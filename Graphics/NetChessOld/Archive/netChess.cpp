#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include "bridge.h"

using namespace std;


const int SCREEN_WIDTH = 1216;
const int SCREEN_HEIGHT = 896;
const int SCREEN_BPP = 32;

int SPRITE_SIZE = 64;
int BORDER_SIZE = 0;

//Slices for our sprite sheet
int CLIP_PAWN = 0;
int CLIP_ROOK = 1;
int CLIP_BISHOP = 2;
int CLIP_KNIGHT = 3;
int CLIP_QUEEN = 4;
int CLIP_KING = 5;

int CLIP_PAWN_SELECT = 6;
int CLIP_ROOK_SELECT = 7;
int CLIP_BISHOP_SELECT = 8;
int CLIP_KNIGHT_SELECT = 9;
int CLIP_QUEEN_SELECT = 10;
int CLIP_KING_SELECT = 11;

int CLIP_PAWN_UPGRADE = 12;
int CLIP_ROOK_UPGRAD = 13;
int CLIP_BISHOP_UPGRAD = 14;
int CLIP_KNIGHT_UPGRAD = 15;
int CLIP_QUEEN_UPGRAD = 16;
int CLIP_KING_UPGRAD = 17;

int CLIP_PAWN_UPGRADE_SELECT = 18;
int CLIP_ROOK_UPGRADE_SELECT = 19;
int CLIP_BISHOP_UPGRADE_SELECT = 20;
int CLIP_KNIGHT_UPGRADE_SELECT = 21;
int CLIP_QUEEN_UPGRADE_SELECT = 22;
int CLIP_KING_UPGRADE_SELECT = 23;

//Our connection to the server
Socket s_socket;
SocketSet socketSet;

//The surfaces
SDL_Surface *board = NULL;
SDL_Surface *pieceSheet1 = NULL; //Player1s sprite sheet
SDL_Surface *pieceSheet2 = NULL; //Player 2
SDL_Surface *pieceSheet3 = NULL; //Player 3
SDL_Surface *pieceSheet4 = NULL; //Player 4
SDL_Surface *ghostSheet = NULL;
SDL_Surface *highlight = NULL;
SDL_Surface *screen = NULL;

//Text input
SDL_Surface *text = NULL;
//side bar chat
SDL_Surface *sideBar = NULL;
SDL_Surface *textBack = NULL;
//The event structure
SDL_Event event;

SDL_Rect clips[24];

//Our "held" piece
Piece* selected = NULL;

//All of the game board pieces
vector<Piece*> pieces;


int player_num; //Our player num relevent to the current game
bool game_start = false;

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
    if(event.button.button == SDL_BUTTON_LEFT)
    {
      x = event.button.x;
      y = event.button.y;

      if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
      {
	//Make sure its our piece
	if(player_num == owner)
	  if(selected == NULL){
	    this->setClip(this->getClip()+6);
	    selected = this;
	    spots = validSpots(c);
	    cerr << "[DEBUG] Piece clicked on, valid spots:" << endl;
	    for(unsigned int i=0;i<spots.size();i++)
	    {
	      cerr << "(" << spots[i].x << "," << spots[i].y << ")" << endl;
	    }
	  }
      }//if its really us
    }
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
}

