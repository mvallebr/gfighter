
#include "GFSystem.h"
#include <iostream>
#include "GFLevLayer.h"
#include "gfighter.h"

GFLevLayer::GFLevLayer(){	
	z = 0;
}

GFLevLayer::~ GFLevLayer() {	
}

bool  
GFLevLayer::LoadImageFromFile(const char *filename) {
	GFighter *gf;
	gf = global_system();
				
	string  vfsfilename =  gf->getLevelVfsFilename();	
	vfsfilename+=filename;
	
	static int i=0;
	//if (i++)
	//	pixmap = gf->LoadPixmapFromFile("/lib/std/cslogods.png");
	//else 
	//	pixmap = gf->LoadPixmapFromFile(vfsfilename.c_str());
	pixmap.loadImageFromFile(vfsfilename);

	return true;
}

void  
GFLevLayer::Render(int offsetx, int offsety, int centerx, int centery) {		
	float z;
	float xscale, yscale;
	GFighter *gf;
	gf = global_system();	
	/*
	pixmap->Draw(gf->g3d, 
		offsetx + x + centerx - (pixmap->Width()/2), //(gf->g3d->GetWidth()/2) - (pixmap->Width()/2), 
		offsety + y + (gf->g3d->GetHeight()) - (pixmap->Height())
		);  */
	z = (this->z==0) ? 1 : this->z;
	xscale = ((float) GFSystem::getInstance()->getScreenWidth())/(gf->getScreenBox()->xmax - gf->getScreenBox()->xmin);
	yscale = ((float) GFSystem::getInstance()->getScreenHeight())/(gf->getScreenBox()->ymax - gf->getScreenBox()->ymin);
	pixmap.drawScaled(
		(int) ((-offsetx/z  + centerx - (pixmap.Width()/2))*xscale ), 
		(int) ((+ offsety/z  - (pixmap.Height())*yscale + (GFSystem::getInstance()->getScreenHeight()) )),
		(int) (pixmap.Width()*xscale),
		(int) (pixmap.Height()*yscale)
		);
		
}