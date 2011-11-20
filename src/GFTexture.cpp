
#include <iostream>
#include <exception>
#include "GFTexture.h"
#include "GFSystem.h"

using irr::core::rect;
using irr::core::position2d;
using irr::core::dimension2d;
using irr::video::ECF_A1R5G5B5;
using irr::video::ECF_R5G6B5;
using irr::video::ECF_R8G8B8;
using irr::video::ECF_A8R8G8B8;
using irr::video::IImage;
using std::cerr;
using std::cout;
using std::exception;

int GFTexture::instanceCount = 0;

void
GFTexture::loadImageFromFile (string filename) {
	//Loads each texture with a different name, so it will use different 3D resources in the video memory
	IImage *img = GFSystem::getInstance()->getDeviceDriver()->createImageFromFile(filename.c_str());
	image = GFSystem::getInstance()->getDeviceDriver()->addTexture("texture"+instanceCount, img);
	img->drop();
	//image = GFSystem::getInstance()->getDeviceDriver()->getTexture(filename.c_str());
}

void
GFTexture::draw(int x, int y) {
	if (image==NULL) { cerr << "Image not loaded!"; return;	}
	GFSystem::getInstance()->getDeviceDriver()->draw2DImage(
			image, rect<s32>(position2d<s32>(x, y), image->getSize()),
			rect<s32>(position2d<s32>(0, 0), image->getSize())
			, 0, 0, true
			);
}

void
GFTexture::drawScaled(int x, int y, int w, int h) {
	if (image==NULL) { cerr << "Image not loaded!"; return;	}
	GFSystem::getInstance()->getDeviceDriver()->draw2DImage(
			image, rect<s32>(position2d<s32>(x, y), dimension2d<s32>(w,h)),
			rect<s32>(position2d<s32>(0, 0), image->getSize())
			, 0, 0, true
			);
}

void
GFTexture::flipImageH() {
	if (image==NULL) { cerr << "Image not loaded!"; return;	}
	int pixelSize=4;
	char temp;
	
	//Calculates the pixel size
	switch (image->getColorFormat()) {
		//	16 bit color format used by the software driver, and thus preferred by all other irrlicht engine video drivers. 
		//	There are 5 bits for every color component, and a single bit is left for alpha information.
		case ECF_A1R5G5B5:	pixelSize=2; break; 
		//	Standard 16 bit color format.
		case ECF_R5G6B5:		pixelSize=2; break; 	
		//	24 bit color, no alpha channel, but 8 bit for red, green and blue.
		case ECF_R8G8B8:		pixelSize=3; break; 	 	
		//	Default 32 bit color format. 8 bits are used for every component: red, green, blue and alpha.
		case ECF_A8R8G8B8:	pixelSize=4; break; 	
		default: break;
	}

	//Flip the image horizontally
	char *buffer = (char *) image->lock(); //Start doing changes
	if (buffer==NULL) {
		cerr << "ERROR! Image cannot be locked!!\n";
		throw new exception("ERROR! Image cannot be locked!!");
	}

	int pitch		= image->getPitch();
	int width		= image->getSize().Width;
	int height	= image->getSize().Height;
	int rowOffset=0;
	int colOffset=0;
	cout << "W= " << width << " H=" << height << " pitch = " << pitch << " psize = " << pixelSize << " \n";
	for (int j=0; j<height; j++) {
		rowOffset=j*pitch;
		unsigned int halfWidth = pitch/(pixelSize*2);
		for (unsigned int i=0; i<halfWidth; i++) { //goes to the half of image width
			colOffset=i*pixelSize;
			for (int k=0; k<pixelSize; k++) { //For each byte of the pixel
				temp = buffer[rowOffset+colOffset+k];
				buffer[rowOffset+colOffset+k] = buffer[rowOffset +pitch -colOffset+k];
				buffer[rowOffset +pitch -colOffset+k] = temp;
			}
		}
	}
	image->unlock(); //Changes done
	image->regenerateMipMapLevels();
}


