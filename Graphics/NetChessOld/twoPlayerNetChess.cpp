#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "bridge.h"

using namespace std;


const int SCREEN_WIDTH = 896;
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

//Our connection to the server
Socket s_socket;
SocketSet socketSet;

//The surfaces
SDL_Surface *board = NULL;
SDL_Surface *pieceSheet1 = NULL; //Player1s sprite sheet
SDL_Surface *pieceSheet2 = NULL; //Player 2
SDL_Surface *ghostSheet = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

SDL_Rect clips[12];

//Our "held" piece
Piece* selected = NULL;
vector<Piece> pieces;
int player_num; //Our player num relevent to the current game
bool game_start = false;

//variables used in HOLD call
Piece ghostPiece = Piece(-1,-64,-64);
int orig_x, orig_y;

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
	    orig_x = selected->getPos().x;
	    orig_y = selected->getPos().y;
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
}

void set_clips()
{
  clips[CLIP_PAWN].x = 0;
  clips[CLIP_PAWN].y = 0;
  clips[CLIP_PAWN].w = SPRITE_SIZE;
  clips[CLIP_PAWN].h = SPRITE_SIZE;

  clips[CLIP_PAWN_SELECT].x = 0;
  clips[CLIP_PAWN_SELECT].y = SPRITE_SIZE;
  clips[CLIP_PAWN_SELECT].w = SPRITE_SIZE;
  clips[CLIP_PAWN_SELECT].h = SPRITE_SIZE;

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

  SDL_WM_SetCaption("NetChess", NULL);

  return true;
}

bool load_files()
{
  //Load the image
  board = load_image("twoPlayerBoardTest.png");
  pieceSheet1 = load_image("basicPieces64.png");
  pieceSheet2 = load_image("basicPieces642.png");
  ghostSheet = load_image("ghostPieces64.png");

  if(board == NULL)
  {
    return false;
  }
  else if (pieceSheet1 == NULL || pieceSheet2 == NULL) 
  {
    return false;
  }
  else if(ghostSheet == NULL)
    return false;

  return true;
}

void clean_up()
{
  SDL_FreeSurface(board);
  SDL_FreeSurface(pieceSheet1);
  SDL_FreeSurface(pieceSheet2);
  SDL_FreeSurface(ghostSheet);

  SDL_Quit();
}

