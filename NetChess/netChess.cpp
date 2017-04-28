#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include "bridge.h"
#include "util.cpp"

using namespace std;

const int SCREEN_WIDTH = 1216;
const int SCREEN_HEIGHT = 896;
const int SCREEN_BPP = 32;

//Our connection to the server
Socket s_socket;
SocketSet socketSet;

//The surfaces
SDL_Surface *board = NULL;
SDL_Surface *pieceSheet1 = NULL; //Player 1
SDL_Surface *pieceSheet2 = NULL; //Player 2
SDL_Surface *pieceSheet3 = NULL; //Player 3
SDL_Surface *pieceSheet4 = NULL; //Player 4
SDL_Surface *graveSheet = NULL; //Gravestones
SDL_Surface *ghostSheet = NULL;
SDL_Surface *highlight = NULL;
SDL_Surface *screen = NULL;

//Text input
SDL_Surface *text = NULL;
SDL_Surface *sideBar = NULL;
SDL_Surface *textBack = NULL;

//The event structure
SDL_Event event;

SDL_Rect clips[48];

//Our "held" piece
Piece* selected = NULL;

//Rightclicking for faction specials
bool click_mode = false;
int click_count = 0;
int click_cap = 0;
vector<coord> clicked_spots;

//All of the game board pieces
vector<Piece*> pieces;

int player_num; //Our player num relevent to the current game
int player_turn = 1;
bool game_start = false;
bool alive = true; //Am i currently alive?

//Chat Variables
StringInput chat;
TTF_Font *font = NULL;
SDL_Color textColor = {0, 0, 0};
vector<string> history;

//Our chess overhead object
Chess* c = new Chess();

//Holds all places our valid moves can go
vector<coord> spots;

//variables used in HOLD call
Piece ghostPiece = Piece(-1,-64,-64);

//array to store locations for lastMove highlighting
vector<coord> lastMove;

//Necro variables
Piece* bitten = NULL;
int bitten_turn = -1;

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
  //Temp rectangle to hold the offset
  SDL_Rect offset;

  //Get the offset
  offset.x = x;
  offset.y = y;

  //blit the surface
  SDL_BlitSurface( source, clip, destination, &offset );
}

void StringInput::show_centered()
{
  if(text != NULL)
  {
    apply_surface(896, SCREEN_HEIGHT - text->h, text, screen);
  }
}

void Piece::setClip(int x)
{
  clip = &clips[x];
  clip_num = x;
}

void Piece::handle_events()
{
  int x = 0, y = 0;

  //If were clicked on
  if(event.type == SDL_MOUSEBUTTONDOWN)
  {
    x = event.button.x;
    y = event.button.y;

    if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
    {
      if(player_num == owner){
	if(selected == NULL){
	  if(event.button.button == SDL_BUTTON_LEFT)
	  {
	    this->setClip(this->getClip()+6);
	    selected = this;
	    cerr << "Selected:" << selected->debug_name << " : " << selected->getNum() << endl;
	    captureMap.clear();
	    spots = validSpots(c);
	    cerr << "Capturable spots:" << captureMap.size() << endl;
	    for(auto it : captureMap)
	      cerr << it.first.x << "," << it.first.y << " => " << it.second << '\n';

	  }//If left click
	  else if(event.button.button == SDL_BUTTON_RIGHT)
	  {
	    if(player_num != player_turn)
	      return;
	    
	    if(this->clicks == 0)
	      return;

	    click_cap = this->clicks;
	    click_count = 0;
	    click_mode = true;
	    selected = this;
	    cerr << "[DEBUG] Entered Altclick mode for piece:" << click_cap << ":" << this->debug_name << endl;

	  }//if right click
	}//if its a piece we own
      }//if theres no piece already selected
    }//If we clicked on this actual piece
  }
}

void Piece::show()
{
  apply_surface(box.x, box.y, sheet, screen, clip);
}

void Piece::setTeam(int x)
{
  if(x == -1)
  {
    sheet = ghostSheet;
  }
  else if(x == 0){
    sheet = pieceSheet1;
    owner = 1;
  }
  else if(x == 1){  
    sheet = pieceSheet2;
    owner = 2;
  }
  else if(x == 2){  
    sheet = pieceSheet3;
    owner = 3;
  }
  else if(x == 3){  
    sheet = pieceSheet4;
    owner = 4;
  }
  else if(x == 4){ //Dead players
    sheet = graveSheet;
    owner = -1;
  }
}

SDL_Surface *load_image( std::string filename )
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;

  //Load image
  loadedImage = IMG_Load( filename.c_str() );
  if( loadedImage != NULL )
  {
    //Optimize image
    optimizedImage = SDL_DisplayFormat( loadedImage );
    if(optimizedImage != NULL){
      Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
      SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }

    //Free old image
    SDL_FreeSurface( loadedImage );
  }
  return optimizedImage;
}

