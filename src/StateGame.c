#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Palette.h"
#include "Print.h"
#include "../res/src/font.h"

static UINT16 bg_palette[] = { PALETTE_FROM_HEADER(tiles) };

void Start_STATE_GAME() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	SetPalette(BG_PALETTE, 0, 8, (UINT16*) bg_palette, bank_STATE_GAME);

	INIT_CONSOLE(font, 3, 2);

	scroll_target = SpriteManagerAdd(SPRITE_HALU, 10, 100);
	InitScrollTiles(0, 12, tiles, 3);
	InitScroll(mapWidth, mapHeight, map, NULL, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAME() {
}