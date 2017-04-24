#include <SDL/SDL.h>

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
int CLIP_ROOK_UPGRADE = 13;
int CLIP_BISHOP_UPGRADE= 14;
int CLIP_KNIGHT_UPGRADE = 15;
int CLIP_QUEEN_UPGRADE = 16;
int CLIP_KING_UPGRADE = 17;

int CLIP_PAWN_UPGRADE_SELECT = 18;
int CLIP_ROOK_UPGRADE_SELECT = 19;
int CLIP_BISHOP_UPGRADE_SELECT = 20;
int CLIP_KNIGHT_UPGRADE_SELECT = 21;
int CLIP_QUEEN_UPGRADE_SELECT = 22;
int CLIP_KING_UPGRADE_SELECT = 23;

int SPRITE_SIZE = 64;
int BORDER_SIZE = 0;

void util_set_clips(SDL_Rect clips [])
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

  clips[CLIP_ROOK_UPGRADE].x = SPRITE_SIZE;
  clips[CLIP_ROOK_UPGRADE].y = SPRITE_SIZE*2;
  clips[CLIP_ROOK_UPGRADE].w = SPRITE_SIZE;
  clips[CLIP_ROOK_UPGRADE].h = SPRITE_SIZE;

  clips[CLIP_ROOK_UPGRADE_SELECT].x = SPRITE_SIZE;
  clips[CLIP_ROOK_UPGRADE_SELECT].y = SPRITE_SIZE*3;
  clips[CLIP_ROOK_UPGRADE_SELECT].w = SPRITE_SIZE;
  clips[CLIP_ROOK_UPGRADE_SELECT].h = SPRITE_SIZE;

  //clip range for the bishop
  clips[CLIP_BISHOP].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP].y = 0;
  clips[CLIP_BISHOP].w = SPRITE_SIZE;
  clips[CLIP_BISHOP].h = SPRITE_SIZE;

  clips[CLIP_BISHOP_SELECT].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP_SELECT].y = SPRITE_SIZE;
  clips[CLIP_BISHOP_SELECT].w = SPRITE_SIZE;
  clips[CLIP_BISHOP_SELECT].h = SPRITE_SIZE;

  clips[CLIP_BISHOP_UPGRADE].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP_UPGRADE].y = SPRITE_SIZE*2;
  clips[CLIP_BISHOP_UPGRADE].w = SPRITE_SIZE;
  clips[CLIP_BISHOP_UPGRADE].h = SPRITE_SIZE;

  clips[CLIP_BISHOP_UPGRADE_SELECT].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP_UPGRADE_SELECT].y = SPRITE_SIZE*3;
  clips[CLIP_BISHOP_UPGRADE_SELECT].w = SPRITE_SIZE;
  clips[CLIP_BISHOP_UPGRADE_SELECT].h = SPRITE_SIZE;

  //clip range for the knight
  clips[CLIP_KNIGHT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT].y = 0;
  clips[CLIP_KNIGHT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT].h = SPRITE_SIZE;

  clips[CLIP_KNIGHT_SELECT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT_SELECT].y = SPRITE_SIZE;
  clips[CLIP_KNIGHT_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT_SELECT].h = SPRITE_SIZE;

  clips[CLIP_KNIGHT_UPGRADE].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT_UPGRADE].y = SPRITE_SIZE*2;
  clips[CLIP_KNIGHT_UPGRADE].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT_UPGRADE].h = SPRITE_SIZE;

  clips[CLIP_KNIGHT_UPGRADE_SELECT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT_UPGRADE_SELECT].y = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT_UPGRADE_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT_UPGRADE_SELECT].h = SPRITE_SIZE;

  //clip range for the queen
  clips[CLIP_QUEEN].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN].y = 0;
  clips[CLIP_QUEEN].w = SPRITE_SIZE;
  clips[CLIP_QUEEN].h = SPRITE_SIZE;

  clips[CLIP_QUEEN_SELECT].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN_SELECT].y = SPRITE_SIZE;
  clips[CLIP_QUEEN_SELECT].w = SPRITE_SIZE;
  clips[CLIP_QUEEN_SELECT].h = SPRITE_SIZE;

  clips[CLIP_QUEEN_UPGRADE].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN_UPGRADE].y = SPRITE_SIZE*2;
  clips[CLIP_QUEEN_UPGRADE].w = SPRITE_SIZE;
  clips[CLIP_QUEEN_UPGRADE].h = SPRITE_SIZE;

  clips[CLIP_QUEEN_UPGRADE_SELECT].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN_UPGRADE_SELECT].y = SPRITE_SIZE*3;
  clips[CLIP_QUEEN_UPGRADE_SELECT].w = SPRITE_SIZE;
  clips[CLIP_QUEEN_UPGRADE_SELECT].h = SPRITE_SIZE;

  //clip range for the king
  clips[CLIP_KING].x = SPRITE_SIZE*5;
  clips[CLIP_KING].y = 0;
  clips[CLIP_KING].w = SPRITE_SIZE;
  clips[CLIP_KING].h = SPRITE_SIZE;

  clips[CLIP_KING_SELECT].x = SPRITE_SIZE*5;
  clips[CLIP_KING_SELECT].y = SPRITE_SIZE;
  clips[CLIP_KING_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KING_SELECT].h = SPRITE_SIZE;

  clips[CLIP_KING_UPGRADE].x = SPRITE_SIZE*5;
  clips[CLIP_KING_UPGRADE].y = SPRITE_SIZE*2;
  clips[CLIP_KING_UPGRADE].w = SPRITE_SIZE;
  clips[CLIP_KING_UPGRADE].h = SPRITE_SIZE;

  clips[CLIP_KING_UPGRADE_SELECT].x = SPRITE_SIZE*5;
  clips[CLIP_KING_UPGRADE_SELECT].y = SPRITE_SIZE*3;
  clips[CLIP_KING_UPGRADE_SELECT].w = SPRITE_SIZE;
  clips[CLIP_KING_UPGRADE_SELECT].h = SPRITE_SIZE;

  //clip range for extra piece images
  clips[24].x = SPRITE_SIZE*0;
  clips[24].y = SPRITE_SIZE*4;
  clips[24].w = SPRITE_SIZE;
  clips[24].h = SPRITE_SIZE;
 
  clips[25].x = SPRITE_SIZE*1;
  clips[25].y = SPRITE_SIZE*4;
  clips[25].w = SPRITE_SIZE;
  clips[25].h = SPRITE_SIZE;
 
  clips[26].x = SPRITE_SIZE*2;
  clips[26].y = SPRITE_SIZE*4;
  clips[26].w = SPRITE_SIZE;
  clips[26].h = SPRITE_SIZE;
 
  clips[27].x = SPRITE_SIZE*3;
  clips[27].y = SPRITE_SIZE*4;
  clips[27].w = SPRITE_SIZE;
  clips[27].h = SPRITE_SIZE;
 
  clips[28].x = SPRITE_SIZE*4;
  clips[28].y = SPRITE_SIZE*4;
  clips[28].w = SPRITE_SIZE;
  clips[28].h = SPRITE_SIZE;
 
  clips[29].x = SPRITE_SIZE*5;
  clips[29].y = SPRITE_SIZE*4;
  clips[29].w = SPRITE_SIZE;
  clips[29].h = SPRITE_SIZE;

  //Extra row 2
  clips[30].x = SPRITE_SIZE*0;
  clips[30].y = SPRITE_SIZE*5;
  clips[30].w = SPRITE_SIZE;
  clips[30].h = SPRITE_SIZE;
 
  clips[31].x = SPRITE_SIZE*1;
  clips[31].y = SPRITE_SIZE*5;
  clips[31].w = SPRITE_SIZE;
  clips[31].h = SPRITE_SIZE;
 
  clips[32].x = SPRITE_SIZE*2;
  clips[32].y = SPRITE_SIZE*5;
  clips[32].w = SPRITE_SIZE;
  clips[32].h = SPRITE_SIZE;
 
  clips[33].x = SPRITE_SIZE*3;
  clips[33].y = SPRITE_SIZE*5;
  clips[33].w = SPRITE_SIZE;
  clips[33].h = SPRITE_SIZE;
 
  clips[34].x = SPRITE_SIZE*4;
  clips[34].y = SPRITE_SIZE*5;
  clips[34].w = SPRITE_SIZE;
  clips[34].h = SPRITE_SIZE;
 
  clips[35].x = SPRITE_SIZE*5;
  clips[35].y = SPRITE_SIZE*5;
  clips[35].w = SPRITE_SIZE;
  clips[35].h = SPRITE_SIZE;
  
  //Extra row 3
  clips[36].x = SPRITE_SIZE*0;
  clips[36].y = SPRITE_SIZE*5;
  clips[36].w = SPRITE_SIZE;
  clips[36].h = SPRITE_SIZE;
 
  clips[37].x = SPRITE_SIZE*1;
  clips[37].y = SPRITE_SIZE*5;
  clips[37].w = SPRITE_SIZE;
  clips[37].h = SPRITE_SIZE;
 
  clips[38].x = SPRITE_SIZE*2;
  clips[38].y = SPRITE_SIZE*5;
  clips[38].w = SPRITE_SIZE;
  clips[38].h = SPRITE_SIZE;
 
  clips[39].x = SPRITE_SIZE*3;
  clips[39].y = SPRITE_SIZE*5;
  clips[39].w = SPRITE_SIZE;
  clips[39].h = SPRITE_SIZE;
 
  clips[40].x = SPRITE_SIZE*4;
  clips[40].y = SPRITE_SIZE*5;
  clips[40].w = SPRITE_SIZE;
  clips[40].h = SPRITE_SIZE;
 
  clips[41].x = SPRITE_SIZE*5;
  clips[41].y = SPRITE_SIZE*5;
  clips[41].w = SPRITE_SIZE;
  clips[41].h = SPRITE_SIZE;

  //Extra row 4
  clips[42].x = SPRITE_SIZE*0;
  clips[42].y = SPRITE_SIZE*6;
  clips[42].w = SPRITE_SIZE;
  clips[42].h = SPRITE_SIZE;
 
  clips[43].x = SPRITE_SIZE*1;
  clips[43].y = SPRITE_SIZE*6;
  clips[43].w = SPRITE_SIZE;
  clips[43].h = SPRITE_SIZE;
 
  clips[44].x = SPRITE_SIZE*2;
  clips[44].y = SPRITE_SIZE*6;
  clips[44].w = SPRITE_SIZE;
  clips[44].h = SPRITE_SIZE;
 
  clips[45].x = SPRITE_SIZE*3;
  clips[45].y = SPRITE_SIZE*6;
  clips[45].w = SPRITE_SIZE;
  clips[45].h = SPRITE_SIZE;
 
  clips[46].x = SPRITE_SIZE*4;
  clips[46].y = SPRITE_SIZE*6;
  clips[46].w = SPRITE_SIZE;
  clips[46].h = SPRITE_SIZE;
 
  clips[47].x = SPRITE_SIZE*5;
  clips[47].y = SPRITE_SIZE*6;
  clips[47].w = SPRITE_SIZE;
  clips[47].h = SPRITE_SIZE;
}