bool init()
{
  //Initialize all SDL subsystems
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    return false;
  }

  //Set up the screen
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  if(screen == NULL)
  {
    return false;
  }
  if(TTF_Init() == -1)
  {
    return false;
  }

  SDL_WM_SetCaption("NetChess", NULL);
  util_set_clips(clips);

  return true;
}

bool load_files()
{
  //Load the image
  board = load_image("Graphic_Assets/fourPlayerBoard64.png");
  //pieceSheet1 = load_image("Graphic_Assets/basicPieces64.png");
  pieceSheet1 = load_image("Graphic_Assets/Fighter-Pieces.png");
  pieceSheet2 = load_image("Graphic_Assets/basicPieces642.png");
  pieceSheet3 = load_image("Graphic_Assets/basicPieces643.png");
  pieceSheet4 = load_image("Graphic_Assets/basicPieces644-better.png");
  graveSheet = load_image("Graphic_Assets/Graves.png");
  ghostSheet = load_image("Graphic_Assets/ghostPieces64.png");
  highlight = load_image("Graphic_Assets/highlight.png");
  textBack = load_image("Graphic_Assets/textBackground.png");
  font = TTF_OpenFont("Graphic_Assets/edosz.ttf",28);

  if(board == NULL){
    cerr << "No board" << endl;
    return false;
  }

  else if (pieceSheet1 == NULL || pieceSheet2 == NULL || pieceSheet3 == NULL || pieceSheet4 == NULL){
    cerr << "No piece sheets" << endl;
    return false;
  }

  else if(ghostSheet == NULL || graveSheet == NULL){
    cerr << "No ghost/grave sheet" << endl;
    return false;
  }

  else if(highlight == NULL){
    cerr << "No hightlight sheet" << endl;
    return false;
  }

  else if(textBack == NULL){
    cerr << "No textBack sheet" << endl;
    return false;
  }

  else if(font == NULL){  
    cerr << "no font" << endl;
    return false;
  }

  return true;
}

void clean_up()
{
  SDL_FreeSurface(board);
  SDL_FreeSurface(pieceSheet1);
  SDL_FreeSurface(pieceSheet2);
  SDL_FreeSurface(pieceSheet3);
  SDL_FreeSurface(pieceSheet4);
  SDL_FreeSurface(graveSheet);
  SDL_FreeSurface(ghostSheet);
  SDL_FreeSurface(highlight);
  SDL_FreeSurface(textBack);
  SDL_Quit();
}

