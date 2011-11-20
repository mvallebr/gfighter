#ifndef __GF_FRAME__
#define __GF_FRAME__

//#include <crystalspace.h>
#include "gfpoly.h"
//#include "GFSprite.h"
#include "GFArray.h"
#include "GFString.h"
#include "GFTexture.h"

class GFFrame {
private:

protected:	
	GFString name, state;
	GFTexture pixmap, pixmapflip;
	int centerx, centery;
	GFArray polys;	
	void RenderPolys(bool flip, int x, int y, int w, int h, float xscale, float yscale);

public:
	GFFrame(const char *name);
	~GFFrame();	

	inline int  getCenterX() { return centerx; }
	inline void setCenterX(int centerx) { this->centerx = centerx; }
	inline int  getCenterY() { return centerx; }
	inline void setCenterY(int centery) { this->centery = centery; }
	inline const char *getState() { return state.GetData(); }
	inline void setState(const char *newstate) { state.Replace(newstate); }
	inline GFTexture* getPixmap() { return &pixmap; }
	inline int getWidth() { return pixmap.Width(); }
	inline int getHeight() { return pixmap.Height(); }

	bool loadPixmap(const char *filename);
	void Render(bool flip, int x, int y);
	inline int getNumPolys() { return polys.Length(); }
	inline GFPoly* getPoly(int i) { return (GFPoly *)polys.Get(i); }
	inline void addPoly(GFPoly *poly) {polys.Push(poly); }
	void verifyCollisions(GFFrame *other, char *thistr, char *othertr);	
};


#endif //__GF_FRAME__
