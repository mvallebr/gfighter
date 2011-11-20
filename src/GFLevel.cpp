#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <map>
//#include "gfighter.h"
#include "GFLevel.h"
#include "GFXmlParser.h"
#include "GFSystem.h"

using std::string;
using std::cout;
using std::cerr;
using std::istringstream;
using std::map;
using std::multimap;

GFLevel::GFLevel(){	
	width = 0;
	height = 0;
	vfspath = NULL;	
	offsetx=offsety=0;	
	y_ground=50;
}

GFLevel::~ GFLevel() {

}

void 
GFLevel::Render(float minz, float maxz) {
	for (int i=0; i<layers.Length(); i++) {
		//cout << "Rendering layer "<<i<<"\n";
		if ((getLayer(i)->getZ()>=minz) && (getLayer(i)->getZ()<maxz)){
			getLayer(i)->Render(offsetx, offsety, 
				getCenterXScreen(), getCenterYScreen());
		}
	}
}

bool 
GFLevel::LoadFromFile(string full_vfs_path) {
	string path = full_vfs_path;
	path += "level.xml";
	cout << full_vfs_path << "\n";



	cout << "Loading file '" << path.c_str() << "'...\n";
	GFXmlDocument *xmldoc = GFXmlParser::getInstance()->parse(path.c_str());

	//Now really load everything
	GFXmlElement *rootNode = xmldoc->getRootElement();
	//  -------------  screen -------------
	GFXmlElement *screen = rootNode->getChild("screen");
	GFXmlElement *ewidth = screen->getChild("width");
	width = ewidth->getContentsAsInteger();
	cout << "LEVEL WIDTH = " << width << "\n";
	GFXmlElement *eheight = screen->getChild("height");
	height = eheight->getContentsAsInteger();
	cout << "LEVEL HEIGHT = " << height << "\n";
	//  -------------  background -------------
	GFXmlElement *background = rootNode->getChild("background");
	GF_XML_MMAP childs =  background->getChilds();
	GF_XML_MMAP::iterator iter;   
  for( iter = childs.begin(); iter != childs.end(); iter++ ) {
		GFXmlElement *layer = iter->second;
		float z=1;
		int x=0, y=0;
		const char *file=NULL;
		
		z = layer->getAttributeValueAsFloat("z");
		x = layer->getAttributeValueAsInteger("x");
		y = layer->getAttributeValueAsInteger("y");
		const string fileStr = layer->getAttributeValueAsString("file");
		file = fileStr.c_str();
    if (!addLayer(x, y, z, file)) {
			cerr << "ERROR ON ADDING LEVEL LAYER! Check filename!\n";
		}		
  }
	return true;
}

bool 
GFLevel::addLayer(int x, int y, float z, const char *filename) {
	if ((z==0) || (filename==NULL)) return false;
	cout << "Addind layer with file '" << filename << "' on z=" << z << "\n";
	//csArray<GFLevLayer> layers;
	GFLevLayer *layer = new GFLevLayer(); //Allocates new layer object
	layer->setZ(z);
	layer->setX(x);
	layer->setY(y);
	if (!layer->LoadImageFromFile(filename)) return false;	
	layers.Push(layer);
	cout << "Number of layers now: " << layers.Length() << "\n";	
	return true;
}

int 
GFLevel::getCenterXScreen(){
	return  (GFSystem::getInstance()->getScreenWidth()/2) + (getCenterX() - (width/2));
}

int 
GFLevel::getCenterYScreen(){	
	return GFSystem::getInstance()->getScreenHeight() - 
		((GFSystem::getInstance()->getScreenHeight()/2) + (-getCenterY() + (height/2)));
}