//Generate starting board
void generatePieces()
{ 
  cerr << "[DEBUG] Beginning board generation" << endl;
  int it = 0;
  int x = -1;
  int y = -1;

  //HOLD stuff
  ghostPiece.setTeam(-1);
  ghostPiece.setClip(0);

  //Player 1 gen 
  for(int j=0;j<2;j++){
    for(int i=0;i<8;i++){
      Piece* newPiece = NULL;
      it++;
      x = i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3;
      y = j*SPRITE_SIZE+BORDER_SIZE;
      int num = it;
      if(j == 1)
      {
	newPiece = new FPawn(x,y,num,'S');
	newPiece->setClip(CLIP_PAWN);
      }
      else{
	if(i==0 || i ==7){  
	  newPiece = new FRook(x,y,num);
	  newPiece->setClip(CLIP_ROOK);
	}
	else if(i==1 || i ==6){ 
	  newPiece = new FKnight(x,y,num);
	  newPiece->setClip(CLIP_KNIGHT);
	}
	else if(i==2 || i ==5){  
	  newPiece = new FBishop(x,y,num);
	  newPiece->setClip(CLIP_BISHOP);
	}
	else if(i==4){  
	  newPiece = new FKing(x,y,num);
	  newPiece->setClip(CLIP_KING);
	}
	else if(i==3){ 
	  newPiece = new FQueen(x,y,num);
	  newPiece->setClip(CLIP_QUEEN);
	}
      }
      newPiece->setTeam(0);
      c->board[newPiece->getSpot().x][newPiece->getSpot().y] = newPiece;
      cerr << newPiece->toString() << endl;
      pieces.push_back(newPiece);
    }
  }
  //Player 2
  for(int j=0;j<2;j++){
    for(int i=0;i<8;i++){
      Piece* newPiece = NULL;
      it++;
      x = i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3;
      y = j*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*12;
      int num = it;
      if(j == 0)
      {
	newPiece = new GPawn(x,y,num,'N');
	newPiece->setClip(CLIP_PAWN);
      }
      else{
	if(i==0 || i ==7){  
	  newPiece = new GRook(x,y,num);
	  newPiece->setClip(CLIP_ROOK);
	}
	else if(i==1 || i ==6){ 
	  newPiece = new GKnight(x,y,num);
	  newPiece->setClip(CLIP_KNIGHT);
	}
	else if(i==2 || i ==5){  
	  newPiece = new GBishop(x,y,num);
	  newPiece->setClip(CLIP_BISHOP);
	}
	else if(i==4){  
	  newPiece = new GKing(x,y,num);
	  newPiece->setClip(CLIP_KING);
	}
	else if(i==3){ 
	  newPiece = new GQueen(x,y,num);
	  newPiece->setClip(CLIP_QUEEN);
	}
      }
      newPiece->setTeam(1);
      c->board[newPiece->getSpot().x][newPiece->getSpot().y] = newPiece;
      cerr << newPiece->toString() << endl;
      pieces.push_back(newPiece);
    }
  }
  //Player 3
  for(int j=0;j<2;j++){
    for(int i=0;i<8;i++){
      Piece* newPiece = NULL;
      it++;
      y = i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3;
      x = j*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*0;
      int num = it;
      if(j == 1)
      {
	newPiece = new NPawn(x,y,num,'E');
	newPiece->setClip(CLIP_PAWN);
      }
      else{
	if(i==0 || i ==7){  
	  newPiece = new NRook(x,y,num);
	  newPiece->setClip(CLIP_ROOK);
	}
	else if(i==1 || i ==6){ 
	  newPiece = new NKnight(x,y,num);
	  newPiece->setClip(CLIP_KNIGHT);
	}
	else if(i==2 || i ==5){  
	  newPiece = new NBishop(x,y,num);
	  newPiece->setClip(CLIP_BISHOP);
	}
	else if(i==4){  
	  newPiece = new NKing(x,y,num);
	  newPiece->setClip(CLIP_KING);
	}
	else if(i==3){ 
	  newPiece = new NQueen(x,y,num);
	  newPiece->setClip(CLIP_QUEEN);
	}
      }
      newPiece->setTeam(2);
      c->board[newPiece->getSpot().x][newPiece->getSpot().y] = newPiece;
      cerr << newPiece->toString() << endl;
      pieces.push_back(newPiece);
    }
  }
  //Player 4
  for(int j=0;j<2;j++){
    for(int i=0;i<8;i++){
      Piece* newPiece = NULL;
      it++;
      y = i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3;
      x = j*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*12;
      int num = it;
      if(j == 0)
      {
	newPiece = new PPawn(x,y,num,'W');
	newPiece->setClip(CLIP_PAWN);
      }
      else{
	if(i==0 || i ==7){  
	  newPiece = new PRook(x,y,num);
	  newPiece->setClip(CLIP_ROOK);
	}
	else if(i==1 || i ==6){ 
	  newPiece = new PKnight(x,y,num);
	  newPiece->setClip(CLIP_KNIGHT);
	}
	else if(i==2 || i ==5){  
	  newPiece = new PBishop(x,y,num);
	  newPiece->setClip(CLIP_BISHOP);
	}
	else if(i==4){  
	  newPiece = new PKing(x,y,num);
	  newPiece->setClip(CLIP_KING);
	}
	else if(i==3){ 
	  newPiece = new PQueen(x,y,num);
	  newPiece->setClip(CLIP_QUEEN);
	}
      }
      newPiece->setTeam(3);
      c->board[newPiece->getSpot().x][newPiece->getSpot().y] = newPiece;
      cerr << newPiece->toString() << endl;
      pieces.push_back(newPiece);
    }
  }

  c->it = 65;
  cerr << "[DEBUG] Done generating boards" << endl;
}

//----------------------
//   Chat functions
//----------------------

void printChat()
{
  for(unsigned int i=0;i<history.size();i++){
    //Get line from history
    string line = history[i];
    //apply like to surface
    sideBar = TTF_RenderText_Solid(font, line.c_str(), textColor);
    //render surface
    int bar = SCREEN_HEIGHT/30;
    apply_surface(896,bar*i, sideBar, screen);
  }

}

//Add a message to the chat history
void addChat(string msg)
{
  history.insert(history.begin(),msg);
  if(history.size() > 28)
  {
    history.pop_back();
  }
}

//----------------------
// Networking functions
//----------------------

