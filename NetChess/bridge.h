#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//Network includes
#include "Net_Assets/Socket.h"
#include "Net_Assets/SocketSet.h"

//String input includes
#include "Text_Assets/StringInput.h"

//Piece include
#include "Piece_Assets/piece.h"

//Default template includes
#include "Piece_Assets/pawn.h"
#include "Piece_Assets/rook.h"
#include "Piece_Assets/knight.h"
#include "Piece_Assets/bishop.h"
#include "Piece_Assets/king.h"
#include "Piece_Assets/queen.h"
#include "Piece_Assets/wall.h"

//Fighter includes
#include "Piece_Assets/Fighters/Fpawn.h"
#include "Piece_Assets/Fighters/Frook.h"
#include "Piece_Assets/Fighters/Fknight.h"
#include "Piece_Assets/Fighters/Fbishop.h"
#include "Piece_Assets/Fighters/Fking.h"
#include "Piece_Assets/Fighters/Fqueen.h"

//Golem includes
#include "Piece_Assets/Golem/Gpawn.h"
#include "Piece_Assets/Golem/Grook.h"
#include "Piece_Assets/Golem/Gknight.h"
#include "Piece_Assets/Golem/Gbishop.h"
#include "Piece_Assets/Golem/Gking.h"
#include "Piece_Assets/Golem/Gqueen.h"

//Necro includes
#include "Piece_Assets/Necro/Npawn.h"
#include "Piece_Assets/Necro/Nrook.h"
#include "Piece_Assets/Necro/Nknight.h"
#include "Piece_Assets/Necro/Nbishop.h"
#include "Piece_Assets/Necro/Nking.h"
#include "Piece_Assets/Necro/Nqueen.h"

//Game object includes
#include "Piece_Assets/chess.h"



//This is meant to be a flexible header file
//Change it according to where you will be locally running the program