void set_clips()
{
  //Clip range for pawn
  clips[CLIP_PAWN].x = 0;
  clips[CLIP_PAWN].y = 0;
  clips[CLIP_PAWN].w = SPRITE_SIZE;
  clips[CLIP_PAWN].h = SPRITE_SIZE;

  clips[CLIP_PAWN_SELECT].x = 0;
  clips[CLIP_PAWN_SELECT].y = SPRITE_SIZE;
  clips[CLIP_PAWN_SELECT].w = SPRITE_SIZE;
  clips[CLIP_PAWN_SELECT].h = SPRITE_SIZE;

  clips[CLIP_PAWN_UPGRADE].x = 0;
  clips[CLIP_PAWN_UPGRADE].y = SPRITE_SIZE*2;
  clips[CLIP_PAWN_UPGRADE].w = SPRITE_SIZE;
  clips[CLIP_PAWN_UPGRADE].h = SPRITE_SIZE;
  
  clips[CLIP_PAWN_UPGRADE_SELECT].x = 0;
  clips[CLIP_PAWN_UPGRADE_SELECT].y = SPRITE_SIZE*3;
  clips[CLIP_PAWN_UPGRADE_SELECT].w = SPRITE_SIZE;
  clips[CLIP_PAWN_UPGRADE_SELECT].h = SPRITE_SIZE;

  //clip range for the rook
  clips[CLIP_ROOK].x = SPRITE_SIZE;
  clips[CLIP_ROOK].y = 0;
  clips[CLIP_ROOK].w = SPRITE_SIZE;
  clips[CLIP_ROOK].h = SPRITE_SIZE;

  clips[CLIP_ROOK_SELECT].x = SPRITE_SIZE;
  clips[CLIP_ROOK_SELECT].y = SPRITE_SIZE;
  clips[CLIP_ROOK_SELECT].w = SPRITE_SIZE;
  clips[CLIP_ROOK_SELECT].h = SPRITE_SIZE;
  
  //clip range for the bishop
  clips[CLIP_BISHOP].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP].y = 0;
  clips[CLIP_BISHOP].w = SPRITE_SIZE;
  clips[CLIP_BISHOP].h = SPRITE_SIZE;

  clips[CLIP_BISHOP_SELECT].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP_SELECT].y = SPRITE_SIZE;
  clips[CLIP_BISHOP_SELECT].w = SPRITE_SIZE;
  clips[CLIP_BISHOP_SELECT].h = SPRITE_SIZE;
  
  //clip range for the knight
  clips[CLIP_KNIGHT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT].y = 0;
  clips[CLIP_KNIGHT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT].h = SPRITE_SIZE;

  clips[CLIP_KNIGHT_SELECT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT_SELECT].y = SPRITE_SIZE;
  clips[CLIP_KNIGHT_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT_SELECT].h = SPRITE_SIZE;

  //clip range for the queen
  clips[CLIP_QUEEN].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN].y = 0;
  clips[CLIP_QUEEN].w = SPRITE_SIZE;
  clips[CLIP_QUEEN].h = SPRITE_SIZE;

  //clip range for the rook
  clips[CLIP_ROOK].x = SPRITE_SIZE;
  clips[CLIP_ROOK].y = 0;
  clips[CLIP_ROOK].w = SPRITE_SIZE;
  clips[CLIP_ROOK].h = SPRITE_SIZE;

  clips[CLIP_ROOK_SELECT].x = SPRITE_SIZE;
  clips[CLIP_ROOK_SELECT].y = SPRITE_SIZE;
  clips[CLIP_ROOK_SELECT].w = SPRITE_SIZE;
  clips[CLIP_ROOK_SELECT].h = SPRITE_SIZE;
  
  //clip range for the bishop
  clips[CLIP_BISHOP].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP].y = 0;
  clips[CLIP_BISHOP].w = SPRITE_SIZE;
  clips[CLIP_BISHOP].h = SPRITE_SIZE;

  clips[CLIP_BISHOP_SELECT].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP_SELECT].y = SPRITE_SIZE;
  clips[CLIP_BISHOP_SELECT].w = SPRITE_SIZE;
  clips[CLIP_BISHOP_SELECT].h = SPRITE_SIZE;
  
  //clip range for the knight
  clips[CLIP_KNIGHT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT].y = 0;
  clips[CLIP_KNIGHT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT].h = SPRITE_SIZE;

  clips[CLIP_KNIGHT_SELECT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT_SELECT].y = SPRITE_SIZE;
  clips[CLIP_KNIGHT_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT_SELECT].h = SPRITE_SIZE;

  //clip range for the queen
  clips[CLIP_QUEEN].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN].y = 0;
  clips[CLIP_QUEEN].w = SPRITE_SIZE;
  clips[CLIP_QUEEN].h = SPRITE_SIZE;

  clips[CLIP_QUEEN_SELECT].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN_SELECT].y = SPRITE_SIZE;
  clips[CLIP_QUEEN_SELECT].w = SPRITE_SIZE;
  clips[CLIP_QUEEN_SELECT].h = SPRITE_SIZE;
  
  //clip range for the king
  clips[CLIP_KING].x = SPRITE_SIZE*5;
  clips[CLIP_KING].y = 0;
  clips[CLIP_KING].w = SPRITE_SIZE;
  clips[CLIP_KING].h = SPRITE_SIZE;
  
  clips[CLIP_KING_SELECT].x = SPRITE_SIZE*5;
  clips[CLIP_KING_SELECT].y = SPRITE_SIZE;
  clips[CLIP_KING_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KING_SELECT].h = SPRITE_SIZE;

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

  return true;
}