//Im so sorry this is in here.
void pieceSpawn(string name, int x, int y, int team)
{
  //PLAC <name> <x> <y> <team>
  char dir; //S-N-E-W | 0-1-2-3
  if(team == 0)
    dir = 'S';
  else if(team == 1)
    dir = 'N';
  else if(team == 2)
    dir = 'E';
  else if(team == 3)
    dir = 'W';
  
  int coordx = x*64;  
  int coordy = y*64;
  Piece* newPiece = NULL;
  if(name == "pawn")
  {
    newPiece = new Pawn(coordx, coordy, c->it, dir);
    newPiece->setClip(CLIP_PAWN);
  }
  else if(name == "rook")
  {
    newPiece = new Rook(coordx, coordy, c->it);
    newPiece->setClip(CLIP_ROOK);
  }
  else if(name == "bishop")
  {
    newPiece = new Bishop(coordx, coordy, c->it);
    newPiece->setClip(CLIP_BISHOP);
  }
  else if(name == "knight")
  {
    newPiece = new Knight(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KNIGHT);
  }
  else if(name == "king")
  {
    newPiece = new King(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KING);
  }
  else if(name == "queen")
  {
    newPiece = new Queen(coordx, coordy, c->it);
    newPiece->setClip(CLIP_QUEEN);
  }
  else if(name == "Fpawn")
  {
    newPiece = new FPawn(coordx, coordy, c->it, dir);
    newPiece->setClip(CLIP_PAWN);
  }
  else if(name == "Frook")
  {
    newPiece = new FRook(coordx, coordy, c->it);
    newPiece->setClip(CLIP_ROOK);
  }
  else if(name == "Fbishop")
  {
    newPiece = new FBishop(coordx, coordy, c->it);
    newPiece->setClip(CLIP_BISHOP);
  }
  else if(name == "Fknight")
  {
    newPiece = new FKnight(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KNIGHT);
  }
  else if(name == "Fking")
  {
    newPiece = new FKing(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KING);
  }
  else if(name == "Fqueen")
  {
    newPiece = new FQueen(coordx, coordy, c->it);
    newPiece->setClip(CLIP_QUEEN);
  }
  else if(name == "Npawn")
  {
    newPiece = new NPawn(coordx, coordy, c->it, dir);
    newPiece->setClip(CLIP_PAWN);
  }
  else if(name == "Nrook")
  {
    newPiece = new NRook(coordx, coordy, c->it);
    newPiece->setClip(CLIP_ROOK);
  }
  else if(name == "Nbishop")
  {
    newPiece = new NBishop(coordx, coordy, c->it);
    newPiece->setClip(CLIP_BISHOP);
  }
  else if(name == "Nknight")
  {
    newPiece = new NKnight(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KNIGHT);
  }
  else if(name == "Nking")
  {
    newPiece = new NKing(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KING);
  }
  else if(name == "Nqueen")
  {
    newPiece = new NQueen(coordx, coordy, c->it);
    newPiece->setClip(CLIP_QUEEN);
  } 
  else if(name == "Ppawn")
  {
    newPiece = new PPawn(coordx, coordy, c->it, dir);
    newPiece->setClip(CLIP_PAWN);
  }
  else if(name == "Prook")
  {
    newPiece = new PRook(coordx, coordy, c->it);
    newPiece->setClip(CLIP_ROOK);
  }
  else if(name == "Pbishop")
  {
    newPiece = new PBishop(coordx, coordy, c->it);
    newPiece->setClip(CLIP_BISHOP);
  }
  else if(name == "Pknight")
  {
    newPiece = new PKnight(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KNIGHT);
  }
  else if(name == "Pking")
  {
    newPiece = new PKing(coordx, coordy, c->it);
    newPiece->setClip(CLIP_KING);
  }
  else if(name == "Pqueen")
  {
    newPiece = new PQueen(coordx, coordy, c->it);
    newPiece->setClip(CLIP_QUEEN);
  }
  else if(name == "")
  {

  }
  else
  {
    cerr << "Invalid spawning parameters:" << name << x << y << team << endl;
    return;
  }
  newPiece->setTeam(team);
  pieces.push_back(newPiece);
  c->board[x][y] = newPiece;
  c->it++;

  cerr << "[DEBUG] Piece spawned:" << name << " " << x << " " << y << " " << team << " " << c->it - 1 << endl;

}

//Connect to the server Whoaaaa!
int connectServer(int argc, char* argv[])
{
  s_socket.open(argv[1], argv[2]);
  s_socket.joinGroup(&socketSet);

  if(!s_socket.isClosed())
    return 0;
  printf("Cannot establish connection to server\n");
  return -1;
}

void killPieces(int team)
{
  for(unsigned int i=0;i<pieces.size();i++)
  {
    if(pieces[i]->getTeam() == team)
    { 
      pieces[i]->setTeam(4);
      pieces[i]->debug_name = "dead";
    }

  }
}

string snip_to_end(string msg, int &cursor)
{
  int last = cursor;
  cursor = msg.find("~",cursor);
  string ret;
  ret = msg.substr(last,cursor-last);
  //cursor++;
  return ret;

}

//Helper function for netProcess
string snip(string msg, int &cursor)
{
  //MOVE 1 100 200
  //     ^-Cursor
  int last = cursor;
  cursor = msg.find(" ",cursor);
  string ret;
  if((unsigned)cursor != string::npos)
    ret = msg.substr(last, cursor-last);
  else
    ret = msg.substr(last,msg.length()-last-1);
  cursor++;
  return ret;
}

void fullRotation();

