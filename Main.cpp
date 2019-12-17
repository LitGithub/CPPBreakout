#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include <iostream>
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include <ctime>
using namespace std;

int stage = 0;
int red = 255;
int green = 0;
int blue = 0;
const char* scores[32] = {"0", "100", "200", "300", "400", "500", "600", "700", "800", "900", "1000", "1100", "1200", "1300", "1400", "1500", "1600", "1700", "1800", "1900", "2000", "2100", "2200", "2300", "2400", "2500", "2600", "2700", "2800", "2900", "3000", "MAX: 3000" };
void rainbow();
bool collision(int x1, int y1, int x2, int y2);
int main() {
	srand(time(NULL));
	//init allegro stuff
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	//allegro display / timer
	ALLEGRO_DISPLAY* display = al_create_display(530, 500);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_FONT* minecraft = al_load_ttf_font("Minecraft.ttf", 50, NULL);
	al_start_timer(timer);

	enum MYKEYS {
		KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_W, KEY_S
	};

	Ball PongBall(0, 255, 255, 250, 250);
	Paddle paddle1(255, 255, 255, 200, 470);
	int score = 0;
	bool key[6] = { false, false, false, false };
	bool redraw = true;
	Brick b1 ;
	Brick b2 ;
	Brick b3 ;
	Brick b4 ;
	Brick b5 ;
	Brick b6 ;
	Brick b7 ;
	Brick b8 ;
	Brick b9 ;
	Brick b10;
	Brick b11;
	Brick b12;
	Brick b13;
	Brick b14;
	Brick b15;
	Brick b16;
	Brick b17;
	Brick b18;
	Brick b19;
	Brick b20;
	Brick b21;
	Brick b22;
	Brick b23;
	Brick b24;
	Brick b25;
	Brick b26;
	Brick b27;
	Brick b28;
	Brick b29;
	Brick b30;
	b1 .initBrick(5, 5);
	b2 .initBrick(110, 5);
	b3 .initBrick(215, 5);
	b4 .initBrick(320, 5);
	b5 .initBrick(425, 5);

	b6 .initBrick(5, 40);
	b7 .initBrick(110, 40);
	b8 .initBrick(215, 40);
	b9 .initBrick(320, 40);
	b10.initBrick(425, 40);

	b11.initBrick(5, 75);
	b12.initBrick(110, 75);
	b13.initBrick(215, 75);
	b14.initBrick(320, 75);
	b15.initBrick(425, 75);

	b16.initBrick(5, 110);
	b17.initBrick(110, 110);
	b18.initBrick(215, 110);
	b19.initBrick(320, 110);
	b20.initBrick(425, 110);
	
	b21.initBrick(5, 145);
	b22.initBrick(110, 145);
	b23.initBrick(215, 145);
	b24.initBrick(320, 145);
	b25.initBrick(425, 145);
	
	b26.initBrick(5, 180);
	b27.initBrick(110, 180);
	b28.initBrick(215, 180);
	b29.initBrick(320, 180);
	b30.initBrick(425, 180);

	//ball thingy
	double xpos = PongBall.getX();
	double ypos = PongBall.getY();
	double vx = PongBall.getXVel();
	double vy = PongBall.getYVel();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (1) {
		//gets keyboard input
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (xpos < 0) {
			vx *= -1;
		}

		if (xpos + 30 > 530) {
			vx *= -1;
		}
		if (ypos <= 0)
			vy *= -1;

		if (ypos + 30 >= 500)
			vy *= -1;

		if (collision(xpos, ypos, paddle1.getX(), paddle1.getY())) {
			vy *= -1;
		}

		if(b1.collision(xpos, ypos)){
			b1.killBrick(); vy *= -1; score+= 100;
		}
		if(b2 .collision(xpos, ypos)){
		b2.killBrick(); vy *= -1; score+= 100;
		}
		if(b3 .collision(xpos, ypos)){
		b3.killBrick(); vy *= -1; score+= 100;
		}
		if(b4 .collision(xpos, ypos)){
		b4.killBrick(); vy *= -1; score+= 100;
		}
		if(b5 .collision(xpos, ypos)){
		b5.killBrick(); vy *= -1; score+= 100;
		}
		if(b6 .collision(xpos, ypos)){
		b6.killBrick(); vy *= -1; score+= 100;
		}
		if(b7 .collision(xpos, ypos)){
		b7.killBrick(); vy *= -1; score+= 100;
		}
		if(b8 .collision(xpos, ypos)){
		b8.killBrick(); vy *= -1; score+= 100;
		}
		if(b9 .collision(xpos, ypos)){
		b9.killBrick(); vy *= -1; score+= 100;
		}
		if(b10.collision(xpos, ypos)){
		b10.killBrick(); vy *= -1; score+= 100;
		}
		if(b11.collision(xpos, ypos)){
		b11.killBrick(); vy *= -1; score+= 100;
		}
		if(b12.collision(xpos, ypos)){
		b12.killBrick(); vy *= -1; score+= 100;
		}
		if(b13.collision(xpos, ypos)){
		b13.killBrick(); vy *= -1; score+= 100;
		}
		if(b14.collision(xpos, ypos)){
		b14.killBrick(); vy *= -1; score+= 100;
		}
		if(b15.collision(xpos, ypos)){
		b15.killBrick(); vy *= -1; score+= 100;
		}
		if(b16.collision(xpos, ypos)){
		b16.killBrick(); vy *= -1; score+= 100;
		}
		if(b17.collision(xpos, ypos)){
		b17.killBrick(); vy *= -1; score+= 100;
		}
		if(b18.collision(xpos, ypos)){
		b18.killBrick(); vy *= -1; score+= 100;
		}
		if(b19.collision(xpos, ypos)){
		b19.killBrick(); vy *= -1; score+= 100;
		}
		if(b20.collision(xpos, ypos)){
		b20.killBrick(); vy *= -1; score+= 100;
		}
		if(b21.collision(xpos, ypos)){
		b21.killBrick(); vy *= -1; score+= 100;
		}
		if(b22.collision(xpos, ypos)){
		b22.killBrick(); vy *= -1; score+= 100;
		}
		if(b23.collision(xpos, ypos)){
		b23.killBrick(); vy *= -1; score+= 100;
		}
		if(b24.collision(xpos, ypos)){
		b24.killBrick(); vy *= -1; score+= 100;
		}
		if(b25.collision(xpos, ypos)){
		b25.killBrick(); vy *= -1; score+= 100;
		}
		if(b26.collision(xpos, ypos)){
		b26.killBrick(); vy *= -1; score+= 100;
		}
		if(b27.collision(xpos, ypos)){
		b27.killBrick(); vy *= -1; score+= 100;
		}
		if(b28.collision(xpos, ypos)){
		b28.killBrick(); vy *= -1; score+= 100;
		}
		if(b29.collision(xpos, ypos)){
		b29.killBrick(); vy *= -1; score+= 100;
		}
		if(b30.collision(xpos, ypos)){
		b30.killBrick(); vy *= -1; score+= 100;
		}

				
				
		xpos += vx;
		ypos += vy;

		PongBall.setYVel(vy);
		PongBall.setXVel(vx);
		PongBall.setY(ypos);
		PongBall.setX(xpos);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			rainbow();
			paddle1.setColor(red, green, blue);
			PongBall.setColor(red, green, blue);
			//move player 4 pixels in a direction when key is pressed

			if (key[KEY_LEFT] && paddle1.getX() != 0) {
				paddle1.setX(paddle1.getX() - 5.0);
			}

			if (key[KEY_RIGHT] && paddle1.getX() + 100 != 530) {
				paddle1.setX(paddle1.getX() + 5.0);
			}

			redraw = true;
		}

		//keyboard and screen sections//////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_W:
				key[KEY_W] = true;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_W:
				key[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:

				break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			paddle1.draw();				
			al_draw_text(minecraft, al_map_rgb(255, 255, 255), 0, 400, NULL, ((score / 100) < 30) ? scores[score / 100] : scores[31]);
			PongBall.draw();				 
			b1 .draw();						 
			b2 .draw();						 
			b3 .draw();						 
			b4 .draw();						 
			b5 .draw();						 
			b6 .draw();						 
			b7 .draw();						 
			b8 .draw();						 
			b9 .draw();						 
			b10.draw();						 
			b11.draw();						 
			b12.draw();						 
			b13.draw();						 
			b14.draw();						 
			b15.draw();						 
			b16.draw();						 
			b17.draw();						 
			b18.draw();						 
			b19.draw();						 
			b20.draw();						 
			b21.draw();						 
			b22.draw();						 
			b23.draw();						 
			b24.draw();						 
			b25.draw();						 
			b26.draw();						 
			b27.draw();						 
			b28.draw();						 
			b29.draw();						 
			b30.draw();			
			al_flip_display();				 
		}//end render

	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}


