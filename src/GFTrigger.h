#ifndef __GF_TRIGGER__
#define __GF_TRIGGER__

#include <string>
#include "GFString.h"
#include "GFSprite.h"
#include "gftriggerc.h"

using std::string;

#ifdef FOR_UNIX
	#include <dlfcn.h>
	#define GetFunctionFromModule dlsym
	#define CloseModule dlclose
	typedef (void*) LpHandleType;
#else
	#include <windows.h>
	#define GetFunctionFromModule GetProcAddress
	#define CloseModule FreeLibrary
	typedef HINSTANCE LpHandleType;
#endif
typedef int (*trigger_function)(trigger_data *data);
#define MAX_TRIGGER_FUNCTIONS 200

extern "C" {	
int stateMatchValue(char *name, char *value);
void setStateValue(char *name, char *value);
}

class GFTrigger {
private:		
	int instance_num;
protected:
	string  name;
	string  vfspath;	
public:
	GFTrigger(string name, string full_vfs_path);
	~GFTrigger();
	inline const char *getName() { return name.c_str(); }
	int CallTrigger();		
	trigger_data data;
};


#endif //__GF_TRIGGER__
