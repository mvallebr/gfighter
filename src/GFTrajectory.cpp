
#include <iostream>
//#include "gfighter.h"
#include "GFTrajectory.h"

using std::cerr;
using std::cout;


GFTrajectory::GFTrajectory(const char *name) {	
	this->name.Replace(name);	
	trigger.Replace("");
	nexttraj.Replace("");
	width = height = 0;
	current_point = 0;
	total_aframes = 0;
	total_time = 1;
}

GFTrajectory::~GFTrajectory() {

}

double 
GFTrajectory::advanceInFrames(double num_frames) {
	GFTrajPoint *p1, *p2;	
	int first_point;
	double x=0, y=0;
	first_point = current_point;
	cur_vector.Set(0, 0);
	total_aframes=0;
	total_time=0;
	//cout << " Trajectory " << getName() << " Len=" << points.Length() << "\n";	
	do {		
		//reached the end of the trajectory
		if (current_point>=points.Length()-1) {
			current_point = 0;
			first_point = current_point;
			p1 = getPoint(current_point);
			p1->setCurrentFrame(0.0);
			return num_frames;
		}
		p1 = getPoint(current_point);		
		//num_frames+=p1->getCurrentFrame();
		//Reached end of the point
		if (num_frames + p1->getCurrentFrame()> p1->getTime()) { 
			num_frames =  num_frames + p1->getCurrentFrame() - p1->getTime() ;
			total_aframes += p1->getAFrames();
			p1->setCurrentFrame(0.0);
			current_point++;
			setPointFrames(0.0);
		} else {
			break;
		}
	} while (true);

	p1 = getPoint(first_point);
	p2 = getPoint(current_point+1);
	total_time += p1->getTime();
	total_aframes += p1->getAFrames();

	x = (p2->getX() - p1->getX());	
	y = (p2->getY() - p1->getY());
	if (p1->getTime()>0) {
		//cout << "num frames = " << num_frames << "\n";
		x = ((double)x * ( num_frames / (double) p1->getTime() ));
		y = ((double)y * ( num_frames / (double) p1->getTime() ));
	} else {
		x = y = 0;
		cerr << "WARNING: POINT " << p1->getName() << " on trajectory '" 
			<< getName() << "' has Time<=0\n";;
	}
	//cout << "POINT " << p1->getName() << " to " << p2->getName() << " on trajectory '" 
	//		<< getName() << "' x=" << x << " y=" << y << "\n";
	cur_vector.Set(x, y);
	p1->setCurrentFrame(p1->getCurrentFrame()+num_frames);
	return 0.0;
}

const GFVector & 
GFTrajectory::getVector() {
	return cur_vector;
}
