
#ifndef __GF_SYSTEM__
#define __GF_SYSTEM__

#include <irrlicht.h>
#include <iostream>
#include <string>
#include <map>

//using namespace irr;
using std::string;
using std::map;
using irr::core::rect;
using irr::core::position2d;
using irr::core::dimension2d;
using irr::video::IVideoDriver;
using irr::video::SColor;
using irr::IrrlichtDevice;
using irr::s32;
using irr::ITimer;
using irr::gui::IGUIEnvironment;
using irr::EKEY_CODE;
using irr::IEventReceiver;
using irr::SEvent;

#pragma comment(lib, "Irrlicht.lib")

class GFSystem : public IEventReceiver {
private:		
	IrrlichtDevice *device;
	IGUIEnvironment* guienv;
	std::string appPath;
	int sw, sh;
	ITimer *timer;
	map<int, bool> pressedKeys;
protected:
	
public:
	virtual bool OnEvent(SEvent event);

	static GFSystem *getInstance();
	GFSystem();
	~GFSystem();
	void initialize(int argc, char *argv[], int screenWidth, int screenheight);
	void finish();
	inline IVideoDriver* getDeviceDriver() { return (device==NULL) ? NULL : device->getVideoDriver(); } 
	inline void beginDraw() { if(device!=NULL) device->getVideoDriver()->beginScene(true, false, SColor(0,120,102,136));	}
	inline void endDraw()		{	
		if(guienv!=NULL) guienv->drawAll();
		if(device!=NULL) device->getVideoDriver()->endScene();		
	} 
	inline bool run()				{	return (getDeviceDriver()!=NULL) && device->run();				}
	inline void drawLine (int x1, int y1, int x2, int y2, int cr, int cg, int cb, int ca) { 
		if (getDeviceDriver()!=NULL)
			getDeviceDriver()->draw2DLine(position2d<s32>(x1,y1), position2d<s32>(x2, y2), SColor(cr,cg,cb,ca));
	} 
	inline string getAppPath() { return appPath; }
	inline int getScreenWidth() { return sw; }
	inline int getScreenHeight() { return sh; }
	//Returns the time elapse since the last call
	inline int getElapsedTime() { 
			static int lastTime;
			if (timer==NULL) return 0; 
			int result = timer->getRealTime()-lastTime; lastTime=timer->getRealTime(); return result; 
	}
	inline bool getKeyPressedState(int key) {  return pressedKeys[key];	}

	//Constant key codes
	static const int P1_UP		= irr::KEY_UP;
	static const int P1_DOWN	= irr::KEY_DOWN;
	static const int P1_LEFT	= irr::KEY_LEFT;
	static const int P1_RIGHT = irr::KEY_RIGHT;
	static const int P1_A			= irr::KEY_KEY_A;
	static const int P1_B			= irr::KEY_KEY_B;
	static const int P1_C			= irr::KEY_KEY_C;
	static const int P1_D			= irr::KEY_KEY_D;
	static const int ESC			= irr::KEY_ESCAPE;
};

#endif //__GF_SYSTEM__
