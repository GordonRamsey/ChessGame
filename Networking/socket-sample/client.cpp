#include "Socket.h"
#include "SocketSet.h"
#include "Console.h"
#include <curses.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

WINDOW* window;
int width,height;
string msg = "";
Console console;

char grid [10][10];
int player_number;
int turn = 1;

struct Board{
  int origin_y;
  int origin_x;
  char grid [10][10];
  bool alive;
};

Board p1, p2, p3, p4; 
Board boards[4] = {p1,p2,p3,p4};

stringstream ss;
vector<string> history;

void initCurses(){
  window = initscr();
  getmaxyx(window,height,width);
  nodelay(window,true);

  refresh();
}

void shutdownCurses(){
  delwin(window);
  endwin();
  refresh();
}

void drawBoard(string caption, Board player, bool current){
  int y = player.origin_y;
  int x = player.origin_x;
  bool alive = player.alive;

  if(alive)
    attron(A_REVERSE);
  mvwaddstr(window,y,x," 0123456789 ");
  if(alive)
    attroff(A_REVERSE);
  string ch = "A";

  string helpme;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    {
      helpme.push_back(player.grid[i][j]);
    }

  for(int i= 0; i < 10; ++i){
    //Print the pretty boarder
    if(alive)
      attron(A_REVERSE);
    ch[0] = i+'A';
    mvwaddstr(window,y+1+i,x,ch.c_str());
    mvwaddstr(window,y+1+i,x+11," ");
    if(alive)
      attroff(A_REVERSE);

    //Print the contents of the grids
    string dad;
    dad = helpme.substr(i*10,10);
    mvwaddstr(window,y+1+i,x+1,dad.c_str());
      
  }
  if(alive)
    attron(A_REVERSE);
  mvwhline(window,y+11,x,' ',12);
  mvwaddstr(window,y+11,x+1+(10-caption.size())/2,caption.c_str());
  if(alive)
    attroff(A_REVERSE);

  //print the TURN line
  if(current)
  {
    attron(A_REVERSE);
    mvwhline(window,y+13,x,' ',12);
    attroff(A_REVERSE);
  }


}

void drawScreen(){
  if(!console.needsDraw()){
    return;
  }
  clear();
  getmaxyx(window,height,width);

  mvwaddstr(window,24,width/2-msg.size()/2,msg.c_str());

  string line = console.getBuffer();

  //Draw messages box
  attron(A_REVERSE);
  mvwhline(window,0,0,' ',width);
  mvwaddstr(window,0,0,"Messages:");
  mvwhline(window,6,0,' ',width);
  attroff(A_REVERSE);
  for(unsigned int i = 0; i < 5 && i < history.size(); ++i){
    string message = history[history.size()-1-i].substr(0,width);
    mvwaddstr(window,5-i,0,message.c_str());
    //mvwaddstr(window,5-i,0,history[history.size()-1-i].c_str());
  }

 //draw boards -- in example case four checkerboards
  string cap[] = {"one","two","three","four"};
  for(int i=0;i < 4; ++i){
    string caption = cap[i];
    if(player_number == i)
      caption = "Me";
    
    if(turn-1 == i)
      drawBoard(caption,boards[i],true);
    else
      drawBoard(caption,boards[i],false);
  }
   
  //Draw command prompt
  attron(A_REVERSE);
  mvwhline(window,height-2,0,' ',width);
  mvwaddstr(window,height-2,0,"Command:");
  attroff(A_REVERSE);

  mvwaddstr(window,height-1,0,line.c_str());
}

