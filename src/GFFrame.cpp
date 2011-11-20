

#include <iostream>

#include "gfighter.h"
#include "GFFrame.h"
#include "GFSystem.h"
using std::cout;
using std::cerr;


GFFrame::GFFrame(const char *name){	
	this->name.Replace(name);	
	state.Replace("");	
	centerx = centery = 0;
}

GFFrame::~ GFFrame() {

}

bool 
GFFrame::loadPixmap(const char *filename) {	
	//Load second instance
	cout << " now flipping '" << filename << "'...";			
	pixmapflip.loadImageFromFile(filename);
	//Flip second instance
	pixmapflip.flipImageH();
	//Load non flip
	cout << "Loading frame texture '" << filename << "'...";			
	pixmap.loadImageFromFile(filename);
	cout << "Ok!\n";
	return true;
}

void 
GFFrame::Render(bool flip, int x, int y) {
	GFighter *gf;
	int xx, yy;
	int w, h;
	float xscale, yscale;
	gf = global_system();		
	
	//xx = gf->getLevel()->getCenterXScreen() + x - (pixmap->Width()/2);
	//yy = gf->g3d->GetHeight() - y - (pixmap->Height()) ;	
	
	xscale = ((float)GFSystem::getInstance()->getScreenWidth()) / (gf->getScreenBox()->xmax - gf->getScreenBox()->xmin);
	yscale = ((float)GFSystem::getInstance()->getScreenHeight()) / (gf->getScreenBox()->ymax - gf->getScreenBox()->ymin);
	xx =	(int) (gf->getLevel()->getCenterXScreen()  		
		+ ( - gf->getLevel()->getOffsetX() + x - (pixmap.Width()/2))* xscale
		);
	yy =	(int) ((GFSystem::getInstance()->getScreenHeight() - ( - gf->getLevel()->getOffsetY() + y + (pixmap.Height()))*yscale ));
	w =		(int)		(pixmap.Width()*xscale		);
	h =		(int)		(pixmap.Height()*yscale	);
	if (flip) {
		pixmapflip.drawScaled(xx, yy, w, h);
		//pixmapflip->Draw(gf->g3d, 	xx, yy);
	} else {
		pixmap.drawScaled(xx, yy, w, h);
		//pixmap->Draw(gf->g3d, 	xx, yy);
	}
	RenderPolys(flip, xx, yy, w, h, xscale, yscale);
}

void 
GFFrame::RenderPolys(bool flip, int x, int y, int w, int h, float xscale, float yscale) {
	for (int i=0; i<polys.Length(); i++) {
		getPoly(i)->calcScreenCoords(flip, x, y, w, h, xscale, yscale);
		getPoly(i)->Render();
	}
}

void
GFFrame::verifyCollisions(GFFrame *other, char *thistr, char *othertr) {
	int oldpt=-1000, oldpo=-1000;
	thistr=othertr=NULL;
	for (int i=0; i<polys.Length(); i++) {
		for (int j=0; j<other->polys.Length(); j++) {
			if ( getPoly(i)->verifyCollision(other->getPoly(j))  ) {				
				//Call polys.Get(i) trigger
				if (getPoly(i)->getPriority()>oldpt) {
					oldpt = getPoly(i)->getPriority();
					thistr = (char *)getPoly(i)->getTrigger();
				}
				//Call other->polys.Get(j) trigger
				if (other->getPoly(j)->getPriority()>oldpo) {
					oldpo = other->getPoly(j)->getPriority();
					othertr = (char *)other->getPoly(j)->getTrigger();
				}				
			}
		}
	}
}