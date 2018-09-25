#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_GBC = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"

void Start_SPRITE_GBC() {}

void Update_SPRITE_GBC() {
	TranslateSprite(THIS, -((struct GbcSpeed*) THIS->custom_data)->speed << delta_time, 0);
}

void Destroy_SPRITE_GBC() {}