//Processes messages from the server, necessary for game to work
void netProcess(string msg)
{
  bool display = true;
  stringstream ss;
  int index;
  index = msg.find(" ");
  string cmd = msg.substr(0,index);
  index++;

  if(cmd == "STRT")//STRT - Game start
  {
    game_start = true;
    ss.str("");
    ss << "NetChess - " << player_num << " - Started";
    SDL_WM_SetCaption(ss.str().c_str(), NULL);
    cerr << "[GAME START] Player turn:" << player_turn << endl;
    return;
  }

  if(cmd == "MOVE")//MOVE <id> <x> <y>
  {
    string num = snip(msg,index);
    string s_x = snip(msg,index);
    string s_y = snip(msg,index);
    int i_num = atoi(num.c_str());

    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == i_num){
	//Make old space empty
	lastMove.push_back(pieces[i]->getSpot());
	c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y] = NULL;
	pieces[i]->setPos(atoi(s_x.c_str()), atoi(s_y.c_str()));
	//Make new space filled with piece
	c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y] = pieces[i];
	lastMove.push_back(pieces[i]->getSpot());
	break;
      }
    }
    //Remove Ghost image
    ghostPiece.setPos(-64,-64);


  }//If- MOVE
  else if(cmd == "PLAC")//PLAC <piece> <piece id> <x> <y> <owner>
  {
    string name = snip(msg,index);
    string s_x = snip(msg,index);
    string s_y = snip(msg,index);
    string s_team = snip(msg,index);

    int x = atoi(s_x.c_str());
    int y = atoi(s_y.c_str());
    int team = atoi(s_team.c_str());

    pieceSpawn(name, x, y, team);

  }//If- PLAC
  else if(cmd == "REMV")//REMV <piece num>
  {
    int number;

    string s_num = snip(msg,index);
    number = atoi(s_num.c_str());

    //Find and remove piece
    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == number){
	//Need to perform a strange check on c->board bc the movement commands come in first
	//If our removed piece still exists on the board, make its board spot NULL
	stringstream ss;
	ss.str("DEFAULT");
	if(c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y]->getNum() == pieces[i]->getNum())
	  c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y] = NULL;
	if(pieces[i]->debug_name.find("king") != string::npos){
	  ss.str("");
	  ss << "DEAD " << pieces[i]->getTeam() << " ~";
	}
	pieces[i] = pieces[pieces.size()-1];
	pieces.pop_back();
	if(ss.str() != "DEFAULT")
	  netProcess(ss.str());
	break;
      }
    }
  }//If- REMV
  else if(cmd == "CAPT")//CAPT <piece id> <piece id> 
  {
    string attack = snip(msg,index);
    string defend = snip(msg,index);
    int a_index, d_index;

    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == atoi(attack.c_str()))
	a_index = i;
      if(pieces[i]->getNum() == atoi(defend.c_str()))
	d_index = i;
    }
    //Remove piece 2*
    coord loc = pieces[d_index]->getPos();

    pieces[d_index] = pieces[pieces.size()-1];
    pieces.pop_back();

    //Move piece 1
    //Update game board
    lastMove.push_back(pieces[a_index]->getSpot());
    c->board[pieces[a_index]->getSpot().x][pieces[a_index]->getSpot().y] = NULL;
    pieces[a_index]->setPos(loc.x, loc.y);
    c->board[pieces[a_index]->getSpot().x][pieces[a_index]->getSpot().y] = pieces[a_index];
    lastMove.push_back(pieces[a_index]->getSpot());

    //Level up the piece
    pieces[a_index]->levelUp();

    //Remove ghost image
    ghostPiece.setPos(-64,-64);


  }//If- CAPT
  else if(cmd == "REDY")//REDY <playernum>   
  {
    string num = snip(msg,index);
    player_num = atoi(num.c_str());
    ss.str("");
    ss << "NetChess - " << player_num << " - Waiting for players...";
    SDL_WM_SetCaption(ss.str().c_str(), NULL);

  }//If- REDY
  else if(cmd == "HOLD")//HOLD <clip> <x> <y>
  {
    string s_clip = snip(msg,index);
    string s_x = snip(msg,index);
    string s_y = snip(msg,index);
    int i_clip = atoi(s_clip.c_str());
    int i_x = atoi(s_x.c_str());
    int i_y = atoi(s_y.c_str());

    ghostPiece.setClip(i_clip-6);
    ghostPiece.setPos(i_x,i_y);

    display = false;

  }//If- HOLD
  else if(cmd == "GMSG")//GMSG <player> <msg>
  {
    string s_player = snip(msg,index);
    string player_message = snip_to_end(msg,index);
    ss.str("");
    ss << s_player << " @ " << player_message;
    addChat(ss.str());

  }//If- GMSG
  else if(cmd == "TURN")//TURN <Player num>
  {
    string s_num = snip(msg,index);
    int num = atoi(s_num.c_str());
    player_turn = num;
    cerr << "[TURN] It is now the turn of player:" << player_turn << endl;
    cerr << "Bite turn:" << bitten_turn << endl;
    if(bitten_turn  == player_turn)
      fullRotation();
  }//If- TURN
  else if(cmd == "LVUP")//LVUP <piece num>
  {
    string s_num = snip(msg,index);
    int num = atoi(s_num.c_str());
    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == num)
      {
	pieces[i]->levelUp();
	c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y]->levelUp();
	break;
      }
    }
  }//If- LVUP
  else if(cmd == "ROCK")//ROCK <piece num>
  {
    string s_num = snip(msg,index);
    int num = atoi(s_num.c_str());
    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == num)
      {
	pieces[i]->Rock();
	break;
      }
    }
  }//If- ROCK
  else if(cmd == "BITE")//BITE <piece num>
  {
    string s_num = snip(msg,index);
    int num = atoi(s_num.c_str());
    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == num)
      {
	bitten = pieces[i];
	bitten_turn = player_turn;
	break;
      }
    }
  }//If- BITE
  else if(cmd == "CLIP")//CLIP <piece num> <clip num>
  {
    string s_num = snip(msg,index);
    string s_clip = snip(msg,index);
    int num = atoi(s_num.c_str());
    int clip = atoi(s_clip.c_str());
    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i]->getNum() == num)
      {
	pieces[i]->setClip(clip);
	break;
      }
      lastMove.clear();
    }
  }//If- CLIP
  else if(cmd == "DEAD")//CLIP <player num>
  {
    string s_num = snip(msg,index);
    int num = atoi(s_num.c_str());
    cout << "Player:" << num << " has died" << endl;
    if(s_num == "1"){
      killPieces(1); 
    }
    else if(s_num == "2"){
      killPieces(2); 
    }
    else if(s_num == "3"){
      killPieces(3); 
    }
    else if(s_num == "4"){
      killPieces(4); 
    }
    if(num == player_num)
    {
      cout << "YOU LOSE" << endl;
      stringstream ss;
      ss.str("");
      ss << "NetChess - " << player_num << " - You Are Dead";
      SDL_WM_SetCaption(ss.str().c_str(), NULL);
      alive = false;
    }
  }//If- DEAD
  else if(cmd == "WINN")//WINN <player num>
  {
    string s_num = snip(msg,index);
    int num = atoi(s_num.c_str());
    if(player_num == num)
    {
      cout << "You win!" << endl;
      //Win and stuff
    }
    else
    {
      cout << "you lose!" << endl;
      //Lose and stuff
    }

  }//If- WINN 
  else
  {
    cerr << "Unknown command received:" << msg << endl;
    return;
  }
  string end = msg.substr(index,1);
  index += 1;
  if(end != "~"){
    cerr << "[ERROR] corrupted message received:" << msg << endl;
    cerr << "[ERROR] Ending:" << end << endl;
  }

  //Debug printing
  if(display)
    cerr << "[DEBUG] Message Received:" << msg << " | " << msg.length() << endl;


  if(msg.size() > (unsigned)index)//If message is greater than ending char ~
  {
    netProcess(msg.substr(index,msg.size()-index));
  }

}

