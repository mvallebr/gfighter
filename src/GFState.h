#ifndef __GF_STATE__
#define __GF_STATE__

#include "GFString.h"

class GFState {
private:

protected:	
	GFString name;
	GFString value;
public:
	GFState(const char *name, const char *value);
	~GFState();	
	inline const char *getName() { return name.GetData(); }
	inline const char *getValue() { return value.GetData(); }
	inline void setValue(char *value) { 		
		this->value.Replace(value);
	}
};


#endif //__GF_STATE__
