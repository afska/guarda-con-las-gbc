#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_HALU = 2;

#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Keys.h"

static UINT8 ANIM_IDLE[] = {1, 0};
static UINT8 ANIM_BLINKING[] = {1, 1};
static UINT8 JUMP_IMPULSE = 10;
static UINT8 JUMP_GRAVITY = 1;
static UINT8 BLINK_WAIT = 60;
static UINT8 BLINK_DURATION = 10;

static struct Data {
	UINT8 isPressingUp;
	UINT8 isJumping;
	UINT8 jumpStartY;
	INT8 velocityY;

	UINT8 blinkTimer;
};

static void blinkIfNeeded();
static void handleInput();
static void updateGravity();
static void checkCollisions();

void Start_SPRITE_HALU() {
	THIS->coll_x = 5;
	THIS->coll_y = 5;
	THIS->coll_w = 19;
	THIS->coll_h = 16;

	$DATA->isPressingUp = FALSE;
	$DATA->isJumping = FALSE;
	$DATA->jumpStartY = 0;
	$DATA->velocityY = 0;
	$DATA->blinkTimer = 0;
}

void Update_SPRITE_HALU() {
	blinkIfNeeded();
	handleInput();
	updateGravity();
	checkCollisions();
}

void Destroy_SPRITE_HALU() {
}

static void blinkIfNeeded() {
	$DATA->blinkTimer++;

	if ($DATA->blinkTimer >= BLINK_WAIT) SetSpriteAnim(THIS, (UINT8*) ANIM_BLINKING, 0);
	if ($DATA->blinkTimer >= BLINK_WAIT + BLINK_DURATION) {
		SetSpriteAnim(THIS, (UINT8*) ANIM_IDLE, 0);
		$DATA->blinkTimer = 0;
	}
}

static void handleInput() {
	if (KEY_PRESSED(J_A) && !$DATA->isPressingUp) $DATA->isPressingUp = TRUE;
	if (!KEY_PRESSED(J_A) && $DATA->isPressingUp) $DATA->isPressingUp = FALSE;

	if ($DATA->isPressingUp && !$DATA->isJumping) {
		$DATA->isJumping = TRUE;
		$DATA->jumpStartY = THIS->y;
		$DATA->velocityY = JUMP_IMPULSE;
	}
}

static void updateGravity() {
	if (!$DATA->isJumping) return;

	$DATA->velocityY -= JUMP_GRAVITY;

	TranslateSprite(THIS, 0, -$DATA->velocityY << delta_time);

	if (THIS->y >= $DATA->jumpStartY) {
		THIS->y = $DATA->jumpStartY;

		$DATA->isJumping = FALSE;
		$DATA->jumpStartY = 0;
		$DATA->velocityY = 0;
	}
}

static void checkCollisions() {
	UINT8 i = 0;
	struct Sprite* sprite;
	SPRITEMANAGER_ITERATE(i, sprite) {
		if (sprite->type == SPRITE_GBC) {
			if (CheckCollision(THIS, sprite)) {
				SetState(STATE_GAME);
			}
		}
	}
}