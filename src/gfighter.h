#ifndef __GFIGHTER_H__
#define __GFIGHTER_H__

#include <stdarg.h>
#include <iostream>
#include <string>

#include "GFSprite.h"
#include "GFLevel.h"
#include "GFRect.h"
#include "GFSystem.h"

using std::cout; 
using std::cerr; 
using std::endl; 
using std::cin; 
using std::fixed;
using std::string;

class GFighter {
private:
	char *levelName;
	bool LoadLevels();
	char *p1Name;
	char *p2Name;
	bool LoadPlayers();
	bool LoadInputs();

	GFLevel  *LoadLevel(const char *vfs_path);
	GFSprite *LoadSprite(const char *vfs_path);
protected:	
	GFLevel *level;
	GFSprite *player1, *player2;
	string  level_vfs_path;
	GFInput *current_input;
	GFRect *screenbox;
public:
	GFighter ();
	~GFighter ();	

	GFLevel *getLevel() {return level;};
	string getLevelVfsFilename() { return level_vfs_path;};
	inline GFRect* getScreenBox() { 
		int i;
		screenbox->xmin = MIN((int)player1->getX()-player1->getCurrentWidth()/2, 
			(int)player2->getX()-player2->getCurrentWidth()/2)-20;
		screenbox->ymin = MIN((int)player1->getY(), (int)player2->getY())-20;
		screenbox->xmax = MAX((int)player1->getX()+player1->getCurrentWidth()/2, 
			(int)player2->getX()+player2->getCurrentWidth()/2)+20;
		screenbox->ymax = MAX((int)player1->getY()+player1->getCurrentHeight(), 
			(int)player2->getY()+player2->getCurrentHeight())+20 + level->getYGround();		
		//If small than screen, se it to screen size
		if ((screenbox->ymax - screenbox->ymin) <  GFSystem::getInstance()->getScreenHeight()) {
			screenbox->ymax = GFSystem::getInstance()->getScreenHeight() + screenbox->ymin;
		}
		if ((screenbox->xmax - screenbox->xmin) <  GFSystem::getInstance()->getScreenWidth()) {
			i = (screenbox->xmax - screenbox->xmin)/2;
			screenbox->xmax = GFSystem::getInstance()->getScreenWidth() + screenbox->xmin - i;
			screenbox->xmin -= i;
		}
		//Correct aspect ratio
		if ((screenbox->ymax - screenbox->ymin)*level->getWidth()/level->getHeight()
			< (screenbox->xmax - screenbox->xmin)) {
			screenbox->ymin = screenbox->ymax*level->getWidth()/level->getHeight() - (screenbox->xmax - screenbox->xmin);
		} else {
			screenbox->xmin = screenbox->xmax - (screenbox->ymax - screenbox->ymin)*level->getWidth()/level->getHeight();
			//screenbox->xmax += (screenbox->ymax - screenbox->ymin)/2;
			i = (screenbox->xmax - screenbox->xmin)/2;
			screenbox->xmin = (int)((player1->getX() + player2->getX())/2 ) - i;
			screenbox->xmax = (int)((player1->getX() + player2->getX())/2 ) + i;
		}		
		return screenbox; }
	// ----------------------------------------

  bool initialize (int argc, char* argv[]);
	void run();
	void gameLoop();
	void processFrame ();
};

//Returns the global system variable 
GFighter *global_system();

#endif // __GFIGHTER_H__

