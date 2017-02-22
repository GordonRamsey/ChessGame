#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>

using namespace std;

// set each piece and pawn values as constant integers
const int pawn = 100;  // 1 = 1 centipawn; 90 = 90 centipawns
const int knight = 300;
const int bishop = 305;
const int rook = 500;
const int queen = 900;
const int king = 20000;

// this is the board it will contain the pieces and pawns
// the first array is for files, the second array is ranks
// ie board[file][rank];
int board[8][8];

string enpassant;

// boolean containers start all with true and become false if castling to their direction becomes broken in the game
// wkside is white kingside castling
// wqside is whites and queenside castling etc....
// If position is loaded from FEN, castling true or false is set according to FEN position
bool wkside;
bool wqside;
bool bkside;
bool bqside;

//onmove is a string that contains the character "w" when it is white to move and "b" when it is black to move
string onmove = "w"; // bool onmove = true;
void printboard(void);
int file2num(string);
string blackmoves(int, int);
string piece2char(int);  // 900 = 'Q'
const int setupboard[8][8] = { rook,  knight, bishop, queen, king, bishop, knight, rook, pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};

void setupinit (void) {

	int a;
	int b;

	onmove = "w";

	wkside = true;
	wqside = true;
	bkside = true;
	bqside = true;

	enpassant = "";

	for (a = 0; a < 8; a++){
		for (b = 0; b < 8; b++){
			board[a][b] = setupboard[a][b];
		}
	}
}

//function prototype
//prototype of function that generates all animal moves regardlessif it leaves or puts friendly king in check
//returns a string containing all moves 4 characters each
string whitemoves(int, int);
int rank2num(string);
int char2promote(char, string);
string checkwhite(int, int, int, int);
string checkblack(int, int, int, int);

string chfile(int);
string chrank(int);

bool bounds (int a, int b){
    if ((a >= 0) && (a <= 7) && (b >= 0) && (b <= 7)){
        return true;
    }
    else{
        return false;
    }
}

