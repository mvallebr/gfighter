
#include <string>
#include "GFSystem.h"
using namespace irr;
using std::string;

static GFSystem * _instance=NULL;
GFSystem *
GFSystem::getInstance() {
	if (_instance==NULL) {
		_instance = new GFSystem();
	}
	return _instance;
}

GFSystem::GFSystem() {
	device	= NULL;
	timer		= NULL;
}

GFSystem::~GFSystem() {
	if (_instance!=NULL) //Check if we are deleting the singleton instance
		if (_instance==this)
			_instance = NULL;
}

void
GFSystem::initialize(int argc, char *argv[], int screenWidth, int screenheight) {
	//init device 
	device = createDevice(video::EDT_DIRECT3D8, core::dimension2d<s32>(screenWidth, screenheight), 16,			
			false, false,	false, this);
	if (device == NULL)
    throw new exception("Error on system initialize");
	device->setWindowCaption(L"Generic Fighter Engine");
	//gui
	guienv	=	device->getGUIEnvironment();
	//Calculates appPath
	appPath = argv[0];
	appPath = appPath.substr(0, appPath.find_last_of('\\')); //take exe name out
	appPath = appPath.substr(0, appPath.find_last_of('\\')); //takes /bin out
	int pos = appPath.find_first_of('\\');
	while (pos>=0) {
		appPath.replace(pos, 1, "/");
		pos = appPath.find_first_of('\\');
	} 
	//Screen bounds
	sw = screenWidth;
	sh = screenheight;
	//timer
	timer = device->getTimer();
	timer->start();
}

void
GFSystem::finish() {
	timer->stop();
	if (device!=NULL) {
		device->drop();
	}
	delete _instance;
}

bool 
GFSystem::OnEvent(SEvent event) {
	if (event.EventType == EET_KEY_INPUT_EVENT) {
			pressedKeys[event.KeyInput.Key] = event.KeyInput.PressedDown;
	}
	return false;
}

