#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_WORLD = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Keys.h"

static UINT8 WALK_SPEED = 3;

static struct Data {
	struct Sprite* halu;
	struct Sprite* stars[2];
};

void Start_SPRITE_WORLD() {
	$DATA->halu = SpriteManagerAdd(SPRITE_HALU, 10, 100);

	$DATA->stars[0] = SpriteManagerAdd(SPRITE_STARS, 30, 10);
	$DATA->stars[0]->current_frame = 0;
	$DATA->stars[1] = SpriteManagerAdd(SPRITE_STARS, 100, 20);
	$DATA->stars[1]->current_frame = 1;
}

void Update_SPRITE_WORLD() {
	/*if (KEY_PRESSED(J_LEFT)) scrollBy(-WALK_SPEED);
	if (KEY_PRESSED(J_RIGHT)) scrollBy(WALK_SPEED);*/
}

void Destroy_SPRITE_WORLD() {
}

/*static void scrollBy(INT8 x) {
	TranslateSprite($DATA->stars[0], x << delta_time, 0);
	TranslateSprite($DATA->stars[1], x << delta_time, 0);
}*/