/* ########################  Main  ####################################### */
int main (void){
	using namespace std;
	string passd;
	string list;
	int x4;
	bool usebook = false;
	int epsqa, epsqb;
	srand ( time(NULL) );
	//passd = "a";
	//cout << file2num(passd);
	//cin.get();
	setupinit();
while (1){
	getline (cin, passd );

if (passd == "uci\x0" )
{
	cout << "id name Echo chess program v 0.7" << endl;
	cout << "id author avery c. aka deepglue5 aka smackthat9876 @ youtube " << endl;
        cout << "option name internal book type check default false" << endl;
        //cout << "option name UCI_EngineAbout type string default http://www.website...." << endl; //unremark this to publish your chess engines website inside the executable
	cout << "uciok" << endl;
}
if (passd == "ucinewgame\x0")
{
	setupinit();
}


if (passd == "isready\x0") {
cout << "readyok" << endl;
}
if (passd ==  "setoption name internal book value false\x0"){
usebook = false;
cout << "info internal book off" << endl;
}
if (passd ==  "setoption name internal book value true\x0"){
usebook = true;
cout << "info internal book on" << endl;
}
if (passd == "quit\x0")   {
cout << "Goodbye !!" << endl << "Thankyou for Playing Echo chess v 0.7";
goto end1;
}
if (passd.substr(0, 9) == "listmoves"){
	  if (onmove == "w") {

        list = whitemoves(epsqa, epsqb);
 }
 else {

        list = blackmoves(epsqa, epsqb);
 }
 cout << list << "\n";
 }
if (passd.substr(0, 10) == "printboard"){
	 printboard();
 }
if (passd.substr(0, 2) == "go"){  //GUI tells program to start 'thinking'


 if (onmove == "w") {

        list = whitemoves(epsqa, epsqb);
 }
 else {

        list = blackmoves(epsqa, epsqb);
 }

bool restorecastle[4];
bool whitecastle = false;
bool blackcastle = false;
int captured;
bool epcapture;
int x, m;
int a, b, c, d;
string move1;
x = list.length();
int branchnode = 0;
int branchnodevalue[218];
string branchmove[218]
if (x == 0) goto noplay;


//test white or blacks first move to call alphabeta
for(m = 0; m += 4; m < x){
    if((list.substr(m+2,1) != "1") && (list.substr(m+2,1) != "8")){

        b = file2num(list.substr(m, 1));
        a = rank2num(list.substr(m + 1, 1));
        d = file2num(list.substr(m + 2, 1));
        c = rank2num(list.substr(m + 3, 1));

        restorecastle[0] = wkside;
        restorecastle[1] = wqside;
        restorecastle[2] = bkside;
        restorecastle[3] = bqside;

        if (board[a][b] == king && a == 0 && b == 4 && c == 0 && d == 6){   // castling white kingside
                   board[0][7] = 0;
                   board[0][5] = rook;
                   whitecastle = true;
                 }
                 if (board[a][b] == king && b == 4 && d == 2){		//castling white queenside
                   board[0][0] = 0;
                   board[0][3] = rook;
                   whitecastle = true;
                 }
                 if (board[a][b] == -king && b == 4 && d == 6){		//castling black kingside
                   board[7][7] = 0;
                   board[7][5] = -rook;
                   blackcastle = true;
                 }
                 if (board[a][b] == -king && b == 4 && d == 2){		//castling black queenside
					 board[7][0] = 0;
                   board[7][4] = -rook;
                   blackcastle = true;
                 }
            switch (board[a][b]){    // Rook and King moves break castling
             case rook:
				 if(a == 0 && b == 0){
					 wqside = false;
				 }
				 if(a == 0 && b == 7){
					 wkside = false;
				 }
             break;
             case -rook:
				 if(a == 7 && b == 0){
					 bqside = false;
				 }
				 if(a == 7 && b == 7){
					 bkside = false;
				 }
				 break;
             case king:
             wkside = false;
             wqside = false;
             break;
             case -king:
             bkside = false;
             bqside = false;
             break;
            }
			if(board[a][b] == pawn && a == 1 && c == 3) {  //white created en passant square
				epsqa = 2;
				epsqb = b;
			}
			if(board[a][b] == -pawn && a == 6 && c == 4) { //black created en passant square
				epsqa = 5;
				epsqb = b;
			}
			if((board[a][b] != pawn && board[a][b] != -pawn) || (abs(a - c) != 2)){		//if the move is not a pawn move en passant is non set, or if it is a pawn move but not 2 ranks up or down
				epsqa = 8;
				epsqb = 8;
			}
            //perform the move
            captured = board[c][d];  //store piece captured so it can be replaced when the move is undone
           board[c][d] = board[a][b];
		   board[a][b] = 0;

		   if(board[c][d] == pawn && (b != d) && (captured == 0) && bounds((c - 1), d)){  //white captures en passant? if so remove black pawn behind whites pawn capture
                board[c-1][d] = 0;
                epcapture = true;
			}
            if(board[c][d] == -pawn && (b != d) && (captured == 0) && bounds((c + 1), d)){
                board[c+1][d] = 0;
                epcapture = true;
            }

            //call alphabeta routine here
            branchnodevalue[branchnode] = alphabeta();
            branchmove = list.substr(m, 4);



            //undo castling if necessary
            if(whitecastle){
                if (d==6){  //undo white castle kingside (move the rook back)
                    board[0][5] = 0;
                   board[0][7] = rook;
                   whitecastle = false;
                }
                if(d == 2){  //undo white castle queenside
                    board[0][3] = 0;
                   board[0][0] = rook;
                   whitecastle = true;
                }

            }
            if(blackcastle){
                if (d==6){  //undo black castle kingside (move the rook back)
                    board[7][5] = 0;
                    board[7][7] = -rook;
                    blackcastle = false;
                }
                if(d == 2){  //undo black castle queenside
                    board[7][3] = 0;
                   board[7[0] = -rook;
                   blackcastle = true;
                }
            }

            if (epcapture == true && c == 5){
			board[c-1][d] = -pawn;
			epcapture = false;

		}
		if (epcapture == true && c == 2){
			board[c+1][d] = pawn;
			epcapture = false;

		}

        wkside = restorecastle[0];
        wqside = restorecastle[1];
        bkside = restorecastle[2];
        bqside = restorecastle[3];

        board[a][b] = board[c][d];
		board[c][d] = captured;

    }
branchnode++;
}



move1 = list.substr(m, 4);

switch(move1[3]){
case 'q':
	if(onmove == "w"){
		move1[3] = '8';
	}
	else{
		move1[3] = '1';
	}
	move1 = move1 + "q";
	break;
case 'r':
	if(onmove == "w"){
		move1[3] = '8';
	}
	else{
		move1[3] = '1';
	}
	move1 = move1 + "r";
	break;
case 'b':
	if(onmove == "w"){
		move1[3] = '8';
	}
	else{
		move1[3] = '1';
	}
	move1 = move1 + "b";
	break;
case 'n':
	if(onmove == "w"){
		move1[3] = '8';
	}
	else{
		move1[3] = '1';
	}
	move1 = move1 + "n";		//NOTE DON'T FORGET EN PASSANT
	break;
}
cout << "bestmove " << move1 << '\n';
 noplay:;
}
if (passd.substr(0,17) == "position startpos"  && passd.length() <= 18) {
setupinit();
}


// -> position startpos moves etc...
if (passd.substr(0, 23) == "position startpos moves")   {
int imax, i;
int a, b, c, d;
setupinit();
imax = passd.length();
 for (i = 24; i < imax; i +=5 )
        {
			b = file2num(passd.substr(i, 1));
			a = rank2num(passd.substr(i + 1, 1));
			d = file2num(passd.substr(i + 2, 1));
			c = rank2num(passd.substr(i + 3, 1));

                 if (board[a][b] == king && a == 0 && b == 4 && c == 0 && d == 6){   // castling white kingside
                   board[0][7] = 0;
                   board[0][5] = rook;
                 }
                 if (board[a][b] == king && b == 4 && d == 2){		//castling white queenside
                   board[0][0] = 0;
                   board[0][3] = rook;
                 }
                 if (board[a][b] == -king && b == 4 && d == 6){		//castling black kingside
                   board[7][7] = 0;
                   board[7][5] = -rook;
                 }
                 if (board[a][b] == -king && b == 4 && d == 2){		//castling black queenside
					 board[7][0] = 0;
                   board[7][4] = -rook;
                 }
            switch (board[a][b]){    // Rook and King moves break castling
             case rook:
				 if(a == 0 && b == 0){
					 wqside = false;
				 }
				 if(a == 0 && b == 7){
					 wkside = false;
				 }
             break;
             case -rook:
				 if(a == 7 && b == 0){
					 bqside = false;
				 }
				 if(a == 7 && b == 7){
					 bkside = false;
				 }
				 break;
             case king:
             wkside = false;
             wqside = false;
             break;
             case -king:
             bkside = false;
             bqside = false;
             break;
            }
			if(board[a][b] == pawn && a == 1 && c == 3) {  //white created en passant square
				epsqa = 2;
				epsqb = b;
			}
			if(board[a][b] == -pawn && a == 6 && c == 4) { //black created en passant square
				epsqa = 5;
				epsqb = b;
			}
			if((board[a][b] != pawn && board[a][b] != -pawn) || (abs(a - c) != 2)){		//if the move is not a pawn move en passant is non set, or if it is a pawn move but not 2 ranks up or down
				epsqa = 8;
				epsqb = 8;
			}


           board[c][d] = board[a][b];
		   board[a][b] = 0;

           string str;
		   x4 = passd.length();
		   if(passd.length() > unsigned(i + 4)){

           str = passd[i + 4];		//next character at end of 4 move sequence may be a promotion
           if (str != " " && !str.empty()){
		   board[c][d] = char2promote(passd[i + 4], onmove);
			i++;        // extra character in sequence of moves.
		   }
           }

           if (onmove == "w"){ onmove = "b"; }else {onmove = "w";} //change side to move
        }
	}
}
end1:
	return 0;
}

//actual function, generates all possible animal moves for white in string format ie (R@a1) "a1a2" + "a1a3" etc
string whitemoves(int epa, int epb){	//epa is integer for en passant square file, epb is en passant square rank, together they make a coordinate
	string allmoves;
	int fromSQa[218];
	int fromSQb[218];
	int toSQa[218];
	int toSQb[218];

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int z = 0;
	string promotions;
	int i2;

	promotions = "qrbn";

	for (a = 0; a < 8; a++){
		for (b = 0; b < 8; b++){
			switch (board[a][b]) {

				case queen:
					{
						for (e = -1; e <= 1; e++) {
						for (f = -1; f <= 1; f++) {
							c = a + e;
							d = b + f;
							if (!(f == 0 && e == 0)) {
								do {
									if (bounds(c, d)) {

										if (board[c][d] == 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
										if (board[c][d] < 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;

											z++;
											break;
										}
										if (board[c][d] > 0) break;
										c = c + e;
										d = d + f;
									}
								}
								while (!(bounds(c, d) == false));

							}

						}
					}

                break;
				case rook:
					for (e = -1; e <= 1; e++) {
						for (f = -1; f <= 1; f++) {
							c = a + e;
							d = b + f;
							if (abs(e)+abs(f) == 1) {
								do {
									if (bounds(c, d)) {

										if (board[c][d] == 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
										if (board[c][d] < 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;

											z++;
											break;
										}
										if (board[c][d] > 0) break;
										c = c + e;
										d = d + f;
									}
								}
								while (!(bounds(c, d) == false));

							}

						}
					}
					break;
					case bishop:
					for (e = -1; e <= 1; e++) {
						for (f = -1; f <= 1; f++) {
							c = a + e;
							d = b + f;
							if (abs(e)+abs(f) == 2) {
								do {
									if (bounds(c, d)) {

										if (board[c][d] == 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
									if (board[c][d] < 0) {
										fromSQa[z] = a;
										fromSQb[z] = b;
										toSQa[z] = c;
										toSQb[z] = d;

										z++;
										break;
									}
									if (board[c][d] > 0) break;

								}
							c = c + e;
							d = d + f;
							}
							while (!(bounds(c, d) == false));
						}
					}
				}
				break;
				case knight:
					for(e=-2; e<=2; e+=1){
						for(f=-2; f<=2; f+=1){
							c = a + e;
							d = b + f;
							if(abs(e) + abs(f) == 3){
								if(bounds(c,d)){
									if(board[c][d]<=0){
										fromSQa[z]=a;
										fromSQb[z]=b;
										toSQa[z]=c;
										toSQb[z]=d;
										z+=1;
									}
								}
							}
						}
					}
					break;
					case pawn:
						//white pawn attack left and forward
						c = a + 1;
						d = b - 1;
						if (bounds(c, d)) {		//bounds checks if the square is on the board, if not go to next move direction for pawn.

							if (board[c][d] < 0 || (epa == c && epb == d)) { //if diagonal square attacked contains a piece valued less than zero then capture is possible, or square is the en passant square from previous move.
								fromSQa[z] = a;
								fromSQb[z] = b;
								toSQa[z] = c;
								toSQb[z] = d;
								z++;
							}
						}
						//white pawn attack right and forward
						c = a + 1;
						d = b + 1;
						if (bounds(c, d)) {

							if (board[c][d] < 0 || (epa == c && epb == d)) {
								fromSQa[z] = a;
								fromSQb[z] = b;
								toSQa[z] = c;
								toSQb[z] = d;
								z++;
							}
						}
						//check if one square forward is unoccupied and add it to the movelist
							if (a == 1) {
								c = 2;
								d = b;
								if (bounds(c, d)) {

									if (board[c][d] == 0) {
										fromSQa[z] = a;
										fromSQb[z] = b;
										toSQa[z] = c;
										toSQb[z] = d;
										z++;
										c = 3;
										d = b;
										//another square forward if the pawn is on it's starting rank
										if (bounds(c, d)) {

											if (board[c][d] == 0) {
												fromSQa[z] = a;
												fromSQb[z] = b;
												toSQa[z] = c;
												toSQb[z] = d;
												z++;
											}
										}
									}
								}
							}
						else {	//pawn is not on starting rank
							c = a + 1;
							d = b;
							if (bounds(c, d)) {
								if (board[c][d] == 0) {
									fromSQa[z] = a;
									fromSQb[z] = b;
									toSQa[z] = c;
									toSQb[z] = d;
									z++;
								}
							}
						}

					break;
					case king:
						for (e = -1; e <= 1; e++) {
							for (f = -1; f <= 1; f++) {
								if (!(e == 0 && f == 0)) {
									c = a + e;
									d = b + f;

									if (bounds(c, d)) {		//checks if coordinates exist on the board

										if (board[c][d] <= 0 && checkwhite(c, d, a, b).empty()) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
									}
								}
							}
						}
					//castleKingSide
						if (wkside && a == 0 && b == 4 && board[0][7] == rook && board[0][6] == 0 && board[0][5] == 0) {
							if (checkwhite(0, 4, 0, 4).empty() && checkwhite(0, 5, 0, 4).empty() && checkwhite(0, 6, 0, 4).empty()) {
								fromSQa[z] = 0;
								fromSQb[z] = 4;
								toSQa[z] = 0;
								toSQb[z] = 6;
								z++;
							}
						}

						//castleQueenSide
						if (wqside == true && a == 0 && b == 4 && board[0][0] == rook && board[0][1] == 0 && board[0][2] == 0 && board[0][3] == 0) {
							if (checkwhite(0, 4, 0, 4).empty() && checkwhite(0, 3, 0, 4).empty() && checkwhite(0, 2, 0, 4).empty()) {
								fromSQa[z] = 0;
								fromSQb[z] = 4;
								toSQa[z] = 0;
								toSQb[z] = 2;
								z++;
							}
						}
				} // close switch

			}


		}
	}
	//now all moves are checked to see if they leave the white king in check and if they do they are discarded from the list
	int i;
	int captured;
	int wksqa, wksqb;
	string addmove;

	for(a = 0; a <= 7; a++){
		for(b = 0; b <= 7; b++){
			if(board[a][b] == king){
				wksqa = a;
				wksqb = b;
				goto kingfound;
			}
		}
	}
kingfound:



	bool epcapture;
	epcapture = false;

	i = 0;
	for(i = 0; i < z; i++){
		a = fromSQa[i];
		b = fromSQb[i];
		c = toSQa[i];
		d = toSQb[i];

		//perform the move
		captured = board[c][d];
		board[c][d] = board[a][b];
		board[a][b] = 0;

		if(board[c][d] == pawn && (b != d) && (captured == 0) && bounds((c - 1), d)){
			board[c-1][d] = 0;
			epcapture = true;
		}

		//if the king is the piece moving wksqa and wksqb won't contain the coordinates of the king! c and d will
		if(board[c][d] == king){
			if(checkwhite(c, d, 64, 0).empty()){
				//add move to list, otherwise discard move (do nothing)
				addmove = chfile(b) + chrank(a) + chfile(d) + chrank(c);		//convert coordinates to ascii
				allmoves = allmoves + addmove;		//add to the movelist
			}
		}
		else{		//if the king is not the piece moving then the king is in the coordinates wksqa and wksqb, and we check that square for check, if it is check it is not added to the movelist (allmoves)
			if(checkwhite(wksqa, wksqb, 64, 0).empty()){
				//add move to list, otherwise discard move (do nothing)
				if(!(board[c][d] == pawn && (c == 7))){		// if the move is not a pawn progressed to the 8th rank, then add move to the list, otherwise, pawn promotions and underpromotions must be added to the move list (each)
					addmove = chfile(b) + chrank(a) + chfile(d) + chrank(c);		//convert coordinates to ascii
					allmoves = allmoves + addmove;		//add to the movelist
				}
				else{
					for(i2 = 0; i2 < 4; i2++){
						addmove = chfile(b) + chrank(a) + chfile(d) + promotions.substr(i2,1);		//promotion is 4 characters the file the pawn starts on followed by the rank and file moving to (if capturing will be different) followed by either q for promote to queen, r for rook, n for knight and b for bishop.
						allmoves = allmoves + addmove;		//add to the movelist
					}
				}
			}
		}


		//undo the move
		board[a][b] = board[c][d];
		board[c][d] = captured;

		if (epcapture == true){
			board[c-1][d] = -pawn;
			epcapture = false;

		}

	}
	return allmoves;
}

string checkwhite(int ksqa, int ksqb, int remva, int remvb){
	int checklista[16];
	int checklistb[16];
	int a, b, c, d, e, f, g, num, xa, xb;
	int repl;
	num = 0;
	string freturn;

	if (remva != 64) {

	repl = board[remva][remvb];
	board[remva][remvb] = 0;

	}
	a = ksqa;
	b = ksqb;



	for (e = -2; e < 3; e++){
	 for (f = -2; f < 3; f++){

		  if ((abs(e) + abs(f)) == 3){     //  check for black knight giving check
			 c = a + e;
			 d = b + f;
			 if (bounds(c, d))
			 {

			  if (board[c][d] == -knight ){
				checklista[num] = c;
				checklistb[num++] = d;
				}
			 }
			}               // end check for black knight
		  if ((abs(e) == 1 || abs(f) == 1) && abs(e) + abs(f) <= 2) //check for black king giving check
		  {
         c = a + e;
			 d = b + f;
			 if (bounds(c, d))
			 {

			  if (board[c][d] == -king )
				{
				checklista[num] = c;
				checklistb[num++] = d;
				}
			 }
		  }    // end check for black king

		g = abs(e) + abs(f);
		if (g == 1)         	// check for queen and rook
		{
		c = a + e;
		d = b + f;
		 while (bounds(c, d))
		 {
			//rook or queen (vertical/horizontal)
			if (board[c][d] == -queen || board[c][d] == -rook) {
			checklista[num] = c;
			checklistb[num++] = d;
			num++;
		 }
			if (board[c][d] != 0) break;

			c = c + e;
			d = d + f;
		 }
		}


				 //bishop or queen (diagonally)
				 if (g == 2 && abs(e) == 1) {
					  c = a + e;
					  d = b + f;
					  while (bounds(c, d)) {

							if (board[c][d] == -queen || board[c][d] == -bishop) {
								checklista[num] = c;
								checklistb[num] = d;
								 num = num + 1;
							}
							if (board[c][d] != 0) break;

							c = c + e;
							d = d + f;
					  }
				 }
	 }
	}

 //black pawns deliver check
	  c = a + 1;
	  d = b + 1;

	  if (bounds(c, d)) {

			if (board[c][d] == -pawn) {
				checklista[num] = c;
				checklistb[num] = d;
				 num++;
			}
	  }

	  c = a + 1;
	  d = b - 1;
	  if (bounds(c, d)) {

			if (board[c][d] == -pawn) {
				checklista[num] = c;
				checklistb[num] = d;
				 num++;
			}
	  }

	  string aa, bb, cc, dd;

switch (num)
{
case 0:
freturn.clear();
break;
case 1:

aa = chfile(ksqb);
bb = chrank(ksqa);
xa = checklista[0];
xb = checklistb[0];
cc = chfile(xb);
dd = chrank(xa);
freturn = aa + bb + cc + dd;

break;
default:
aa = chfile(ksqb);
bb = chrank(ksqa);
xa = checklista[0];
xb = checklistb[0];
cc = chfile(xb);
dd = chrank(xa);
freturn = aa + bb + cc + dd;
xa = checklista[1];
xb = checklistb[1];
cc = chfile(xb);
dd = chrank(xa);
freturn = freturn + cc + dd;
break;

}
if (remva != 64) {
board[remva][remvb] = repl;
}
 return freturn;
 }



string chfile(int x){		//takes an integer 0-7 and returns ascii character or one character string of file "a" to "h"
string cho;
    switch(x){
        case 0:
        cho = "a";
        break;
        case 1:
        cho = "b";
        break;
        case 2:
        cho = "c";
        break;
        case 3:
        cho = "d";
        break;
        case 4:
        cho = "e";
        break;
        case 5:
        cho = "f";
        break;
        case 6:
        cho = "g";
        break;
        case 7:
        cho = "h";
        break;

        }
    return cho;
}



string chrank(int x){		//takes an integer (x) 0-7 and returns ascii "1" to '8" Usually to represent rank on the chessboard
    string cho;
    switch(x){
        case 0:
        cho = "1";
        break;
        case 1:
        cho = "2";
        break;
        case 2:
        cho = "3";
        break;
        case 3:
        cho = "4";
        break;
        case 4:
        cho = "5";
        break;
        case 5:
        cho = "6";
        break;
        case 6:
        cho = "7";
        break;
        case 7:
        cho = "8";
        break;

    }
 return cho;
}

string checkblack(int ksqa, int ksqb, int remva, int remvb){
	int checklista[16];
	int checklistb[16];
	int a, b, c, d, e, f, g, num, xa, xb;
	int repl;
	num = 0;
	string freturn;

	if (remva != 64) {

	repl = board[remva][remvb];
	board[remva][remvb] = 0;

	}
	a = ksqa;
	b = ksqb;



	for (e = -2; e < 3; e++){
	 for (f = -2; f < 3; f++){

		  if ((abs(e) + abs(f)) == 3){     //  check for white knight giving check
			 c = a + e;
			 d = b + f;
			 if (bounds(c, d))
			 {

			  if (board[c][d] == knight ){
				checklista[num] = c;
				checklistb[num++] = d;
				}
			 }
			}               // end check for black knight
		  if ((abs(e) == 1 || abs(f) == 1) && abs(e) + abs(f) <= 2) //check for black king giving check
		  {
         c = a + e;
			 d = b + f;
			 if (bounds(c, d))
			 {

			  if (board[c][d] == king )
				{
				checklista[num] = c;
				checklistb[num++] = d;
				}
			 }
		  }    // end check for black king

		g = abs(e) + abs(f);
		if (g == 1)         	// check for queen and rook
		{
		c = a + e;
		d = b + f;
		 while (bounds(c, d))
		 {
			//rook or queen (vertical/horizontal)
			if (board[c][d] == queen || board[c][d] == rook) {
			checklista[num] = c;
			checklistb[num++] = d;
			num++;
		 }
			if (board[c][d] != 0) break;

			c = c + e;
			d = d + f;
		 }
		}


				 //bishop or queen (diagonally)
				 if (g == 2 && abs(e) == 1) {
					  c = a + e;
					  d = b + f;
					  while (bounds(c, d)) {

							if (board[c][d] == queen || board[c][d] == bishop) {
								checklista[num] = c;
								checklistb[num] = d;
								 num = num + 1;
							}
							if (board[c][d] != 0) break;

							c = c + e;
							d = d + f;
					  }
				 }
	 }
	}

 //white pawns deliver check
	  c = a - 1;
	  d = b + 1;

	  if (bounds(c, d)) {

			if (board[c][d] == pawn) {
				checklista[num] = c;
				checklistb[num] = d;
				 num++;
			}
	  }

	  c = a - 1;
	  d = b - 1;
	  if (bounds(c, d)) {

			if (board[c][d] == pawn) {
				checklista[num] = c;
				checklistb[num] = d;
				 num++;
            }
        }

	  string aa, bb, cc, dd;

        switch (num){
            case 0:
            freturn.clear();
            break;
            case 1:

            aa = chfile(ksqb);
            bb = chrank(ksqa);
            xa = checklista[0];
            xb = checklistb[0];
            cc = chfile(xb);
            dd = chrank(xa);
            freturn = aa + bb + cc + dd;

            break;
            default:
            aa = chfile(ksqb);
            bb = chrank(ksqa);
            xa = checklista[0];
            xb = checklistb[0];
            cc = chfile(xb);
            dd = chrank(xa);
            freturn = aa + bb + cc + dd;
            xa = checklista[1];
            xb = checklistb[1];
            cc = chfile(xb);
            dd = chrank(xa);
            freturn = freturn + cc + dd;
            break;

        }
    if (remva != 64) {
        board[remva][remvb] = repl;
    }
 return freturn;
 }

 //actual function, generates all possible animal moves for black in string format ie (R@a1) "a1a2" + "a1a3" etc
string blackmoves(int epa, int epb){	//epa is integer for en passant square file, epb is en passant square rank, together they make a coordinate
	string allmoves;
	int fromSQa[218];
	int fromSQb[218];
	int toSQa[218];
	int toSQb[218];

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int z = 0;
	string promotions;
	int i2;
	promotions = "qrbn";

	for (a = 0; a < 8; ++a){
		for (b = 0; b < 8; ++b){
			if(a == 7 && b == 0){
				//printboard();
			}
			switch (board[a][b]) {
				case -queen:		//generate animal moves for black queen (found on square where rank is a, file is b.)

						{
						for (e = -1; e <= 1; e++) {
						for (f = -1; f <= 1; f++) {
							c = a + e;
							d = b + f;
							if (!(e == 0 && f == 0)) {
								do {
									if (bounds(c, d)) {

										if (board[c][d] == 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
										if (board[c][d] > 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;

											z++;
											break;
										}
										if (board[c][d] < 0) break;
										c = c + e;
										d = d + f;
									}
								}
								while (!(bounds(c, d) == false));

							}

						}
					}

				break;

				case -rook:
					for (e = -1; e <= 1; e++) {
						for (f = -1; f <= 1; f++) {
							c = a + e;
							d = b + f;
							if (abs(e)+abs(f) == 1) {
								do {
									if (bounds(c, d)) {

										if (board[c][d] == 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
										if (board[c][d] > 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;

											z++;
											break;
										}
										if (board[c][d] < 0) break;
										c = c + e;
										d = d + f;
									}
								}
								while (!(bounds(c, d) == false));

							}

						}
					}
					break;
				case -bishop:
					for (e = -1; e <= 1; e++) {
						for (f = -1; f <= 1; f++) {
							c = a + e;
							d = b + f;
							if (abs(e)+abs(f) == 2) {
								do {
									if (bounds(c, d)) {

										if (board[c][d] == 0) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
									if (board[c][d] > 0) {
										fromSQa[z] = a; //toSQa[18]
										fromSQb[z] = b;
										toSQa[z] = c;
										toSQb[z] = d;

										z++;
										break;
									}
									if (board[c][d] < 0) break;

								}
							c = c + e;
							d = d + f;
							}
							while (bounds(c, d));
						}
					}
				}
				break;
				case -knight:
					for(e=-2; e<=2; e+=1){
						for(f=-2; f<=2; f+=1){
							c = a + e;
							d = b + f;
							if(abs(e) + abs(f) == 3){
								if(bounds(c,d)){
									if(board[c][d]>=0){
										fromSQa[z]=a;
										fromSQb[z]=b;
										toSQa[z]=c;
										toSQb[z]=d;
										z+=1;
									}
								}
							}
						}
					}
					break;
					case -pawn:
						//white pawn attack left and forward (forward from blacks perspective)
						c = a - 1;
						d = b + 1;
						if (bounds(c, d)) {

							if (board[c][d] > 0 || (epa == c && epb == d)) { //if diagonal square attacked contains a piece valued less than zero then capture is possible, or square is the en passant square from previous move.
								fromSQa[z] = a;
								fromSQb[z] = b;
								toSQa[z] = c;
								toSQb[z] = d;
								z++;
							}
						}
						//white pawn attack right and forward
						c = a - 1;
						d = b - 1;
						if (bounds(c, d)) {

							if (board[c][d] > 0 || (epa == c && epb == d)) {
								fromSQa[z] = a;
								fromSQb[z] = b;
								toSQa[z] = c;
								toSQb[z] = d;
								z++;
							}
						}
						//check if one square forward is unoccupied and add it to the movelist
							if (a == 6) {
								c = 5;
								d = b;
								if (bounds(c, d)) {

									if (board[c][d] == 0) {
										fromSQa[z] = a;
										fromSQb[z] = b;
										toSQa[z] = c;
										toSQb[z] = d;
										z++;
										//decrement the file for c, d (coordinates for move to testing)
										c = 4;
										d = b;
										//another square forward if the pawn is on it's starting rank
										if (bounds(c, d)) {

											if (board[c][d] == 0) {
												fromSQa[z] = a;
												fromSQb[z] = b;
												toSQa[z] = c;
												toSQb[z] = d;
												z++;
											}
										}
									}
								}
							}
						else {	//pawn is not on starting rank
							c = a - 1;
							d = b;
							if (bounds(c, d)) {
								if (board[c][d] == 0) {
									fromSQa[z] = a;
									fromSQb[z] = b;
									toSQa[z] = c;
									toSQb[z] = d;
									z++;
								}
							}
						}

					break;
					case -king:
						for (e = -1; e <= 1; e++) {
							for (f = -1; f <= 1; f++) {
								if (!(e == 0 && f == 0)) {
									c = a + e;
									d = b + f;

									if (bounds(c, d)) {		//checks if coordinates exist on the board

										if (board[c][d] >= 0 && checkblack(c, d, a, b).empty()) {
											fromSQa[z] = a;
											fromSQb[z] = b;
											toSQa[z] = c;
											toSQb[z] = d;
											z++;
										}
									}
								}
							}
						}
					//castleKingSide
						if (bkside && a == 7 && b == 4 && board[7][7] == -rook && board[7][6] == 0 && board[7][5] == 0) {
							if (checkblack(7, 4, 7, 4).empty() && checkblack(7, 5, 7, 4).empty() && checkblack(7, 6, 7, 4).empty()) {
								fromSQa[z] = 7;
								fromSQb[z] = 4;
								toSQa[z] = 7;
								toSQb[z] = 6;
								z++;
							}
						}

						//castleQueenSide
						if (bqside == true && a == 7 && b == 4 && board[7][0] == -rook && board[7][1] == 0 && board[7][2] == 0 && board[7][3] == 0) {
							if (checkblack(7, 4, 7, 4).empty() && checkblack(7, 3, 7, 4).empty() && checkblack(7, 2, 7, 4).empty()) {
								fromSQa[z] = 7;
								fromSQb[z] = 4;
								toSQa[z] = 7;
								toSQb[z] = 2;
								z++;
							}
						}
				} // close switch

			}


		}
	}
	//now all moves are checked to see if they leave the white king in check and if they do they are discarded from the list
	int i;
	int captured;
	int bksqa, bksqb;
	string addmove;

	for(a = 0; a <= 7; a++){
		for(b = 0; b <= 7; b++){
			if(board[a][b] == -king){
				bksqa = a;
				bksqb = b;
				goto kingfound;
			}
		}
	}
kingfound:

	bool epcapture;
	epcapture = false;

	for(i = 0; i < z; i++){
		a = fromSQa[i];
		b = fromSQb[i];
		c = toSQa[i];
		d = toSQb[i];
		if(!bounds(a, b) || !bounds(c, d)){

		}
		//perform the move
		captured = board[c][d];
		board[c][d] = board[a][b];
		board[a][b] = 0;

		if(board[c][d] == -pawn && (b != d) && (captured == 0) && bounds((c + 1), d)){
			board[c+1][d] = 0;
			epcapture = true;
		}

		//if the king is the piece moving wksqa and wksqb won't contain the coordinates of the king! c and d will
		if(board[c][d] == -king){
			if(checkblack(c, d, 64, 0).empty()){
				//add move to list, otherwise discard move (do nothing)
				addmove = chfile(b) + chrank(a) + chfile(d) + chrank(c);		//convert coordinates to ascii
				allmoves = allmoves + addmove;		//add to the movelist
			}
		}
		else{		//if the king is not the piece moving then the king is in the coordinates wksqa and wksqb, and we check that square for check, if it is check it is not added to the movelist (allmoves)
			string p2;
			p2 = checkblack(bksqa, bksqb, 64, 0);
			if(checkblack(bksqa, bksqb, 64, 0).empty()){
				//add move to list, otherwise discard move (do nothing)
				if(!(board[c][d] == -pawn && (c == 0))){		// if the move is not a pawn progressed to the 8th rank, then add move to the list, otherwise, pawn promotions and underpromotions must be added to the move list (each)
					addmove = chfile(b) + chrank(a) + chfile(d) + chrank(c);		//convert coordinates to ascii
					allmoves = allmoves + addmove;		//add to the movelist
				}
				else{
					for(i2 = 0; i2 < 4; i2++){
						addmove = chfile(b) + chrank(a) + chfile(d) + promotions.substr(i2,1);		//promotion is 4 characters the file the pawn starts on followed by the rank and file moving to (if capturing will be different) followed by either q for promote to queen, r for rook, n for knight and b for bishop.
						allmoves = allmoves + addmove;		//add to the movelist
					}
				}
			}
		}


		//undo the move
		board[a][b] = board[c][d];
		board[c][d] = captured;

		if (epcapture == true){
			board[c+1][d] = -pawn;
			epcapture = false;

		}

	}
	return allmoves;
}

int file2num(string f1){
int aa;
switch (f1[0]){
	case 'a':
	aa = 0;
	break;
	case 'b':
	aa = 1;
	break;
	case 'c':
	aa = 2;
	break;
	case 'd':
	aa = 3;
	break;
	case 'e':
	aa = 4;
	break;
	case 'f':
	aa = 5;
	break;
	case 'g':
	aa = 6;
	break;
	case 'h':
	aa = 7;
	break;
 }
return aa;
}

int rank2num(string f1){
int aa;
switch (f1[0]){
	case '1':
	aa = 0;
	break;
	case '2':
	aa = 1;
	break;
	case '3':
	aa = 2;
	break;
	case '4':
	aa = 3;
	break;
	case '5':
	aa = 4;
	break;
	case '6':
	aa = 5;
	break;
	case '7':
	aa = 6;
	break;
	case '8':
	aa = 7;
	break;
 }
return aa;
}

int char2promote(char a, string b){
int out1;
char aa;
aa = a;
switch (aa){
case 'q':
out1 = queen;
break;
case 'r':
out1 = rook;
break;
case 'b':
out1 = bishop;
break;
case 'n':
out1 = knight;
break;
}
if (b == "b") out1 *= -1;
return out1;
}

void printboard(void){
	using namespace std;
	int a, b;
	cout << "\n";
	for(a = 7; a >= 0; a--){
		for(b = 0; b <8; b++){
			cout << piece2char(board[a][b]);
		}
	cout << "\n";
	}

}

string piece2char(int piece){
	string boardstring;
	switch(piece){
		case king:
		boardstring = boardstring + "K";
		break;
		case -king:
		boardstring = boardstring + "k";
		break;
		case queen:
		boardstring = boardstring + "Q";
		break;
		case -queen:
		boardstring = boardstring + "q";
		break;
		case rook:
		boardstring = boardstring + "R";
		break;
		case -rook:
		boardstring = boardstring + "r";
		break;
		case 0:
		boardstring = boardstring + "-";
		break;
		case bishop:
		boardstring = boardstring + "B";
		break;
		case -bishop:
		boardstring = boardstring + "b";
		break;
		case knight:
		boardstring = boardstring + "N";
		break;
		case -knight:
		boardstring = boardstring + "n";
		break;
		case pawn:
		boardstring = boardstring + "P";
		break;
		case -pawn:
		boardstring = boardstring + "p";
		break;
	}
	return boardstring;
}

int alphabeta(int depth, int alpha, int beta, bool sidetomove){
    if(depth == 0) return evaluate();

    if(maximizingplayer){
        //for each white move branch
        //see wikipedia
    }
    else{
        //for each black move branch
    }

}

int evaluate(void){
    //evaluate position based on, material, positional center control, pawn structure etc...
}
