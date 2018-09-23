#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_PLAYER = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Keys.h"

UINT8 anim_player_idle[] = {2, 0, 1};
UINT8 anim_player_walk[] = {2, 2, 3};
UINT8 i;
struct Sprite* sprite;

void Start_SPRITE_PLAYER() {
	THIS->coll_x = 2;
	THIS->coll_y = 2;
	THIS->coll_w = 11;
	THIS->coll_h = 14;
}

void Update_SPRITE_PLAYER() {
	if (KEY_PRESSED(J_UP)) {
		TranslateSprite(THIS, 0, -1);
		SetSpriteAnim(THIS, (UINT8*) anim_player_walk, 15);
	}

	if (KEY_PRESSED(J_DOWN)) {
		TranslateSprite(THIS, 0, 1);
		SetSpriteAnim(THIS, (UINT8*) anim_player_walk, 15);
	}

	if (KEY_PRESSED(J_LEFT)) {
		TranslateSprite(THIS, -1, 0);
		SetSpriteAnim(THIS, (UINT8*) anim_player_walk, 15);
	}

	if (KEY_PRESSED(J_RIGHT)) {
		TranslateSprite(THIS, 1, 0);
		SetSpriteAnim(THIS, (UINT8*) anim_player_walk, 15);
	}

	if (keys == 0) {
		SetSpriteAnim(THIS, (UINT8*) anim_player_idle, 15);
	}

	SPRITEMANAGER_ITERATE(i, sprite) {
		if (sprite->type == SPRITE_ENEMY) {
			if (CheckCollision(THIS, sprite)) {
				SetState(STATE_GAME);
			}
		}
	}
}

void Destroy_SPRITE_PLAYER() {
}