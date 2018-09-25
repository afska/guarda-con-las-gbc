#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(STATE_GAME) \
STATE_DEF_END

#define SPRITES \
_SPRITE_COLOR(SPRITE_HALU, halu, 3, FRAME_32x32, 2) \
_SPRITE_COLOR(SPRITE_STARS, stars, 3, FRAME_32x32, 2) \
_SPRITE_DMG(SPRITE_WORLD, world, 3, FRAME_8x8, 1) \
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#define $DATA ((struct Data*) THIS->custom_data)
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

#endif