bool load_files()
{
  //Load the image
  board = load_image("fourPlayerBoard64.png");
  pieceSheet1 = load_image("basicPieces64.png");
  pieceSheet2 = load_image("basicPieces642.png");
  pieceSheet3 = load_image("basicPieces643.png");
  pieceSheet4 = load_image("basicPieces644.png");
  ghostSheet = load_image("ghostPieces64.png");
  textBack = load_image("textBackground.png");

  highlight = load_image("highlight.png");

  font = TTF_OpenFont("edosz.ttf",28);
  if(font == NULL)
  {  
    cerr << "Fuck me no font" << endl;
    return false;
  }

  if(board == NULL)
  {
    return false;
  }
  else if (pieceSheet1 == NULL || pieceSheet2 == NULL || pieceSheet3 == NULL || pieceSheet4 == NULL)
  {
    return false;
  }
  else if(ghostSheet == NULL)
    return false;

  cerr << "Sheet1:" << pieceSheet1 << endl;
  cerr << "Sheet2:" << pieceSheet2 << endl;
  cerr << "Sheet3:" << pieceSheet3 << endl;
  cerr << "Sheet4:" << pieceSheet4 << endl;
  
  
  return true;
}

void clean_up()
{
  SDL_FreeSurface(board);
  SDL_FreeSurface(pieceSheet1);
  SDL_FreeSurface(pieceSheet2);
  SDL_FreeSurface(pieceSheet3);
  SDL_FreeSurface(pieceSheet4);
  SDL_FreeSurface(ghostSheet);

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
      cerr << "[NEW PIECE GEN]" << endl;
      Piece* newPiece = NULL;;
      it++;
      x = i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3;
      y = j*SPRITE_SIZE+BORDER_SIZE;
      cerr << "Spot X:" << x << " Spot Y:" << y << endl;
      int num = it;
      if(j == 1)
      {
	newPiece = new Pawn(x,y,num,'S');
	newPiece->setClip(CLIP_PAWN);
      }
      else{
	if(i==0 || i ==7){  
	  newPiece = new Rook(x,y,num);
	  newPiece->setClip(CLIP_ROOK);
	}
	else if(i==1 || i ==6){ 
	  newPiece = new Knight(x,y,num);
	  newPiece->setClip(CLIP_KNIGHT);
	}
	else if(i==2 || i ==5){  
	  newPiece = new Bishop(x,y,num);
	  newPiece->setClip(CLIP_BISHOP);
	}
	else if(i==4){  
	  newPiece = new King(x,y,num);
	  newPiece->setClip(CLIP_KING);
	}
	else if(i==3){ 
	  newPiece = new Queen(x,y,num);
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
	 newPiece = new Pawn(x,y,num,'N');
	 newPiece->setClip(CLIP_PAWN);
       }
       else{
	 if(i==0 || i ==7){  
	   newPiece = new Rook(x,y,num);
	   newPiece->setClip(CLIP_ROOK);
	 }
	 else if(i==1 || i ==6){ 
	   newPiece = new Knight(x,y,num);
	   newPiece->setClip(CLIP_KNIGHT);
	 }
	 else if(i==2 || i ==5){  
	   newPiece = new Bishop(x,y,num);
	   newPiece->setClip(CLIP_BISHOP);
	 }
	 else if(i==4){  
	   newPiece = new King(x,y,num);
	   newPiece->setClip(CLIP_KING);
	 }
	 else if(i==3){ 
	   newPiece = new Queen(x,y,num);
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
	 newPiece = new Pawn(x,y,num,'E');
	 newPiece->setClip(CLIP_PAWN);
       }
       else{
	 if(i==0 || i ==7){  
	   newPiece = new Rook(x,y,num);
	   newPiece->setClip(CLIP_ROOK);
	 }
	 else if(i==1 || i ==6){ 
	   newPiece = new Knight(x,y,num);
	   newPiece->setClip(CLIP_KNIGHT);
	 }
	 else if(i==2 || i ==5){  
	   newPiece = new Bishop(x,y,num);
	   newPiece->setClip(CLIP_BISHOP);
	 }
	 else if(i==4){  
	   newPiece = new King(x,y,num);
	   newPiece->setClip(CLIP_KING);
	 }
	 else if(i==3){ 
	   newPiece = new Queen(x,y,num);
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
	 newPiece = new Pawn(x,y,num,'W');
	 newPiece->setClip(CLIP_PAWN);
       }
       else{
	 if(i==0 || i ==7){  
	   newPiece = new Rook(x,y,num);
	   newPiece->setClip(CLIP_ROOK);
	 }
	 else if(i==1 || i ==6){ 
	   newPiece = new Knight(x,y,num);
	   newPiece->setClip(CLIP_KNIGHT);
	 }
	 else if(i==2 || i ==5){  
	   newPiece = new Bishop(x,y,num);
	   newPiece->setClip(CLIP_BISHOP);
	 }
	 else if(i==4){  
	   newPiece = new King(x,y,num);
	   newPiece->setClip(CLIP_KING);
	 }
	 else if(i==3){ 
	   newPiece = new Queen(x,y,num);
	   newPiece->setClip(CLIP_QUEEN);
	 }
       }
       newPiece->setTeam(3);
       c->board[newPiece->getSpot().x][newPiece->getSpot().y] = newPiece;
       cerr << newPiece->toString() << endl;
       pieces.push_back(newPiece);
     }
   }

   cerr << "[DEBUG] Done generating boards" << endl;
}

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

string snip_to_end(string msg, int &cursor)
{
  int last = cursor;
  cursor = msg.find("~",cursor);
  string ret;
  ret = msg.substr(last,cursor-last);
  cursor++;
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

//Processes messages from the server
void netProcess(string msg)
{
  stringstream ss;
  int index, last;
  index = msg.find(" ");
  string cmd = msg.substr(0,index);
  index++;
  
  if(cmd == "STRT")//STRT - Game start
  {
    game_start = true;
    ss.str("");
    ss << "NetChess - " << player_num << " - Started";
    SDL_WM_SetCaption(ss.str().c_str(), NULL);
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
	c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y] = NULL;
	pieces[i]->setPos(atoi(s_x.c_str()), atoi(s_y.c_str()));
	//Make new space filled with piece
	c->board[pieces[i]->getSpot().x][pieces[i]->getSpot().y] = pieces[i];
	break;
      }
    }
    //Remove Ghost image
    ghostPiece.setPos(-64,-64);


  }//If- MOVE
  else if(cmd == "PLAC")//PLAC <piece> <piece id> <x> <y> <owner>
  {

  }//If- PLAC
  else if(cmd == "REMV")//REMV <x> <y>
  {
    int x, y;
    
    string s_x = snip(msg,index);
    string s_y = snip(msg,index);
    x = atoi(s_x.c_str());
    y = atoi(s_y.c_str());

    //Find and remove piece
    for(unsigned int i=0;i<pieces.size();i++){
      int px, py;
      Piece* dummy = pieces[i];
      px = dummy->getSpot().x;
      py = dummy->getSpot().y;
      if(x == px && y == py){
	pieces[i] = pieces[pieces.size()-1];
	pieces.pop_back();
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
    c->board[pieces[a_index]->getSpot().x][pieces[a_index]->getSpot().y] = NULL;
    pieces[a_index]->setPos(loc.x, loc.y);
    c->board[pieces[a_index]->getSpot().x][pieces[a_index]->getSpot().y] = pieces[a_index];
    

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
    
  }//If- HOLD
  else if(cmd == "GMSG")//GMSG <player> <msg>
  {
    string s_player = snip(msg,index);
    string player_message = snip(msg,index);
    ss.str("");
    ss << s_player << " @ " << player_message;
    addChat(ss.str());
    
  }//If- GMSG
  else if(cmd == "STAT")//STAT <code>
  {
    string code = snip(msg,index);
    if(code == "01"){     
      cerr << "Handshake received" << endl;
    }
  }
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
  if(msg.size() > (unsigned)index)//If message is greater than ending char ~
  {
    cerr << "[LONG STRING] Recursing with string:" << msg.substr(index,msg.size()-index) << endl;;
    netProcess(msg.substr(index,msg.size()-index));
  }

}

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
  set_clips();
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
      Uint8 *keystates = SDL_GetKeyState(NULL);
      //This wont let us do anything until the game starts
      if(game_start){ 
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
	  
	  if(selected != NULL){//If we are trying to move a piece
	    bool failure = false; //set to true if the move is invalid
	    
	    x = event.button.x;
	    y = event.button.y;

	    //Snap location to grid
	    x = x - x%SPRITE_SIZE;
	    y = y - y%SPRITE_SIZE;
	    

	    //Send command
	    stringstream ss;
	    ss.str("");

	    //CAPT Check
	    //Check if space is already occupied
	    bool capture = false;
	    for(unsigned int i=0;i<pieces.size();i++){
	      if(pieces[i]->getPos().x == x && pieces[i]->getPos().y == y){
		//It is! lets kill it!
		ss << "CAPT " << selected->getNum() << " " << pieces[i]->getNum() << " ~";
	     
	        //If we find our own selected piece, ignore it	
		if(pieces[i]->getSpot().x == selected->getSpot().x && 
		    pieces[i]->getSpot().y == selected->getSpot().y){
		  failure = true;
		  break;
		}
		capture = true;
		break;
	      }
	    }
	    //MOVE check
	    //Send move command
	    if(!capture)
	    {  
	      ss << "MOVE " << selected->getNum() << " " << x << " " << y << " ~";
	    }

	    //XXX: [Engine] Translate to grid coords
	    coord spot;
	    spot.x = x / 64;
	    spot.y = y / 64;
	    cerr << "Spot:" << spot.x << "," << spot.y << endl;

	    //XXX: [Engine] Perform check 
	    //Acquire valid spots
	    //spots.clear(); 
	    //spots = selected->validSpots(c);
	    bool valid = false;
	    cerr << "size of spots:" << spots.size() << endl;
	    for(unsigned int i=0;i<spots.size();i++){//check if our spot is valid
	      cerr << "(" << spots[i].x << "," << spots[i].y << ")" << endl;
	      if(spots[i].x == spot.x && spots[i].y == spot.y)
		valid = true;
	    }
	    
	    //Ghost and highlight cleanup
	    selected->setClip(selected->getClip()-6);
	    selected = NULL;
	    ghostPiece.setPos(-64,-64);
	    spots.clear();
	    
	    if(failure)//If we try to capture a friendly piece
	      continue;
	    
	    if(!valid)//If we click on an invalid spot
	      continue;

	    s_socket.writeString(ss.str());

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
	else if(event.type == SDL_MOUSEMOTION && selected != NULL)
	{
	  int x = event.motion.x-32;
	  int y = event.motion.y-32;

	  stringstream ss;
	  ss.str("");
	  ss << "HOLD " << selected->getClip() << " " << x << " " << y << " ~";
	  //socketSet.wait(0);
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

      if(event.type == SDL_QUIT)
      {
	quit = true;
      }

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
      cerr << "Message Received:" << msg << " | " << bytes << endl;

      netProcess(msg);
    }//if- socket has event

//// -------
//// DRAWING
//// -------
    //Make window white instead of black - obselete
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

    //Apply the board to the screen
    apply_surface(0, 0, board, screen, NULL);

    //Show() pieces
    for(unsigned int i=0;i<pieces.size();i++)
      pieces[i]->show();

    ghostPiece.show();

    apply_surface(896, 0, textBack, screen, NULL);
    //Show the chat input
    chat.setSurface(TTF_RenderText_Solid(font, chat.getText().c_str(), textColor));
    chat.show_centered();
   
    //print side chat bar
    printChat();

    //Show the highlights
    for(unsigned int i=0;i<spots.size();i++){
      apply_surface(spots[i].x*64, spots[i].y*64, highlight, screen);
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
