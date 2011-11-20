#ifndef __GF_TRAJECTORY__
#define __GF_TRAJECTORY__

//#include <crystalspace.h>
#include "GFTrajPoint.h"
#include "GFString.h"
#include "GFArray.h"
#include "GFVector.h"

class GFTrajectory {
private:

protected:	
	GFArray points;
	GFString name, trigger, nexttraj;
	int width, height;
	GFVector cur_vector;
	int current_point;
	double total_aframes;
	double total_time;
public:
	GFTrajectory(const char *name);
	~GFTrajectory();		
	inline void addPoint(GFTrajPoint *point) { points.Push(point);};
	inline const char *getName() { return name.GetData(); }
	inline void setTrigger(const char *newvalue) {	
		trigger.Replace(newvalue);	}
	inline const char *getTrigger() { return trigger.GetData(); }
	inline void setNextTraj(const char *newvalue) {	
		nexttraj.Replace(newvalue);	}
	inline const char *getNextTraj() { return nexttraj.GetData(); }
	inline void setWidth(int width) { this->width = width;	}
	inline int getWidth() { return width; }
	inline void setHeight(int height) { this->height = height;	}
	inline int getHeight() { return height; }
	inline GFTrajPoint *getPoint(int id) { return (GFTrajPoint *) points.Get(id); }
	inline void setCurrentPoint(int current_point) { this->current_point = current_point;	}
	inline int getCurrentPoint() { return current_point; }
	inline void setPointFrames(double frames) { getPoint(current_point)->setCurrentFrame(frames);	}
	inline int getNumPoints() { return points.Length(); }
	double advanceInFrames(double num_frames);
	const GFVector & getVector();
	inline const double getAFrames() { return (total_time==0) ? 1.0 : (total_aframes/total_time); }
};


#endif //__GF_TRAJECTORY__
