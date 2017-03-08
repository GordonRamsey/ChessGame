#include "Socket.h"
#include "Timer.h"
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

Socket listener;
vector<Socket> sockets;

int turn; //Which players turn is it?

struct player{
  char grid [10][10];
  int number;
  Socket socket;
  bool alive;
  bool AI;
};

int AI_is_coming [] = {0,0,0,0};
vector<player> players;
vector<player> spectators;
stringstream ss;
Timer watch;
bool active_game = false;

void fire(int target, int Y, int X)
{
  char loc = players[target-1].grid[Y][X];

  if(loc != '.' && loc != 'O')//We have a hit
  {

    // Mark ship as hit
    players[target-1].grid[Y][X] = 'X';

    //Broadcast the hit to everyone
    ss.str("");
    ss << "HIT! " << target << " " << (char)(Y + 'A') << " " << X;
    for(unsigned int j =0; j < sockets.size(); ++j){
      sockets[j].writeString(ss.str());
    }
    cerr << ss.str() << endl;

    // Check if ship is dead		  
    //Check if the loc character still exists
    bool ship_alive = false;
    for(int j=0;j<10;j++)
      for(int k=0;k<10;k++)
      {
	if(players[target-1].grid[j][k] == loc)
	  ship_alive = true;
      }

    //If that character is no longer on the board, report ship death
    if(ship_alive == false)
    {
      ss.str("");
      ss << "BOOM " << target << " " << loc - '0' << "  ";
      for(unsigned int j =0; j < sockets.size(); ++j){
	sockets[j].writeString(ss.str());
      }
      cerr << ss.str() << endl;

      // Check if player is dead
      bool playeralive = false;
      for(int j=0;j<10;j++)
	for(int k=0;k<10;k++)
	{
	  char spot = players[target-1].grid[j][k];
	  if(spot != '.' && spot != 'X' && spot != 'O')
	    playeralive = true;
	}

      //If player is dead - Broadcast and let the player know
      if(playeralive == false)
      {
	ss.str("");
	ss << "DEAD " << target << "    ";
	for(unsigned int j =0; j < sockets.size(); ++j){
	  sockets[j].writeString(ss.str());
	}
	cerr << ss.str() << endl;
	//Make that player dead
	players[target-1].alive = false;
      }//Player is dead
    }//Sunk ship
  }//Hit
  else//We have a miss
  {
    players[target-1].grid[Y][X] = 'O';

    //broadcast the miss message
    ss.str("");
    ss << "MISS " << target << " " << (char)(Y + 'A') << " " << X;
    for(unsigned int i =0; i < sockets.size(); ++i){
      sockets[i].writeString(ss.str());
    }
    cerr << ss.str() << endl;
  }	
  //Fire has been properly executed and the turn is now over
}

//use this to YELL to all clients
void broadcast(string message)
{
  ss.str("");
  int size = message.size();
  if(size < 32)
  {
    for(int i=0;i<32-size;i++)
      message.push_back(' ');
    size = 32;
  }

  ss << "YELL" << (char)size << "0    " << message;

  for(unsigned int j =0; j < sockets.size(); ++j){
    sockets[j].writeString(ss.str());
  }
}


//AI Function
void AI(player leaver)
{
  watch.start(2);
  int x = rand() % 10;
  int y = rand() % 10;
  int target = ((int)rand() % 4) + 1;

  //Its a crappy AI, but dont shoot yourself man
  while(target == leaver.number)
    target = ((int)(rand() % 4)) + 1;

  while(watch.timeLeft() != 0)
  {
    //giving the clients a second to catch up  
  }
  fire(target, y, x);

  ss.str("");
  ss << "Player " << leaver.number << " is absent. AI shot for them";
  broadcast(ss.str());
  cerr << ss.str() << endl;

}

