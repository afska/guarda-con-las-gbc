#pragma bank 2
#include "main.h"
UINT8 bank_SPRITE_ENEMY = 2;

#include "SpriteManager.h"

struct EnemyInfo {
	INT8 velocityY;
	INT8 velocityX;
};

const UINT8 anim_enemy_idle[] = {0, 1, 2, 3};

void Start_SPRITE_ENEMY() {
	/*struct EnemyInfo* data = (struct EnemyInfo*) THIS->custom_data;
	data->velocityX = 1;
	data->velocityY = 1;*/

	SetSpriteAnim(THIS, anim_enemy_idle, 15);
}

void Update_SPRITE_ENEMY() {
	/*struct EnemyInfo* data = (struct EnemyInfo*) THIS->custom_data;
	if (TranslateSprite(THIS, data->velocityX, data->velocityY)) {
		INT8 sx = rand() % 2 == 0 ? 1 : -1;
		INT8 sy = rand() % 2 == 0 ? 1 : -1;

		data->velocityX = data->velocityX * sx;
		data->velocityY = data->velocityY * sy;
	}*/
}

void Destroy_SPRITE_ENEMY() {
}