//Generate starting board
void generatePieces()
{ 
   int it = 0;

   //HOLD stuff
   ghostPiece.setTeam(-1);
   ghostPiece.setClip(0);

   //Player 1 gen 
   for(int j=0;j<2;j++){
    for(int i=0;i<8;i++){
      Piece newPiece = Piece(i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3, j*SPRITE_SIZE+(SPRITE_SIZE*3+BORDER_SIZE), it); 
      it++;
      newPiece.setTeam(0);
      if(j == 1)
	newPiece.setClip(CLIP_PAWN);
      else{
	if(i==0 || i ==7)
	  newPiece.setClip(CLIP_ROOK);
	if(i==1 || i ==6)
	  newPiece.setClip(CLIP_KNIGHT);
	if(i==2 || i ==5)
	  newPiece.setClip(CLIP_BISHOP);
	if(i==4)
	  newPiece.setClip(CLIP_KING);
	if(i==3)
	  newPiece.setClip(CLIP_QUEEN);
      }
      pieces.push_back(newPiece);
    }
  }
  //Player 2 gen
  for(int j=2;j>0;j--){
    for(int i=0;i<8;i++){
      Piece newPiece = Piece(i*SPRITE_SIZE+BORDER_SIZE+SPRITE_SIZE*3, j*SPRITE_SIZE+(SPRITE_SIZE*8 + BORDER_SIZE), it); 
      it++;
      newPiece.setTeam(1);
      if(j == 1)
	newPiece.setClip(CLIP_PAWN);
      else{
	if(i==0 || i ==7)
	  newPiece.setClip(CLIP_ROOK);
	if(i==1 || i ==6)
	  newPiece.setClip(CLIP_KNIGHT);
	if(i==2 || i ==5)
	  newPiece.setClip(CLIP_BISHOP);
	if(i==4)
	  newPiece.setClip(CLIP_KING);
	if(i==3)
	  newPiece.setClip(CLIP_QUEEN);
      }
      pieces.push_back(newPiece);
    }
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

//Helper function for netProcess
string snip(string msg, int &cursor)
{
  //MOVE 1 100 200
  //     ^-Cursor
  int last = cursor;
  cursor = msg.find(" ",cursor);
  string ret;
  if(cursor != string::npos)
    ret = msg.substr(last, cursor-last);
  else
    ret = msg.substr(last,msg.length()-last);
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
      if(pieces[i].getNum() == i_num){
	pieces[i].setPos(atoi(s_x.c_str()), atoi(s_y.c_str()));
	break;
      }
    }
    //Remove Ghost image
    ghostPiece.setPos(-64,-64);

  }
  //If- MOVE
  else if(cmd == "PLAC")//PLAC <piece> <piece id> <x> <y> <owner>
  {
    //EMPTY
  }
  //If- PLAC
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
      Piece dummy = pieces[i];
      px = dummy.getSpot().x;
      py = dummy.getSpot().y;
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
      if(pieces[i].getNum() == atoi(attack.c_str()))
	a_index = i;
      if(pieces[i].getNum() == atoi(defend.c_str()))
	d_index = i;
    }
    //Remove piece 2*
    coord loc = pieces[d_index].getPos();

    pieces[d_index] = pieces[pieces.size()-1];
    pieces.pop_back();

    //Move piece 1
    pieces[a_index].setPos(loc.x, loc.y);

    //Remove ghost image
    ghostPiece.setPos(-64,-64);

  }//If- CAPT
  else if(cmd == "REDY")//REDY <playernum>   
  {
    last = index;
    index = msg.find(" ",index);
    string num = msg.substr(last,index-last);
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
  else
  {
    cerr << "Unknown command received:" << msg << endl;
  }
}

int main ( int argc, char* argv[] )
{
  bool quit = false;
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

	    //XXX: [Engine] Translate to grid coords
        //ValidMoves(selected->getSpot());
	    //XXX: [Engine] Perform check 
	    //If valid continue
	    //If invalid ignore the command

	    //XXX: [Engine] Send MOVE/CAPT command to server

	    //Set sprite back to normal
	    selected->setClip(selected->getClip()-6);

	    //Send command
	    stringstream ss;
	    ss.str("");

	    //CAPT Check
	    //Check if space is already occupied
	    bool capture = false;
	    for(unsigned int i=0;i<pieces.size();i++){
	      if(pieces[i].getPos().x == x && pieces[i].getPos().y == y){
		//It is! lets kill it!
		ss << "CAPT " << selected->getNum() << " " << pieces[i].getNum();
	     
	        //If we find our own selected piece, ignore it	
		if(pieces[i].getSpot().x == selected->getSpot().x && 
		    pieces[i].getSpot().y == selected->getSpot().y){
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
	      ss << "MOVE " << selected->getNum() << " " << x << " " << y;
	    }

	    selected = NULL;
	    
	    //If the move was not valid, dont send anything
	    
	    //Hide ghost image after moving
	    ghostPiece.setPos(-64,-64);
	    if(failure)
	      continue;

	    s_socket.writeString(ss.str());

	    continue;
	  }//If- Selected != null
	}//If- event type = mouseleft
	else if(event.type == SDL_MOUSEMOTION && selected != NULL)
	{
	  stringstream ss;
	  ss.str("");
	  ss << "HOLD " << selected->getClip() << " " << event.motion.x-32 << " " << event.motion.y-32;
	  socketSet.wait(0);
	  s_socket.writeString(ss.str());
	  
	}
	
	//Perform local piece event handling
	for(unsigned int i=0;i<pieces.size();i++)
	  pieces[i].handle_events();

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
      int bytes = s_socket.readString(msg,64);
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
      pieces[i].show();

    ghostPiece.show();

    //Update screen
    if(SDL_Flip( screen ) == -1){
      return 1;
    }

  }//While- Quit == false
  //Free space and quit SDL
  clean_up();

  return 0;
}
