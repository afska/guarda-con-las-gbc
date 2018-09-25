#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_WORLD = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Keys.h"

static UINT8 INITIAL_WALK_SPEED = 3;
static UINT8 PLAYER_X = 10;
static UINT8 PLAYER_Y = 100;
static UINT8 STAR1_X = 30;
static UINT8 STAR2_X = 100;
static UINT8 STARS_RESPAWN_MARGIN = 10;
static UINT8 WIDTH = 160;

static struct Data {
	struct Sprite* halu;
	struct Sprite* stars[2];

	UINT8 walkSpeed;
};

static void scrollBy(INT8 x);

void Start_SPRITE_WORLD() {
	$DATA->halu = SpriteManagerAdd(SPRITE_HALU, PLAYER_X, PLAYER_Y);

	$DATA->stars[0] = SpriteManagerAdd(SPRITE_STARS, STAR1_X, 10);
	$DATA->stars[0]->current_frame = 0;
	$DATA->stars[1] = SpriteManagerAdd(SPRITE_STARS, STAR2_X, 20);
	$DATA->stars[1]->current_frame = 1;

	$DATA->walkSpeed = INITIAL_WALK_SPEED;
}

void Update_SPRITE_WORLD() {
	scrollBy($DATA->walkSpeed);
}

void Destroy_SPRITE_WORLD() {
}

static void scrollBy(INT8 x) {
	$DATA->stars[0]->x = MIN(MAX($DATA->stars[0]->x - x, 0), WIDTH);
	$DATA->stars[1]->x = MIN(MAX($DATA->stars[1]->x - x, 0), WIDTH);

	if ($DATA->stars[0]->x <= 1) $DATA->stars[0]->x = WIDTH - STARS_RESPAWN_MARGIN;
	if ($DATA->stars[1]->x <= 1) $DATA->stars[1]->x = WIDTH - STARS_RESPAWN_MARGIN;
}