//currently used only with necro pawn
void fullRotation()
{
  //XXX
  if(bitten != NULL){
    stringstream ss;
    ss << "REMV " << bitten->getNum() << " ~";
    ss << "PLAC Npawn " << bitten->getSpot().x << " " << bitten->getSpot().y << " " << bitten_turn-1 << " ~";
    netProcess(ss.str());
    bitten = NULL;
    bitten_turn = -1;
  }
}



// ------------------------
// Drawing Helper Functions
// ------------------------

void drawAura(coord spot, string name)
{
  if(name == "Nrook"){

    if(c->board[spot.x][spot.y+1] == NULL and c->isValid(spot.x,spot.y+1))
      apply_surface((spot.x)*64, (spot.y+1)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x][spot.y-1] == NULL and c->isValid(spot.x,spot.y-1))
      apply_surface((spot.x)*64, (spot.y-1)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x+1][spot.y] == NULL and c->isValid(spot.x+1,spot.y))
      apply_surface((spot.x+1)*64, (spot.y)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x+1][spot.y+1] == NULL and c->isValid(spot.x+1,spot.y+1))
      apply_surface((spot.x+1)*64, (spot.y+1)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x+1][spot.y-1] == NULL and c->isValid(spot.x+1,spot.y-1))
      apply_surface((spot.x+1)*64, (spot.y-1)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x-1][spot.y] == NULL and c->isValid(spot.x-1,spot.y))
      apply_surface((spot.x-1)*64, (spot.y)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x-1][spot.y+1] == NULL and c->isValid(spot.x-1,spot.y+1))
      apply_surface((spot.x-1)*64, (spot.y+1)*64, pieceSheet3, screen, &clips[25]);
    if(c->board[spot.x-1][spot.y-1] == NULL and c->isValid(spot.x-1,spot.y-1))
      apply_surface((spot.x-1)*64, (spot.y-1)*64, pieceSheet3, screen, &clips[25]);
  }
  else if (name == "Bitten")
  {
    apply_surface((spot.x)*64, (spot.y)*64, pieceSheet3, screen, &clips    [24]);

  }
} 


// -------------------
// Main Game Functions
// -------------------

