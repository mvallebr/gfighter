#ifndef __GF_INPUT__
#define __GF_INPUT__

#include "GFString.h"
#include "GFInputSet.h"
#include "GFArray.h"

#define MAX_INPUTSETS 16 

class GFInput {
private:

protected:		
	GFString  name, trigger, triggerRelease;
	int current;
public:
	GFArray inputsets;

	GFInput(const char *name);
	~GFInput();	
	inline const char *getTrigger() { return trigger.GetData(); }
	inline void setTrigger(const char *newstate) { trigger.Replace(newstate); }	
	inline const char *getTriggerRelease() { return triggerRelease.GetData(); }
	inline void setTriggerRelease(const char *newstate) { triggerRelease.Replace(newstate); }	
	inline int getCurrent() { return current; }
	inline void setCurrent(int current) { this->current = current; };
	inline GFInputSet * getInputSet(int id) { return (GFInputSet *)inputsets.Get(id); }
	
	bool VerifyKeyboard();
	bool compareTo(GFInput *input);

};


#endif //__GF_INPUT__
