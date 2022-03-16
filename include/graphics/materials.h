/**
 * @file materials.h
 * @author Alex "FaceFTW" Westerman
 * @brief Material Defines
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022. Work is based on original work from Microsoft Corp (c) 1994
 *
 */

/******** materials ********************************/

#ifndef __materials_h_
#define __materials_h_
#define NUM_TEA_MATERIALS 24

enum {
	EMERALD = 0,
	JADE,
	OBSIDIAN,
	PEARL,
	RUBY,
	TURQUOISE,
	BRASS,
	BRONZE,
	CHROME,
	COPPER,
	GOLD,
	SILVER,
	BLACK_PLASTIC,
	CYAN_PLASTIC,
	GREEN_PLASTIC,
	RED_PLASTIC,
	WHITE_PLASTIC,
	YELLOW_PLASTIC,
	BLACK_RUBBER,
	CYAN_RUBBER,
	GREEN_RUBBER,
	RED_RUBBER,
	WHITE_RUBBER,
	YELLOW_RUBBER
};

// 'white' materials, for texturing

#define NUM_TEX_MATERIALS 4

enum {
	BRIGHT_WHITE = NUM_TEA_MATERIALS,
	WHITE,
	WARM_WHITE,
	COOL_WHITE
};

#endif //__materials_h_