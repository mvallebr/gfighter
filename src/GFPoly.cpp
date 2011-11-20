

#include "GFSystem.h"
#include "gfighter.h"
#include "GFFrame.h"


GFPoly::GFPoly(const char *name){	
	this->name.Replace(name);	
	trigger.Replace("");
	priority = 0;	
	for (int i=0; i<4; i++) {
		vertices[i].x = vertices[i].y = 0.0;
		vertices_scr[i].x = vertices_scr[i].y = 0.0;
		line_colors[i] = USUAL_COLOR; //red, in rgb
	}
}

GFPoly::~GFPoly() {

}

void
GFPoly::Render() {
	//GFighter *gf;

	GFSystem::getInstance()->drawLine(
		(int) vertices_scr[0].x, (int) vertices_scr[0].y, (int) vertices_scr[1].x, (int) vertices_scr[1].y, 
		(line_colors[0] >> 16) & 255 , (line_colors[0] >> 8) & 255, line_colors[0] & 255, 255);
	GFSystem::getInstance()->drawLine(
		(int) vertices_scr[1].x, (int) vertices_scr[1].y, (int) vertices_scr[2].x, (int) vertices_scr[2].y,
		(line_colors[1] >> 16) & 255 , (line_colors[1] >> 8) & 255, line_colors[1] & 255, 255);
	GFSystem::getInstance()->drawLine(
		(int) vertices_scr[2].x, (int) vertices_scr[2].y, (int) vertices_scr[3].x, (int) vertices_scr[3].y, 
		(line_colors[2] >> 16) & 255 , (line_colors[2] >> 8) & 255, line_colors[2] & 255, 255);
	GFSystem::getInstance()->drawLine(
		(int) vertices_scr[3].x, (int) vertices_scr[3].y, (int) vertices_scr[0].x, (int) vertices_scr[0].y, 
		(line_colors[3] >> 16) & 255 , (line_colors[3] >> 8) & 255, line_colors[3] & 255, 255);

	//gf = global_system();	
	//gf->g3d->GetDriver2D()->DrawLine(vertices_scr[0].x, vertices_scr[0].y, 
	//	vertices_scr[1].x, vertices_scr[1].y, line_colors[0]);
	//gf->g3d->GetDriver2D()->DrawLine(vertices_scr[1].x, vertices_scr[1].y, 
	//	vertices_scr[2].x, vertices_scr[2].y, line_colors[1]);
	//gf->g3d->GetDriver2D()->DrawLine(vertices_scr[2].x, vertices_scr[2].y, 
	//	vertices_scr[3].x, vertices_scr[3].y, line_colors[2]);
	//gf->g3d->GetDriver2D()->DrawLine(vertices_scr[3].x, vertices_scr[3].y, 
	//	vertices_scr[0].x, vertices_scr[0].y, line_colors[3]);
	
}

void 
GFPoly::calcScreenCoords(bool flip, int x, int y, int w, int h, float xscale, float yscale) {
	if (flip) {
		vertices_scr[0].x = x+w-vertices[0].x*xscale;
		vertices_scr[0].y = y+h-vertices[0].y*yscale;
		vertices_scr[1].x = x+w-vertices[1].x*xscale;
		vertices_scr[1].y = y+h-vertices[1].y*yscale;
		vertices_scr[2].x = x+w-vertices[2].x*xscale;
		vertices_scr[2].y = y+h-vertices[2].y*yscale;
		vertices_scr[3].x = x+w-vertices[3].x*xscale;
		vertices_scr[3].y = y+h-vertices[3].y*yscale;		
	} else {
		vertices_scr[0].x =   x+vertices[0].x*xscale;
		vertices_scr[0].y = y+h-vertices[0].y*yscale;
		vertices_scr[1].x =   x+vertices[1].x*xscale;
		vertices_scr[1].y = y+h-vertices[1].y*yscale;
		vertices_scr[2].x =   x+vertices[2].x*xscale;
		vertices_scr[2].y = y+h-vertices[2].y*yscale;
		vertices_scr[3].x =   x+vertices[3].x*xscale;
		vertices_scr[3].y = y+h-vertices[3].y*yscale;
	}
}

int 
GFPoly::verifyCollision(GFPoly *other) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			//compare this->polyline[i] with other->polyline[j]
			if (verifyLineIntersection(vertices_scr[i], vertices_scr[(i==3)?0:i+1],
				other->vertices_scr[j], other->vertices_scr[(j==3)?0:j+1]
				)) {
				line_colors[i] = other->line_colors[j] = COLLISION_COLOR;
				return 1;
			} else {
				line_colors[i] = other->line_colors[j] = USUAL_COLOR;
			}
		}
	}
	return 0;
}

int 
GFPoly::verifyLineIntersection(GFVector &a1, GFVector &a2, GFVector &b1, GFVector &b2) {
	den   = (b2.y - b1.y)*(a2.x - a1.x) - (b2.x - b1.x)*(a2.y - a1.y);	
	if (den==0) return 0; //lines are parallel
	//could test if numa == numb to see if the lines are coincident
	numa  = (b2.x - b1.x)*(a1.y - b1.y) - (b2.y - b1.y)*(a1.x - b1.x);	
	numb  = (a2.x - a1.x)*(a1.y - b1.y) - (a2.y - a1.y)*(a1.x - b1.x);	
	
	ua = numa / den;
	ub = numb / den;
	//to have colision, both ua and ub needs to be beetwen 0 and 1
	//cout << "ua=" << ua << " ub=" << ub << "\n";
	/*static int k=0;
	if ((0.0<ua) && (ua<1.0) && (0.0<ub) && (ub<1.0))  {
		if (k++>50) {
			k=0;
			cout << "a1=(" << a1.x << "," << a1.y << ") ";
			cout << "b1=(" << b1.x << "," << b1.y << ") \n";
			cout << "a2=(" << a2.x << "," << a2.y << ") ";
			cout << "b2=(" << b2.x << "," << b2.y << ") \n";
			cout << "ua=" << ua << " ub=" << ub << "\n\n";
        }
	}*/
	return (0.0<ua) && (ua<1.0) && (0.0<ub) && (ub<1.0);
}






