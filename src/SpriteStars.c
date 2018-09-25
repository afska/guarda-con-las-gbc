#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_STARS = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"

void Start_SPRITE_STARS() {
	THIS->current_frame = 1;
}

void Update_SPRITE_STARS() {}

void Destroy_SPRITE_STARS() {}
