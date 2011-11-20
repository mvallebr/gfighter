#ifndef __GF_LEVEL__
#define __GF_LEVEL__

#include "GFLevLayer.h"
#include "GFArray.h"
#include "GFString.h"

class GFLevel {
private:	
	
protected:
	int width, height;
	int offsetx, offsety;
	int y_ground;
	GFArray layers;
	GFString vfspath;
	bool addLayer(int x, int y, float z, const char *filename);
public:
	GFLevel();
	~GFLevel();
	
	GFString  getVfsPath() { return vfspath; };
	inline int getWidth() { return width; };
	inline int getHeight() { return height; };
	bool LoadFromFile(string full_vfs_path);
	void Render(float minz, float maxz);
	inline int getYGround() { return y_ground; };
	inline int getCenterX() { return width/2; };
	inline int getCenterY() { return height/2; };
	inline int getOffsetX() { return offsetx; }
	inline void setOffsetX(int offsetx) { this->offsetx = offsetx; }
	inline int getOffsetY() { return offsety; }
	inline void setOffsetY(int offsety) { this->offsety = offsety; }
	inline GFLevLayer *getLayer(int id) { return (GFLevLayer *) layers.Get(id); }

	//Screen coordinates
	int getCenterXScreen();
	int getCenterYScreen();
};


#endif //__GF_LEVEL__
