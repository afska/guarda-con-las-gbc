#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_HALU = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Keys.h"

static UINT8 ANIM_IDLE[] = {1, 0};
static UINT8 ANIM_BLINKING[] = {1, 1};
static UINT8 BLINK_WAIT = 60;
static UINT8 BLINK_DURATION = 10;

UINT8 blinkCounter = 0;

void Start_SPRITE_HALU() {
	THIS->coll_x = 2;
	THIS->coll_y = 2;
	THIS->coll_w = 11;
	THIS->coll_h = 14;
}

void Update_SPRITE_HALU() {
	blinkIfNeeded();

	if (KEY_PRESSED(J_UP)) TranslateSprite(THIS, 0, -1 << delta_time);

	if (KEY_PRESSED(J_DOWN)) TranslateSprite(THIS, 0, 1 << delta_time);

	if (KEY_PRESSED(J_LEFT)) TranslateSprite(THIS, -1 << delta_time, 0);

	if (KEY_PRESSED(J_RIGHT)) TranslateSprite(THIS, 1 << delta_time, 0);

	/*UINT8 i = 0;
	struct Sprite* sprite;
	SPRITEMANAGER_ITERATE(i, sprite) {
		if (sprite->type == SPRITE_ENEMY) {
			if (CheckCollision(THIS, sprite)) {
				SetState(STATE_GAME);
			}
		}
	}*/
}

void Destroy_SPRITE_HALU() {
}

static void blinkIfNeeded() {
	blinkCounter++;

	if (blinkCounter >= BLINK_WAIT) SetSpriteAnim(THIS, (UINT8*) ANIM_BLINKING, 0);
	if (blinkCounter >= BLINK_WAIT + BLINK_DURATION) {
		SetSpriteAnim(THIS, (UINT8*) ANIM_IDLE, 0);
		blinkCounter = 0;
	}
}