void nextTurn()
{
  int current = turn + 1;
  if(current == 5)
    current = 1;

  while(true)
  {
    //check if player is alive
    if(players[current-1].alive == false)
      current++;
    else
      break;
    if(current == 5)
      current = 1;
  }

  turn = current;

  ss.str("");
  ss << "TURN " << turn;
  for(unsigned int j =0; j < sockets.size(); ++j){
    sockets[j].writeString(ss.str());
  }
  cerr << ss.str() << endl;

  //AI CHECK - Player have 2 misses?
  //If so, take their turn for them
  if(AI_is_coming[turn-1] > 0)
  {
    players[turn-1].AI = true;
    AI(players[turn-1]);

    //ERROR CHECK - Are all players AI?
    bool endgame = true;
    for(int i=0;i<4;i++)
    {
      cerr << "Player " << i << " - AI:" << players[i].AI << endl;
      if(players[i].AI == false)
	endgame = false;
    }
    if(endgame == true)
    {
      cerr << "THE PLAYERS ARE ALL AFK. ITS ALL OGRE" << endl;
      exit(0);
    }

    nextTurn();
  }//AI

  watch.start(30);
}

void generateGrid(vector<vector<char> > & grid)
{
  //Fill it with blanks
  vector<char> line;
  for(int i=0;i<10;i++)
    line.push_back('.'); 

  for(int i=0;i<10;i++)
    grid.push_back(line);

  //Generate the 1, 2, 3, 4, 5 ship
  //             2  3  3  4  5 size

  //for each ship
  for(int i=1;i<6;i++)
  {
    //pick a place till it works
    while(true){
      srand(rand()*time(NULL));
      srand(rand()*time(NULL));
      int x = rand() % 10;
      int y = rand() % 10;

      int dir = rand() % 2;

      int size = i;
      if(size == 1 || size == 2)
	size += 1;

      bool fail = false;

      //Does it fits?
      for(int check=0;check<size;check++)
      {
	if(y+size >= 10 || x+size >= 10)
	{
	  fail = true;
	  break;
	}
	if(dir == 0){ 
	  if(grid[y+check][x] != '.')
	  { 
	    fail = true;
	    break;
	  }
	}
	else if(dir == 1)
	  if(grid[y][x+check] != '.')
	  { 
	    fail = true;
	    break;
	  }
      }
      //oh yes it fits
      if(fail == false)
      {
	if(dir == 0)
	  for(int draw=0;draw<size;draw++)
	    grid[y+draw][x] = (char)i+48;
	else if(dir == 1)
	  for(int draw=0;draw<size;draw++)
	    grid[y][x+draw] = (char)i+48;

	break;//get out of this while loop
      }
      //Didnt fits, try again forever
    }

  }

  cerr << "Grid completed:\n";
  for(int i=0;i<10;i++)
  {  
    for(int j=0;j<10;j++)
      cerr << grid[i][j];

    cerr << endl;
  }

}

void sendError(Socket socket, string message)
{
  ss.str("");
  int size = message.size();
  if(size < 32)
  {
    for(int i=0;i<32-size;i++)
      message.push_back(' ');
    size = 32;
  }
  ss << "TELL" << (char)size << "? 0  " << message;
  socket.writeString(ss.str());
}

void spec(Socket socket)
{
  //Send the current grids to the spectator
  ss.str("");
  ss << "SPEC      ";
  for(int j=0;j<4;j++)
    for(int k=0;k<10;k++)
      for(int l=0;l<10;l++)
      {
	char spot = players[j].grid[k][l];
	if(spot == '.' || spot == 'X' || spot == 'O')
	  ss << spot;
	else
	  ss << '.';
      }
  socket.writeString(ss.str());
  cerr << ss.str();
}



