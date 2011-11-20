#ifndef __GF_ACTION__
#define __GF_ACTION__

#include "GFString.h"
#include "GFFrame.h"
//#include "GFSprite.h"
#include "GFArray.h"

class GFAction {
private:

protected:	
	GFString  name, nextAction, soundFile, trigger;
	GFArray frames;
	int current_frame;
	double current_adv_frame;
public:
	GFAction(const char *name);
	~GFAction();	
	inline const char *getName() { return name.GetData(); }
	inline void setNextAction(const char *newvalue) {	
		nextAction.Replace(newvalue);	}
	inline const char *getNextAction() { return nextAction.GetData(); }
	inline void setSoundFile(const char *newvalue) {	
		soundFile.Replace(newvalue);	}
	inline const char *getSoundFile() { return soundFile.GetData(); }
	inline void setTrigger(const char *newvalue) {	
		trigger.Replace(newvalue);	}
	inline const char *getTrigger() { return trigger.GetData(); }

	inline void setCurrentFrame(int current_frame) {	
		this->current_frame = current_frame;	}
	inline int getCurrentFrame() { return current_frame; }
	inline GFFrame* getFrame( int i) { return (GFFrame *)frames.Get(i); }
	inline int getNumFrames() { return frames.Length(); }
	inline void setCurrentAdvFrame(double current_adv_frame) {	
		this->current_adv_frame = current_adv_frame;	}
	inline double getCurrentAdvFrame() { return current_adv_frame; }
	

	bool addFrame(const char *name, const char *state, const char *imagefile, 
		int centerx, int centery);
	bool Render(bool flip, int x, int y, double frames_to_advance);
	void verifyCollisions(GFAction *other, char *thistr, char *othertr);
};


#endif //__GF_ACTION__
