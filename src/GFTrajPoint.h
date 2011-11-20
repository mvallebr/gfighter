#ifndef __GF_TRAJPOINT__
#define __GF_TRAJPOINT__

#include <string>
using std::string;
//#include "GFString.h"

class GFTrajPoint {
private:

protected:
	string name;
	int aframes, time, x, y;
	double current_frame;
public:
	GFTrajPoint(const char *name);
	~GFTrajPoint();
	inline const char *getName() { return name.c_str(); }
	inline void setX(const int x) { this->x = x; }
	inline const int getX() { return x; }
	inline void setY(const int y) { this->y = y; }
	inline const int getY() { return y; }
	inline void setCurrentFrame(const double current_frame) { 
		this->current_frame = current_frame; }
	inline const double getCurrentFrame() { return current_frame; }
	inline void setAFrames(const int aframes) { this->aframes = aframes; }
	inline const int getAFrames() { return aframes; }
	inline void setTime(const int time) { this->time = time; }
	inline const int getTime() { return time; }
};


#endif //__GF_TRAJPOINT__
