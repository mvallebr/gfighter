#ifndef __GF_SPRITE__
#define __GF_SPRITE__

//#include <crystalspace.h>
#include "GFString.h"
#include "GFAction.h"
#include "GFFrame.h"
#include "GFTrajectory.h"
#include "GFTrajPoint.h"
#include "GFInput.h"
#include "GFInputSet.h"
#include "GFState.h"
#include "GFTrigger.h"

#include <string>

using std::string;

class GFSprite {
private:

protected:
	string vfspath;

	double x, y;
	bool flip;

	GFArray		actions;
	int current_action;
	int current_trajectory;
	int current_input;

	GFArray	trajectories;
	GFArray			states;
	GFArray			inputs;
	GFArray			triggers;

	double aframes;
public:
	void GFSPrite();
	~GFSprite();

	inline double  getX() { return x; }
	inline void setX(double x) { this->x = x; }
	inline double  getY() { return y; }
	inline void setY(double y) { this->y = y; }
	inline bool getFlip() { return flip; }
	inline void setFlip(bool flip) { this->flip = flip; }
	inline int  getCurrentAction() { return current_action; }
	inline void setCurrentAction(int current_action) 
		{ this->current_action = current_action; }
	inline int  getCurrentTrajectory() { return current_trajectory; }
	inline void setCurrentTrajectory(int current_trajectory) 
		{ this->current_trajectory = current_trajectory; }
	inline int  getCurrentInput() { return current_input; }
	inline void setCurrentInput(int current_input) 
		{ this->current_input = current_input; }
	inline GFAction*  getAction(int id) { return (GFAction *)(actions.Get(id)); }
	inline GFTrajectory*  getTrajectory(int id) { return (GFTrajectory*)(trajectories.Get(id)); }
	inline GFInput*  getInput(int id) { return (GFInput*)(inputs.Get(id)); }
	inline GFTrigger*  getTrigger(int id) { return (GFTrigger*)(triggers.Get(id)); }
	inline GFState*  getState(int id) { return (GFState*)(states.Get(id)); }
	inline int getNumInputs() { return inputs.Length(); }
	inline double getAFrames() { return aframes; }
	inline int getCurrentWidth() {  
		GFAction *action;
		GFFrame *frame;
		int nframe;
		if (current_action<0) return -1;
		if (getAction(current_action)->getCurrentFrame() <0) return -1;
		action = getAction(current_action);
		nframe = action->getCurrentFrame();
		frame = action->getFrame(nframe);
		return frame->getWidth();		
	}
	inline int getCurrentHeight() {  
		return  (current_action<0) ? -1 : (
			(getAction(current_action)->getCurrentFrame() <0)	
			? -1 : getAction(current_action)->getFrame(getAction(current_action)->getCurrentFrame())->getHeight()
			); 
	}
	bool LoadFromFile(string full_vfs_path);
	int FindAction(const char *actionname);
	int FindTrajectory(const char *trajectoryname);
	int FindTrigger(const char *triggername);
	int LoadTriggerData(GFTrigger *trigger);
	int SaveTriggerData(GFTrigger *trigger);
	int CallTrigger(const char *triggername);
	void Render();
	bool ProcessTrajectory();
	void addState  (char *name, char *value);
	int  findState (char * name);
	void setStateValue(char *name, char *value);
	const char *getStateValue(char *name);
	void verifyCollisions(GFSprite *other);

};
void setCurrentSprite(GFSprite *sp);
GFSprite *getCurrentSprite();

#endif //__GF_SPRITE__
