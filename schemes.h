#ifndef __SCHEMES_H__
#define __SCHEMES_H__

#include "viiper.h" /* for enum items */

#define BORDER_T 0
#define BORDER_C 1
#define BORDER_B 2
#define BORDER_S 3
#define BORDER_L 0
#define BORDER_R 2
//#define BORDER(v,h) op.sch->border[BORDER_ ## v][BORDER_ ## h]
#define BORDER(v,h) (g.b.t&1<<BONUS_WRAP?op.sch->permeable:op.sch->border) \
	[BORDER_ ## v][BORDER_ ## h]

struct scheme {
	char* border[4][3];
	char* permeable[4][3]; /* for wrap-around mode */

	char* snake[5][5]; /* [predecessor][successor] */
	char* color[3]; /* 0=even, 1=odd, 2=head */

	char* food[NUM_FOODS];
	char* boni[NUM_BONI];

	int cell_width; /* logical cell width */
	int display_width; /* physical cell width */
};

struct scheme unic0de = {
	.border = {
		{"╔", "══", "╗"},
		{"║", "  ", "║"},
		{"╚", "══", "╝"},
		{  "╡","","╞"  },
	},
	.permeable = {//┅╍
		{"┏", "╍╍", "┓"},
		{"┋", "  ", "┋"},
		{"┗", "╍╍", "┛"},
		{  "┥","","┝"  },
	},

	.snake = { /* sorted like in the enum directions */
	/*NOTE: same-to-same direction is for wrap-around*/
		{/* NONE -> */
			/*NONE */ "",
			/*NORTH*/ "⢿⡿",
			/*EAST */ "⢾⣿",
			/*SOUTH*/ "⣾⣷",
			/*WEST */ "⣿⡷",
		},{/* NORTH -> */
			/*NONE */ "⢇⡸",
			/*NORTH*/ "⢇⠜",
			/*EAST */ "⢇⣈",
			/*SOUTH*/ "⡇⢸",
			/*WEST */ "⣁⡸",
		},{/* EAST -> */
			/*NONE */ "⢎⣉",
			/*NORTH*/ "⢇⣈",
			/*EAST */ "⠪⣉",
			/*SOUTH*/ "⡎⢉",
			/*WEST */ "⣉⣉",
		},{/* SOUTH -> */
			/*NONE */ "⡎⢱",
			/*NORTH*/ "⡇⢸",
			/*EAST */ "⡎⢉",
			/*SOUTH*/ "⡔⢱",
			/*WEST */ "⡉⢱",
		},{/* WEST -> */
			/*NONE */ "⣉⡱",
			/*NORTH*/ "⣁⡸",
			/*EAST */ "⣉⣉",
			/*SOUTH*/ "⡉⢱",
			/*WEST */ "⣉⡢",
		},
	},
	.color = {"32", "92", "92;1"},

	.food = {
		[FOOD_5] = "🍐",
		[FOOD_10] = "🍎",
		[FOOD_20] = "🥑",
	},
	.boni = {
		[BONUS_SNIP] = "✂️ ",
		[BONUS_GROW] = "🐍",
		[BONUS_SLOW] = "🐌",
		[BONUS_FAST] = "🐇",
		[BONUS_WRAP] = "🧱",
	},

	.cell_width = 2,
	.display_width = 2,
};

#endif
