#ifndef __GF_TEXTURE__
#define __GF_TEXTURE__

#include <irrlicht.h>
#include <iostream>
#include <string>

using irr::video::ITexture;
using std::string;

#pragma comment(lib, "Irrlicht.lib")

class GFTexture {
private:		
	ITexture* image;
	static int instanceCount;

protected:
	
public:
	GFTexture() { 
		image = NULL;
		instanceCount ++;
	}
	~GFTexture() {
		if (image!=NULL) delete image;
	}
	inline int Width() { return (image==NULL) ? 0 : 	image->getSize().Width;}
	inline int Height() { return (image==NULL) ? 0 : image->getSize().Height;}
	
	// Loads a texture from a file
	void loadImageFromFile(string filename);
	void flipImageH();
	void draw(int x, int y);
	void drawScaled(int x, int y, int w, int h);
};


#endif //__GF_TEXTURE__
