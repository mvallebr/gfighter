#ifndef __GF_VECTOR__
#define __GF_VECTOR__

class GFVector {
private:		
	
protected:
	
public:
	double x, y;
	GFVector()			{	x=y=0;	}
	GFVector(double x, double y)	{	this->x=x;  this->y=y; }
	~GFVector() {}
	void Set(double x, double y) { this->x=x;  this->y=y; }
	
};


#endif //__GF_VECTOR__
