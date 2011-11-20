
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
#include "gfighter.h"
#include "GFTrigger.h"
#include "GFSystem.h"

using std::string;
using std::transform;
using std::tolower;

//Global variables declared to load dll
int num_instances=0;
LpHandleType plugin_handle=NULL;

//C functions
extern "C" {
	trigger_function fptr[MAX_TRIGGER_FUNCTIONS];
}

int stateMatchValue(char *name, char *value) {
	GFSprite *sp;
	char *svalue;
	sp = getCurrentSprite();		 	
	if (sp!=NULL) {
		svalue = (char *) sp->getStateValue(name);		
	}
	if ( (svalue==NULL) || (value==NULL) ) 
		return 0;
	string a(value), b(svalue);
	transform (a.begin(), a.end(), a.begin(), tolower);
	transform (b.begin(), b.end(), b.begin(), tolower);
	cout << "Comparing '" << value << "' with '" << svalue << "'\n";
	cout << "Returning '";
	cout << ((a==b) ? "TRUE" : "FALSE") ;
	cout << "'\n\n";
	return (a==b);
}

void setStateValue(char *name, char *value) {
	GFSprite *sp;
	sp = getCurrentSprite();	
	if (sp!=NULL) {
		sp->setStateValue(name, value);			
	} else {
		cerr << "Unexpected error! No current sprite set! \n";
	}
}

//Object functions
GFTrigger::GFTrigger(string name, string full_vfs_path){		
	char filename[1024];
	//GFighter *gf;	
	//gf = global_system();
	
	this->name=name;			

	//vfspath = GFSystem::getInstance()->getAppPath();
	vfspath+=full_vfs_path;
	vfspath+="triggers";		
	#ifdef FOR_UNIX
		vfspath+=".so";
	#else
		vfspath+=".dll";
	#endif
	//csRef <iDataBuffer> data = gf->vfs->GetRealPath(vfspath.GetData());
	strcpy(filename, vfspath.c_str());
	//Load the plugin dll
	if (num_instances==0) {
		cout << "Loading Trigger file '" << filename << "'...\n";
		#ifdef FOR_UNIX
			plugin_handle = dlopen(filename , RTLD_LAZY);
		#else
			plugin_handle = LoadLibrary(filename);
		#endif
		cout  << "plugin_handle = '" << plugin_handle << "'\n";
	}	
	//Initialize function point on data structure
	this->data.stateMatchValue = stateMatchValue;
	this->data.setStateValue   = setStateValue;
	//Increase instance and load plugin function from dll
	instance_num = num_instances; //instance_num is new available id
	cout << "instance_num=" << instance_num << "\n";
	cout.flush();
	fptr[instance_num] = NULL;
	if (plugin_handle!=NULL) {//Load function to this instance_num
		fptr[instance_num] = (trigger_function) 
			GetFunctionFromModule(plugin_handle, getName());			
	}
	cout << "fptr[instance_num]=" << fptr[instance_num] << "\n";
	cout.flush();
	num_instances++;
}

GFTrigger::~GFTrigger() {
	num_instances--;
	//If it´s the last instance, close the dll. 
	if (num_instances==0) {
		if (plugin_handle)
			CloseModule( plugin_handle );
	}
}

int 
GFTrigger::CallTrigger() {
	int returnvalue;
	cout << "Executing trigger '" << getName() << "'\n";
	if (fptr[instance_num]) {		
		cout << "Before - "<< (&data)->pcurrent_action << "\n";
		returnvalue =  (*(fptr[instance_num]))(&data);		
		cout << "After - "<< (&data)->pcurrent_action << "\n";
		return returnvalue;
	} else {
		cerr << "ERROR! Trigger " << getName() << " not loaded! \n";
		cerr << "Please check the function name on triggers dll!\n";
		cerr.flush();
	}
	return -1;
}
