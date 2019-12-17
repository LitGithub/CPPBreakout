#include "Brick.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
Brick::Brick() {
	xPos = 0;
	yPos = 0;
	width = 0;
	height = 0;
	Dead = 0;
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
}

void Brick::initBrick(int x, int y) {
	xPos = x;
	yPos = y;
	height = 30;
	width = 100;
}

void Brick::draw() {
	if(!Dead)
	al_draw_filled_rectangle(xPos, yPos, xPos + width, yPos + height, al_map_rgb(r, g, b));
}

bool Brick::isDead() {
	return Dead;
}

void Brick::killBrick() {
	Dead = 1;
}

bool Brick::collision(int x1, int y1) {
	if (!Dead) {
		if ((x1 + 30 > xPos) && (x1 < xPos + width) && (y1 + 30 > yPos) && (y1 < yPos + height))
			return true;
		else
			return false;
	}
	else
		return false;
};