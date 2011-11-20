

#include <iostream>

//#include "gfighter.h"
#include "GFAction.h"

using std::cerr;
using std::cout;


GFAction::GFAction(const char *name){	
	this->name.Replace(name);
	nextAction.Replace("");
	soundFile.Replace("");
	trigger.Replace("");
	current_frame = 0;
	current_adv_frame = 0.0;
}

GFAction::~ GFAction() {

}

bool 
GFAction::addFrame(const char *name, const char *state, const char *imagefile, 
			  int centerx, int centery) {
	GFFrame *newframe = new GFFrame(name);
	newframe->setState(state);
	newframe->setCenterX(centerx);
	newframe->setCenterY(centery);
	newframe->loadPixmap(imagefile);
		
	frames.Push(newframe);

	return true;
}

bool 
GFAction::Render(bool flip, int x, int y, double frames_to_advance) {
	bool f;//first time on loop
	if (current_frame>=frames.Length()) {
		cerr << "Error! Sprites tryied to render non existing frame: " << current_frame+1 << 
			" on action '" << name.GetData() << "'!!\n";
		current_frame = -1;
		return true;
	}
	current_adv_frame += frames_to_advance;	
	getFrame(current_frame)->Render(flip, x, y);
	f=true;
	while (current_adv_frame > 1.0) {				
		//it assures that if there is more than one frame at a time, 
		// both of them will be printed
		if (!f) 
			getFrame(current_frame)->Render(flip, x, y);
		if (f) f=false;
		current_adv_frame--;
		current_frame++;			
		if (current_frame>=frames.Length()) {
			current_frame = 0;
			return true;
		}
	}		
	return false;
}

void 
GFAction::verifyCollisions(GFAction *other, char *thistr, char *othertr){
	return getFrame(current_frame)->verifyCollisions(
		other->getFrame(other->current_frame), thistr, othertr
		);
}