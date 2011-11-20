
#include <iostream>
//#include "gfighter.h"
#include "GFState.h"


GFState::GFState(const char *name, const char *value){	
	this->name.Replace(name);	
	this->value.Replace(value);	
}

GFState::~GFState() {

}
