#include <gb/gb.h>
#include <stdio.h>


#include "cursor_tiles.h"
#include "cards_tiles.h"


typedef struct Card {
	UINT8 x, y;
	UINT8 left, right;
	UINT8 nb;
	UBYTE selected;
} Card;

typedef struct Cursor {
	UINT8 x, y;
	UINT8 left, right;
	INT8 nb;
} Cursor;


INT8 bounds(Cursor *c);
void select(Cursor *c);
void show_selected(Cursor *c, Card cardarray[]);

// make extern variables and use extern to access in functions
//UINT8 posx[] = {56, 72, 88};
//UINT8 posy[] = {48, 64, 80};

Card one, two, three, four, five, six, seven, eight;
Cursor cursor;

UINT8 posx[] = {56, 72, 88};
UINT8 posy[] = {48, 64, 80};


void main() {

	// put in init() function

	//cursor.x = posx[0];
	//cursor.right = posy[0];
	//cursor.left = 0;
	//cursor.right = 1;
	//cursor.nb = 0;

	one.x = posx[0];
	one.y = posy[0];
	one.left = 0;
	one.right = 1;
	one.nb = 1;
	one.selected = 0;

	two.x = posx[1];
	two.y = posy[0];
	two.left = 2;
	two.right = 3;
	two.nb = 2;
	two.selected = 0;

	three.x = posx[2];
	three.y = posy[0];
	three.left = 4;
	three.right = 5;
	three.nb = 3;
	three.selected = 0;

	four.x = posx[0];
	four.y = posy[1];
	four.left = 6;
	four.right = 7;
	four.nb = 4;
	four.selected = 0;

	five.x = posx[1];
	five.y = posy[1];
	five.left = 8;
	five.right = 9;
	five.nb = 5;
	five.selected = 0;

	six.x = posx[2];
	six.y = posy[1];
	six.left = 10;
	six.right = 11;
	six.nb = 6;
	six.selected = 0;

	seven.x = posx[0];
	seven.y = posy[2];
	seven.left = 12;
	seven.right = 13;
	seven.nb = 7;
	seven.selected = 0;

	eight.x = posx[1];
	eight.y = posy[2];
	eight.left = 14;
	eight.right = 15;
	eight.nb = 8;
	eight.selected = 0;

	cursor.x = posx[2];
	cursor.y = posy[2];
	cursor.left = 16;
	cursor.right = 17;
	cursor.nb = 9;

	
	SPRITES_8x16;
	//set_sprite_data(0, 4, cursor_data);
	//set_sprite_tile(cursor.left, 0);
	//move_sprite(cursor.left, cursor.x, cursor.y);
	//set_sprite_tile(cursor.right, 2);
	//move_sprite(cursor.right, cursor.x + 8, cursor.y);

	set_sprite_data(0, 32, cards_data);

	// one
	set_sprite_tile(one.left, 0);
	move_sprite(one.left, one.x, one.y);
	set_sprite_tile(one.right, 2);
	move_sprite(one.right, one.x + 8, one.y);

	// two
	set_sprite_tile(two.left, 4);
	move_sprite(two.left, two.x, two.y);
	set_sprite_tile(two.right, 6);
	move_sprite(two.right, two.x + 8, two.y);

	// three
	set_sprite_tile(three.left, 8);
	move_sprite(three.left, three.x, three.y);
	set_sprite_tile(three.right, 10);
	move_sprite(three.right, three.x + 8, three.y);

	// four
	set_sprite_tile(four.left, 12);
	move_sprite(four.left, four.x, four.y);
	set_sprite_tile(four.right, 14);
	move_sprite(four.right, four.x + 8, four.y);

	// five
	set_sprite_tile(five.left, 16);
	move_sprite(five.left, five.x, five.y);
	set_sprite_tile(five.right, 18);
	move_sprite(five.right, five.x + 8, five.y);

	// six
	set_sprite_tile(six.left, 20);
	move_sprite(six.left, six.x, six.y);
	set_sprite_tile(six.right, 22);
	move_sprite(six.right, six.x + 8, six.y);

	// seven
	set_sprite_tile(seven.left, 24);
	move_sprite(seven.left, seven.x, seven.y);
	set_sprite_tile(seven.right, 26);
	move_sprite(seven.right, seven.x + 8, seven.y);

	// eight
	set_sprite_tile(eight.left, 28);
	move_sprite(eight.left, eight.x, eight.y);
	set_sprite_tile(eight.right, 30);
	move_sprite(eight.right, eight.x + 8, eight.y);

	// cursor
	set_sprite_data(32, 4, cursor_data);
	set_sprite_tile(cursor.left, 32);
	move_sprite(cursor.left, cursor.x, cursor.y);
	set_sprite_tile(cursor.right, 34);
	move_sprite(cursor.right, cursor.x + 8, cursor.y);
	
	SHOW_SPRITES;
	// end init() function 

	while(1) {
		select(&cursor);
	}
}


INT8 bounds(Cursor *c) {
	UINT8 posx[] = {56, 72, 88};
	UINT8 posy[] = {48, 64, 80};

	if (c->x == posx[0] && c->y == posy[0]) {
		return 1;
	}
	else if (c->x == posx[1] && c->y == posy[0]) {
		return 2;
	}
	else if (c->x == posx[2] && c->y == posy[0]) {
		return 3;
	}
	else if (c->x == posx[0] && c->y == posy[1]) {
		return 4;
	}
	else if (c->x == posx[1] && c->y == posy[1]) {
		return 5;
	}
	else if (c->x == posx[2] && c->y == posy[1]) {
		return 9;
	}
	else if (c->x == posx[0] && c->y == posy[2]) {
		return 7;
	}
	else if (c->x == posx[1] && c->y == posy[2]) {
		return 8;
	}
	else if (c->x == posx[2] && c->y == posy[2]) {
		return 9;
	}
	
	return -1;
}

void select(Cursor *c) {
	INT8 selected;
	switch (joypad()) {
		case J_UP:
			c->y -= 16;
			selected = bounds(c);

			if (selected == -1) {
				c->y += 16;
				break;
			}
			else {
				move_sprite(c->left, c->x, c->y);
				move_sprite(c->right, c->x + 8, c->y);
				c->nb = selected;
			}

			delay(100);
			break;

		case J_DOWN:
			c->y += 16;
			selected = bounds(c);
			
			if (selected == -1) {
				c->y -= 16;
				break;
			}
			else {
				move_sprite(c->left, c->x, c->y);
				move_sprite(c->right, c->x + 8, c->y);
				c->nb = selected;
			}

			delay(100);
			break;

		case J_LEFT:
			c->x -= 16;
			selected = bounds(c);

			if (selected == -1) {
				c->x += 16;
				break;
			}
			else {
				move_sprite(c->left, c->x, c->y);
				move_sprite(c->right, c->x + 8, c->y);
				c->nb = selected;
			}

			delay(100);
			break;

		case J_RIGHT:
			c->x += 16;
			selected = bounds(c);

			if (selected == -1) {
				c->x -= 16;
				break;
			}
			else {
				move_sprite(c->left, c->x, c->y);
				move_sprite(c->right, c->x + 8, c->y);
				c->nb = selected;
				
			}

			delay(100);
			break;
	
		default:
			break;
	}
}



