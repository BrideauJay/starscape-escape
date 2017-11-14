#ifndef Platform_h
#define Platform_h

using namespace std;

class Platform {
public:
	Platform();
	Platform(int startx, int length, int starty, int pixel_width);


	int startx;
	int length;
	int starty;

	int pixel_width;

	void draw();

	bool contains(int xin, int yin);
};


#endif