int main ( int argc, char* argv[] )
{
  bool quit = false;
  bool chat_mode = false;
  int x,y;

  // Error check
  if (argc < 3 || argc >= 4)
  {
    cerr << "Please retry and enter the ip address"
      << " and a port number." << endl
      << "Example: Frodo 8000" << endl
      << "Shutting Down." << endl;
    return 1;
  }

  //Attempt connection to server. s_socket will be connection socket.
  if(connectServer(argc, argv) == -1)
    return 1;

  //run initialiation and asset loading
  if(init() == false)
    return 1;
  if(load_files() == false)
    return 1;
  generatePieces();

  //// --------------
  //// MAIN GAME LOOP
  //// --------------
  //While the user hasn't quit
  while(quit == false)
  {

    //// ----------
    //// SDL EVENTS
    //// ----------
    //While theres an event to handle
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
	quit = true;
      }

      if(!alive)
	continue;
      
      Uint8 *keystates = SDL_GetKeyState(NULL);
      //This wont let us do anything until the game starts
      if(game_start){ 
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if(event.button.button == SDL_BUTTON_RIGHT && click_mode)
	  {//Elegant exit for alt-click mode
	    selected = NULL;
	    clicked_spots.clear();
	    click_mode = false;
	    cerr << "[DEBUG] Click mode exited" << endl;
	    continue;
	  }
	  else if(click_mode)//If we are clicking for an ability
	  {
	    x = event.button.x - event.button.x%SPRITE_SIZE;
	    y = event.button.y - event.button.y%SPRITE_SIZE;
	    coord newCoord;
	    newCoord.x = x;
	    newCoord.y = y;

	    clicked_spots.push_back(newCoord);
	    click_count++;

	    if(click_count == click_cap){
	      click_cap = 0;
	      click_count = 0;
	      click_mode = false;

	      string result = selected->processClicks(clicked_spots, c);
	      selected = NULL;
	      clicked_spots.clear();

	      if(result == "ERROR"){
		cerr << "[ERROR] ERROR return, something was clicked incorrectly" << endl;
		continue;
	      }
	      if(result == "DEFAULT"){
		cerr << "[DEBUG] DEFAULT return value" << endl;
		continue;
	      }

	      if(player_num == player_turn)
		s_socket.writeString(result);
	      continue;
	    }
	  }
	  else if(selected != NULL){//If we are trying to move a piece
	    bool failure = false; //set to true if the move is invalid

	    x = event.button.x;
	    y = event.button.y;
	    //Snap location to grid
	    x = x - x%SPRITE_SIZE;
	    y = y - y%SPRITE_SIZE;

	    cerr << "Clicked Spot:" << x << "," << y << " | " << x/64 << "," << y/64 << endl;
	    //Send command
	    stringstream ss;
	    ss.str("");

	    //CAPT Check
	    //Check if space is already occupied
	    bool capture = false;
	    for(unsigned int i=0;i<pieces.size();i++){
	      if(pieces[i]->getPos().x == x && pieces[i]->getPos().y == y){//If mouse spot is occupied
		//If we find our own selected piece, ignore it	
		if(pieces[i]->getSpot().x == selected->getSpot().x && 
		    pieces[i]->getSpot().y == selected->getSpot().y){
		  failure = true;
		  break;
		}
		cerr << "[DEBUG] Fetching command from spot:" << pieces[i]->getSpot().x << "," << pieces[i]->getSpot().y << endl;
		coord help = { x/64, y/64 };
		cerr << "[DEBUG] Command:" << selected->getCaptCmd(help) << endl;
		ss.str(selected->getCaptCmd(pieces[i]->getSpot()));
		//check if the piece is allowed to be captured at all (For the sake of golems and such)
		//IsCapturable returns true if its a good case, we dont want failure to be true if its a good case
		string capicing = "DEFAULT";

		failure = !(c->isCapturable(selected->getSpot(), pieces[i]->getSpot(), capicing));

		//If captured unit has additional effects (See Necro)
		if(capicing != "DEFAULT")
		{  
		  cerr << "[DEBUG] Capicing returned not default:" << capicing << endl;
		  ss.str(ss.str() + capicing);
		}

		capture = true;
		break;
	      }
	    }
	    //MOVE check
	    if(!capture)
	    {  
	      ss << "MOVE " << selected->getNum() << " " << x << " " << y << " ~";
	    }

	    //[Engine] Translate to grid coords
	    coord spot;
	    spot.x = x / 64;
	    spot.y = y / 64;

	    //[Engine] Perform check 
	    //Acquire valid spots
	    bool valid = false;
	    for(unsigned int i=0;i<spots.size();i++){//check if our spot is valid
	      //cerr << "(" << spots[i].x << "," << spots[i].y << ")" << endl;
	      if(spots[i].x == spot.x && spots[i].y == spot.y)
		valid = true;
	    }

	    //Ghost and highlight cleanup
	    selected->setClip(selected->getClip()-6);
	    ghostPiece.setPos(-64,-64);
	    spots.clear();

	    if(failure || !valid){//If we try to capture a friendly pieceor try to click on an invalid spot
	      selected = NULL;
	      continue;
	    }

	    //FINALLY- We know our move is valid, perform faction checks

	    if(player_num == player_turn){ 
	      string icing;//Icing on the MOVE/CAPT cake
	      cerr << "[DEBUG] Calling Piece movement func" << endl;
	      icing = selected->Move(spot);
	      if(icing != "DEFAULT")
		ss.str(ss.str() + icing);
	    }

	    selected = NULL;
	    lastMove.clear();


	    if(player_num == player_turn){
	      cerr << "[DEBUG] Sending message:" << ss.str() << endl;
	      s_socket.writeString(ss.str());
	    }

	    continue;
	  }//If- Selected != null
	}//If- event type = mouseleft
	//If enter key is pressed, enter chat mode
	else if(keystates[SDLK_RETURN])
	{
	  cerr << "Enter registered- current chat:" << chat.getText() << endl;
	  if(!chat_mode)
	  {  
	    chat_mode = true;
	    chat.addChar('_');
	  }
	  else
	  {  
	    chat_mode = false;
	    if(chat.getText() != "" && chat.getText() != "_"){
	      stringstream ss;
	      ss.str("");
	      ss << "GMSG " << player_num << " " << chat.getText() << " ~";
	      //socketSet.wait(0);
	      s_socket.writeString(ss.str());
	    }
	    chat.reset();
	  }
	}
	//HOLD MOUSE MOTION
	else if(event.type == SDL_MOUSEMOTION && selected != NULL && !click_mode)
	{
	  int x = event.motion.x-32;
	  int y = event.motion.y-32;

	  stringstream ss;
	  ss.str("");
	  ss << "HOLD " << selected->getClip() << " " << x << " " << y << " ~";
	  //socketSet.wait(0);
	  if(player_num == player_turn)
	    s_socket.writeString(ss.str());

	}

	//Perform local piece event handling (get clicked on)
	for(unsigned int i=0;i<pieces.size();i++)
	  pieces[i]->handle_events();

	//If chatmode is on, do chat things (get chatted in)
	if(chat_mode){
	  chat.handle_input(event,font,textColor);
	}

      }//If- game start


    }//While- SDL_PollEvent

    //// ------------------
    //// NETWORK CONNECTION
    //// ------------------
    if(s_socket.isClosed()){
      printf("Lost connection with server\n");
      return 1;
    }

    socketSet.wait(0);
    if(s_socket.hasEvent())
    {
      //Do appropriate things with server message
      string msg = "DEFAULT";
      int bytes = s_socket.readString(msg,256);
      if(bytes == 256){
	cerr << "[ERROR] Read too large (> 256)" << endl;
      }

      netProcess(msg);
    }//if- socket has event

    //// -------
    //// DRAWING
    //// -------
    //Make window white instead of black - obselete
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

    //Apply the board to the screen
    apply_surface(0, 0, board, screen, NULL);

    //Next apply last move highlight
    for(unsigned int i=lastMove.size()-2;i<lastMove.size();i++){
      apply_surface(lastMove[i].x*64, lastMove[i].y*64, highlight, screen, &clips[2]);
    }

    //Show() pieces
    for(unsigned int i=0;i<pieces.size();i++)
    {
      //Draw auras first
      if(pieces[i]->debug_name == "Nrook")
	if(pieces[i]->isLevel())
	  drawAura(pieces[i]->getSpot(), "Nrook");
      if(bitten != NULL)
	drawAura(bitten->getSpot(), "Bitten");

      pieces[i]->show();
    }

    ghostPiece.show();

    apply_surface(896, 0, textBack, screen, NULL);
    //Show the chat input
    chat.setSurface(TTF_RenderText_Solid(font, chat.getText().c_str(), textColor));
    chat.show_centered();

    //print side chat bar
    printChat();

    //Show the highlights
    for(unsigned int i=0;i<spots.size();i++){//Show blue spots
      apply_surface(spots[i].x*64, spots[i].y*64, highlight, screen, &clips[0]);
      for(unsigned int j=0; j<pieces.size(); j++){//Show red spots
	if((pieces[j]->getSpot().x == spots[i].x) and (pieces[j]->getSpot().y == spots[i].y))
	  apply_surface(spots[i].x*64, spots[i].y*64, highlight, screen, &clips[1]);
      }
    }

    //Show highlight for click mode
    if(click_mode){
      int m_x, m_y;
      m_x = event.motion.x - event.motion.x%SPRITE_SIZE;
      m_y = event.motion.y - event.motion.y%SPRITE_SIZE;
      apply_surface(m_x, m_y, highlight, screen, &clips[3]);
    }

    //Update screen
    if(SDL_Flip( screen ) == -1){
      return 1;
    }

  }//While- Quit == false
  //Free space and quit SDL
  clean_up();

  return 0;
}
