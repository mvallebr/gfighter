#ifndef __GF_POLY__
#define __GF_POLY__

//#include <crystalspace.h>

#include "GFString.h"
#include "GFVector.h"

#define USUAL_COLOR		(255)
#define COLLISION_COLOR (255 << 16)

class GFPoly {
private:
	double numa, numb, den, ua, ub; //for line intersection detection
protected:	
	GFString name, trigger;	
	GFVector vertices[4];
	GFVector vertices_scr[4];	
	int line_colors[4];
	int priority;
	int verifyLineIntersection(GFVector &a1, GFVector &a2, GFVector &b1, GFVector &b2);
public:
	GFPoly(const char *name);
	~GFPoly();	

	inline int  getPriority() { return priority; }
	inline void setPriority(int priority) { this->priority = priority; }

	inline void setTrigger(const char *newvalue) {trigger.Replace(newvalue); }
	inline const char *getTrigger() { return trigger.GetData(); }
	inline void setVectorPoint(int index, double x, double y) { 
		if ((index<0) || (index>3)) return;
		vertices[index].x = x;
		vertices[index].y = y;
	}
	inline double getVectorX(int index) {
		if ((index<0) || (index>3)) return -1;
		return vertices[index].x;
	}
	inline double getVectorY(int index) {
		if ((index<0) || (index>3)) return -1;
		return vertices[index].y;
	}

	void Render();
	void calcScreenCoords(bool flip, int x, int y, int w, int h, float xscale, float yscale);
	int verifyCollision(GFPoly *other);	
};


#endif //__GF_POLY__
