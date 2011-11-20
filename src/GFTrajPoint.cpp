
#include <iostream>
//#include "gfighter.h"
#include "GFTrajPoint.h"


GFTrajPoint::GFTrajPoint(const char *name){	
	this->name= name;	
	aframes = time = x = y = 0;
	current_frame = 0.0;
}

GFTrajPoint::~GFTrajPoint() {

}
