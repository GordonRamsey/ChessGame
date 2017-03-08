Andrew the Brogan
Alex Caroll
Eden Church

Group 3 README

(Since I now know that you read these, I'll try to make it worth your while)

To Compile:
 Use the make file that our glorious overload Dymacek gave us.
 use the command "make"

To Run:
 This part is important:
  The game will not start until 4 players are connected.
  You cannot speak or do anything while the game is waiting for players

 To run a server:
  Use the command - ./server <PORT #>

 To run a client:
  Use the command - ./client <IP ADDRESS> <PORT #>
  After launching the client, you will be prompted wheter to join as a player or spectator
  Just follow what it says on screen

Notes:
 Andrew worked a long time on this and would like a good grade
 I think we have all the bonus points
  - but not that one involving a not-text-based client. Becasue this is clearly text based
  - Also, its not written in another language. So theres that.

Other Stuff:
 So much error checking. (All with appropriate error messages :^))
  Client - Checks to make sure that youre only sending off real commands
  Client - Wont blow up if the server sends back something odd
  Client - Apparently this isnt really a problem, but if a message size is < 32, it will fill the rest with ' '
    This lets it print to the server console without anything freaky happening
  Server - Added a sendError function to the server for easy errorSending
  Server - Checks that its only receiving real commands
  Server - Fire checks that the coordinates are good
  Server - Wont accept player commands (FIRE, YELL, TELL) from non-players
  Server - Wont accept commands till the game has started
  Server - Wont accept commands from dead players
  Server - Wont accept a FIRE command when its not the players turn
  Server - Checks if the FIRE command was properly formatted
    AI   - Checks if all players go AFK. Its all ogre if they do.
  
 Added a visual bar to show whos turn it currently is
  Included a TURN command exchange between server and client

 Grid boarders turn black when a player dies

 Added a few things here and there to make the text bar in the center easier to look at

 AI takes over if the player misses a turn in
  player can come back by simply issuing a command

 Spectators get a full history of events, rather than just being thrown into whats current
  AKA they enter with a bunch of X's and O's already in place. No they cannot see the ship placements
  This is done through the use of a SPEC command which the server responds to VIEW with
  it goes <SPEC      <GRID1><GRID2><GRID3><GRID4>>
  all the grid info should be ignored by my classmates clients. If they were made correctly :^)