void rainbow() {
	switch (stage) {
	case 0: // blue up
		blue++;
		if (blue >= 255)
			stage++;
		break;
	case 1: // red down
		red--;
		if (red == 0)
			stage++;
		break;
	case 2: // green up
		green++;
		if (green >= 255)
			stage++;
		break;
	case 3: // blue down
		blue--;
		if (blue == 0)
			stage++;
		break;
	case 4: // red up
		red++;
		if (red >= 255)
			stage++;
		break; // green removal
	case 5:
		green--;
		if (green == 0)
			stage++;
		break;
	case 6: // blue and green increase
		if (blue != 255)
			blue++;
		if (green != 255)
			green++;
		if (red == 255 && blue == 255 && green == 255)
			stage++;
		break;
	case 7: // rgb decrease
		if (red != 0)
			red--;
		if (green != 0)
			green--;
		if (blue != 0)
			blue--;
		if (red <= 0 && blue <= 0 && green <= 0)
			stage++;
		break;
	case 8: // red increase to reset
		red++;
		if (red == 255)
			stage = 0;
		break;

	}
};

bool collision(int x1, int y1, int x2, int y2) {
	if ((x1 + 30 > x2) && (x1 < x2 + 100) && (y1 + 30 > y2) && (y1 < y2 + 20))
		return true;
	else
		return false;
}