#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"
#include "..\res\src\stars.h"
#include "..\res\src\world.h"
#include "..\res\src\halu.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"

#include "Print.h"
#include "../res/src/font.h"

#include "Palette.h"

static UINT16 PALETTE_TILES[] = {PALETTE_FROM_HEADER(tiles)};
static UINT16 PALETTE_SPRITES[] = { 
	PALETTE_INDEX(halu, 0),
	PALETTE_INDEX(stars, 1),
	PALETTE_INDEX(halu, 2),
	PALETTE_INDEX(halu, 3),
	PALETTE_INDEX(halu, 4),
	PALETTE_INDEX(halu, 5),
	PALETTE_INDEX(halu, 6),
	PALETTE_INDEX(halu, 7)
};

void Start_STATE_GAME() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != N_SPRITE_TYPES; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	SetPalette(BG_PALETTE, 0, 8, (UINT16*) PALETTE_TILES, bank_STATE_GAME);
	SetPalette(SPRITES_PALETTE, 0, 8, (UINT16*) PALETTE_SPRITES, bank_STATE_GAME);

	INIT_CONSOLE(font, 3, 2);

	SpriteManagerAdd(SPRITE_WORLD, 0, 0);
	InitScrollTiles(0, 4, tiles, 3);
	InitScroll(mapWidth, mapHeight, map, NULL, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAME() {
}