int main(int argc,char** argv){
  bool spec;

  //Starting page
  cout << "~.~*^*~.~WELCOME TO BATTLESHIP~.~*^*~.~\n";
  cout << "Would you like to join as a player, or spectator?\n";
  cout << "P - Player | S - Spectator\n";
  char answer;
  cin >> answer;
  answer = toupper(answer);
  if(answer != 'P')
    spec = true;
  else
    spec = false;

  //Initiate server connection and Cursus
  Socket socket;
  SocketSet socketSet;
  socket.open(argv[1],argv[2]);
  socket.joinGroup(&socketSet);
  initCurses();
  string line = "";

  //Define all the players starting boards
  for(int h=0;h<4;h++)
  {  
    boards[h].origin_y = 8;
    boards[h].origin_x = (width-51)/2+h*14;
    for(int i=0;i<10;i++)
      for(int j=0;j<10;j++)
	boards[h].grid[i][j] = '.';
    boards[h].alive = true;
  }

  console.reDraw();
  drawScreen();

  //Attempt to join as a player
  if(spec == false)
  {
    //Upon first join - send the JOIN command
    socket.writeString("JOIN      ");
  }
  else//attempt to join as a spectator
  {
    socket.writeString("VIEW      ");
  }

  //Expect a GRID response if player join
  //otherwise expect a VIEW response
  socketSet.wait(10);
  if(socket.hasEvent())
    socket.readString(msg,10);//110 is right, right?

  history.push_back(msg);
  //We should probably check to make sure its a GRID message first
  if(strncmp(msg.c_str(), "GRID", 4) == 0)
  {
    //Get our player number
    player_number = msg[5] - '0' - 1;

    //Read in the grid
    socket.readString(msg,100);
    int counter = 0;
    for(int i=0;i<10;i++)
      for(int j=0;j<10;j++)
      {
	grid[i][j] = msg[counter];
	counter++;
      }

    //Assign the read-in grid to the appropriate player board
    for(int i=0;i<10;i++)
      for(int j=0;j<10;j++)
      {
	boards[player_number].grid[i][j] = grid[i][j];
      }
    ss.str("");
    ss << "Welcome! You are player number " << player_number+1 << ", please wait for the other players to join";
    history.push_back(ss.str());

  }

  //But wait, what if were a spectator?
  //Expect the SPEC command in return to VIEW
  else if(strncmp(msg.c_str(), "SPEC", 4) == 0)
  {
    //Epic code to handle spectating
    //Read in the grids
    
    player_number = -1;

    socket.readString(msg,400);
    int counter = 0;
    for(int grid=0;grid<4;grid++)
      for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	{
	  boards[grid].grid[i][j] = msg[counter];
	  counter++;
	}

    history.push_back("You are a SPECTATOR for this game\n");
    msg = "You are a SPECTATOR for this game";

  }
  else //We've received something very unexpected. Try again i guess
  {
    cerr << "Servers not sending the right thing back" << endl;
  }

  bool fail = false;
  while(!socket.isClosed()){//Active connection with the server
    ss.str("");
    if(fail == true){
      fail = false; 
      msg = "Your command was typed incorrectly. Nothing was sent.";
      console.reDraw();
      drawScreen();
    } 
    if(console.getLine(window,line)){
      //EXECUTING COMMANDS/ Make work plz
      if(line == "quit"){
	socket.close();
      }
      else if(line == "")
      {
	fail = true;
	continue;
      }
      else if(line[0] == '/')//Its a message
      {
	if(line[1] != ' ')//its a TELL
	{
	  if(line[1] != '1' && line[1] != '2' && line[1] != '3' && line[1] != '4')
	  {//Fails the target error check
	    fail = true;
	    continue;
	  }
	  string message = line.substr(3);
	  ss.str("");
	  char size = (char)message.size();
	  if(size < 32)
	  {  
	    for(int i=0;i<32-size;i++)
	      message.push_back(' ');
	    size = 32;
	  }
	  ss << "->TELL:[" << line[1] << "] " << message;
	  history.push_back(ss.str());
	  ss.str("");
	  ss << "TELL" << size << line[1] << " " << player_number+1 << "  " << message;
	  console.reDraw();
	  drawScreen();

	}
	else{//Its a YELL
	  string message = line.substr(2);
	  ss.str(""); 
	  char size = (char)message.size();
	  if(size < 32)
	  {  
	    for(int i=0;i<32-size;i++)
	      message.push_back(' ');
	    size = 32;
	  }
	  ss << "YELL" << size << player_number+1 << "    " << message;
	}
      }//YELL/TELL
      else if(line[0] == '!')//Attack command
      {//!2 A5
	if((line[1] != '1' && line[1] != '2' && line[1] != '3' && line[1] != '4')
	    || (line.size() != 5))
	{  
	  continue;//Failes the target error check
	  fail = true;
	}
	ss.str("");
	ss << "FIRE " << line[1] << " " << (char)toupper(line[3]) << " " << line[4];
      }//Attack command
      else
      {//Command not recognized, try again
	fail = true;
	continue;
      }

      if(fail == false)
	socket.writeString(ss.str());

      continue;

    }//End of send command
    else//Start of recv command
    {
      socketSet.wait(0);
      if(socket.hasEvent()){//Recv a message from the server
	socket.readString(msg,10);
	//Potential commands:

	//HIT! # Y X. or MISS
	if(((strncmp(msg.c_str(),"HIT!",4) == 0)) || (strncmp(msg.c_str(),"MISS",4) == 0))
	{
	  //Incursus magic
	  //Y = A-J   X= 0-9

	  string cmd;
	  ss.str(msg);
	  ss >> cmd; // cmd = HIT! or MISS

	  int player = msg[5] - '0';
	  int Y = msg[7] - 'A';
	  int X = msg[9] - '0';

	  if(cmd == "HIT!")
	  {
	    //Mark the location on that persons grid with an X
	    boards[player-1].grid[Y][X] = 'X';
	    ss.str("");
	    ss << "HIT! Player " << player << " was hit at " << msg[7] << msg[9];
	    history.push_back(ss.str());
	    msg = ss.str();
	  }
	  else if(cmd == "MISS")
	  {
	    //Mark that loc with a O
	    boards[player-1].grid[Y][X] = 'O';
	    ss.str("");
	    ss << "MISS! Player " << player << " was missed at " << msg[7] << msg[9];
	    history.push_back(ss.str());
	    msg = ss.str();
	  }
	}//HIT!/MISS

	//BOOM # S  .
	else if(strncmp(msg.c_str(),"BOOM",4) == 0)
	{
	  int player = msg[5] - '0';
	  int ship = msg[7] - '0';

	  string s_ship;

	  if(ship == 1)
	    s_ship = "(2) Patrol Boat";
	  else if(ship == 2)
	    s_ship = "(3) Submarine";
	  else if(ship == 3)
	    s_ship = "(3) Destroyer";
	  else if(ship == 4)
	    s_ship = "(4) Battleship";
	  else if(ship == 5)
	    s_ship = "(5) Aircraft Carrier";

	  ss.str("");
	  ss << "BOOM! Player " << player << " had their " <<  s_ship << " blown up!" << endl;
	  history.push_back(ss.str());
	  msg = ss.str();

	}//BOOM

	//DEAD #    .
	else if(strncmp(msg.c_str(),"DEAD",4) == 0)
	{
	  int player = msg[5] - '0';

	  ss.str("");
	  ss << "DEAD! Player " << player << " has no ships left!" << endl;
	  history.push_back(ss.str());

	  boards[player-1].alive = false;

	  if(player_number == player)//ITS ME OMG
	  {
	    msg = "YOU ARE DEAD. NOT BIG SURPRISE";
	  }
	  else
	    msg = ss.str();

	}//DEAD

	//YELL*#    0x
	else if(strncmp(msg.c_str(),"YELL",4) == 0)
	{
	  int player = msg[5] - '0';
	  int size = msg[4];

	  socket.readString(msg,size);
	  string message = msg;

	  ss.str("");
	  ss << "YELL:[" << player << "] " << message << endl;
	  history.push_back(ss.str());

	  msg = ss.str();

	}
	//TELL*# #  0x
	//    To From
	else if(strncmp(msg.c_str(),"TELL",4) == 0)
	{
	  int from = msg[7] - '0';
	  int size = msg[4];

	  socket.readString(msg,size);
	  string message = msg;

	  ss.str("");
	  ss << "TELL:[" << from << "] " << message << endl;
	  history.push_back(ss.str());

	  msg = ss.str();
	}

	//TURN #    .
	//Whos turn is it :O
	else if (strncmp(msg.c_str(),"TURN",4) == 0)
	{
	  turn = msg[5] - '0';
	  ss.str("");
	  ss << "It is now player number " << turn << "'s turn";
	  history.push_back(ss.str());

	  msg = ss.str();
	}

	if(!socket.isClosed()){
	  flash();
	  //msg = "[server]:" + msg;
	  console.reDraw();
	}
      }

    }
    drawScreen();
  }
  shutdownCurses();
  return 0;
}