int main(int argc,char** argv){
  SocketSet socketSet;
  listener.listen(argv[1]);
  listener.joinGroup(&socketSet);
  string msg = "";
  watch.start(9999);
  //start a 30 second timer

  while(!listener.isClosed()){
    //wait at most 2 seconds -- on event it will interupt
    socketSet.wait(2);

    msg = "";

    if(listener.hasEvent()){
      Socket sock = listener.accept();
      sock.joinGroup(&socketSet);
      cout << sock.toString() << " has joined\n";
      sockets.push_back(sock);
    }else{
      for(int i =sockets.size()-1; i >=0; --i){
	if(sockets[i].hasEvent()){
	  int bytes = sockets[i].readString(msg,255);
	  if(!sockets[i].isClosed())
	  {
	    cerr << msg << "\n";
	    //What message did we just receive? How to handle?

	    //VIEW
	    //Join as a spectator, confirm that they are in
	    if(strncmp(msg.c_str(),"VIEW",4) == 0)
	    {
	      spec(sockets[i]);	     
	    }

	    //JOIN      .
	    //Handles differently from the other commands
	    if(strncmp(msg.c_str(),"JOIN",4) == 0)
	    {
	      //Is the player list full?
	      if(players.size() == 4)
	      {
		//Yes - send back VIEW
		spec(sockets[i]);
	      }//VIEW
	      else//Not spectating, joining
	      {
		//No - send back the players number and grid
		player newplayer;
		newplayer.socket = sockets[i];
		newplayer.number = players.size() + 1;
		newplayer.alive = true;

		//Generate a grid for this player
		vector<vector<char> > grid;

		//Generating code
		// . = empty , 1/2/3/4/5 = ship , X = hit
		generateGrid(grid);

		//Give graph to new player, and convert it to string
		string s_grid;
		for(int y=0;y<10;y++)
		{  for(int x=0;x<10;x++)
		  {
		    newplayer.grid[y][x] = grid[y][x];
		    s_grid.push_back(grid[y][x]);
		  }
		}

		players.push_back(newplayer);//We now have a full player added

		//Send the player their grid info
		ss.str("");
		ss << "GRID " << newplayer.number << "    " << s_grid;
		cerr << ss.str() << endl;
		newplayer.socket.writeString(ss.str());

		//Perhaps we should broadcast that this player has joined?

		ss.str("");
		int count = players.size();
		ss << "A new player has joined! Current player count:" << count;
		cerr << ss.str() << endl;
		broadcast(ss.str());

		//for(unsigned int j =0; j < sockets.size(); ++j){
		//  sockets[j].writeString(ss.str());
		//}

		//Also, is the list full and the game can start now?
		if(players.size() == 4)
		{
		  //-----IMPORTANT GAME STARTING THINGS-----
		  //Start the timer, and assign player 1 the first turn
		  turn = 1;
		  watch.start(30);
		  active_game = true;

		  //That should be broadcasted as well
		  ss.str("");
		  ss << "The game has begun! Let the odds be ever in your favor. Player1 please begin";
		  broadcast(ss.str());
		  cerr << ss.str() << endl;
		}//for
	      }//if game is ready to start
	    }//JOIN, not VIEW - already completed
	    else//Commands that apply only to players
	    {
	      bool valid = false;

	      //ERROR CHECK - Dont accept commands if game hasent started
	      if(players.size() != 4)
	      {
		sendError(sockets[i], "Please dont send commands before the game starts");
		valid = false;
		continue;
	      } 

	      int current_player = -1;
	      //ERROR CHECK - Is this from a current player?
	      for(int j=0;j<4;j++)//Is this from a current player?
	      {
		if(players[j].socket == sockets[i])
		{  
		  valid = true;
		  current_player = j;
		}
	      }

	      //ERROR CHECK - Is this current player dead?
	      if(current_player != -1)
	      {
		if(players[current_player].alive == false)
		{
		  sendError(sockets[i],"The dead do not speak...");
		  continue;
		}
	      }

	      if(valid != true)//Its from a spec or something. Just ignore it
	      {
		cerr << "IGNORED";
		continue;
	      }

	      //ERROR CHECK - Set this players AI counter to 0
	      AI_is_coming[current_player] = 0;
	      players[current_player].AI = false;

	      //FIRE # Y X.
	      //Whats involved:
	      //- Hit/miss
	      //- Was ship destroyed?
	      //- Is player destroyed?

	      if(strncmp(msg.c_str(),"FIRE",4) == 0)
	      {
		//ERROR CHECK - Is the firecommand created correctly?
		if(msg.size() != 10)
		  sendError(sockets[i], "ALERT: Invalid FIRE command");

		//ERROR CHECK - is it from the right player?
		valid = false;
		for(int j=0;j<4;j++)
		{
		  if(players[j].socket.hasEvent())
		  {
		    if(players[j].number != turn)//Is it their turn?
		    {
		      //If its not, kindly tell them to not do that
		      //This showed up, but hits still went through
		      sendError(sockets[i], "ALERT: PLEASE DO NOT ATTACK YET");
		    }
		    else
		    {
		      valid = true;
		      break;
		    }
		  }
		}

		if(valid == true)//It is this players turn
		{
		  cerr << "Proper player initiated an attack. calculating results..." << endl;
		  int target = msg[5] - '0';
		  int Y = msg[7] - 'A'; 
		  int X = msg[9] - '0';

		  //ERROR CHECK- Are the coords valid?
		  if(!((Y >= 0) && (Y < 10)) || !((X >= 0) && (X < 10)))
		  {
		    sendError(sockets[i],"ALERT: Invalid Coordinates");
		    continue;
		  }

		  fire(target,Y,X);
		  nextTurn();
		}//Players turn
	      }//FIRE

	      //YELL*#    0x
	      //Send the yell message all the cluients ways
	      else if(strncmp(msg.c_str(),"YELL",4) == 0)
	      {  
		for(unsigned int j =0; j < sockets.size(); ++j){
		  sockets[j].writeString(msg);
		}
	      }//Yell

	      //TELL*# #  0x
	      //        To From
	      //send the tell message to the appropriate player
	      else if(strncmp(msg.c_str(),"TELL",4) == 0)
	      {
		int i_to = msg[5] - '0';	
		players[i_to-1].socket.writeString(msg);

	      }//tell

	      //ERROR CHECK - UNKNOWN COMMAND
	      else
	      {
		sendError(sockets[i], "ALERT: Unknown Command");
	      }

	      //sockets[i].writeString(msg);
	    }//Else - commands that are only for players
	  }//if socket !closed
	  else{
	    sockets.erase(sockets.begin()+i);
	  }
	}//If socket has event
      }//For all sockets
    }//if listener has events

    if(active_game == true)
    {
      //Check if the game is over
      int gameover = 0;
      int whos_alive;
      for(int j=0;j<4;j++)
      {//is only 1 player alive?
	if(players[j].alive == true)
	{
	  gameover++;
	  whos_alive = j;
	}
      }
      if(gameover == 1)//Nope, guess its all ogre
      {
	ss.str("");
	broadcast("~*^*~.~THE GAME IS OVER~.~*^*~");
	ss << "PLAYER " << whos_alive << " IS THE WINNER";
	broadcast(ss.str());
	cerr << ss.str() << endl;
	break;
      }

      if(watch.timeLeft() < 6){
	broadcast("TIME: Almost out of time!");
      }
      if(watch.timeLeft() == 0){
	ss.str("");
	ss << "ALERT: Player" << turn << " ran out of time";
	broadcast(ss.str());
	cerr << ss.str() << endl;

	//If the player has missed 2 turns, set them to AI
	AI_is_coming[turn-1]++;
        cerr << "Player AI count:" << AI_is_coming[turn-1] << endl;	
	nextTurn();
      }
    }
  }
  for(unsigned int i =0; i < sockets.size(); i++){
    sockets[i].close();
  }
  return 0;
}

