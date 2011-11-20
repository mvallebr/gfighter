#ifndef __GF_LEVLAYER__
#define __GF_LEVLAYER__

#include "GFTexture.h"

struct iImage;

class GFLevLayer {
private:
	
protected:
	int x, y;
	float z;
	GFTexture pixmap;
public:
	GFLevLayer();
	~GFLevLayer();	
	float getZ() { return z;};
	void  setZ(float z) { this->z = z; };
	int getX() { return x;};
	void  setX(int x) { this->x = x; };
	int getY() { return y;};
	void  setY(int y) { this->y = y; };
	bool  LoadImageFromFile(const char *filename);
	void  Render(int offsetx, int offsety, int centerx, int centery);
};	



#endif //__GF_LEVLAYER__
