class Brick {
private:
	int width;
	int height;
	int xPos;
	int yPos;
	bool Dead;
	int r, g, b;
public:
	Brick();
	void initBrick(int x, int y);
	void draw();
	bool isDead();
	void killBrick();
	bool collision(int x1, int y1);
};