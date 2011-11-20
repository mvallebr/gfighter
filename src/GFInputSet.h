#ifndef __GF_INPUTSET__
#define __GF_INPUTSET__

#include "GFString.h"

class GFInputSet {
private:

protected:	
	bool up_arrow, down_arrow, left_arrow, right_arrow;
	bool a, b, c, d;
	int mindur, maxdur;
	int duration;
public:
	GFInputSet();
	~GFInputSet();	
	inline bool getUpArrow() {return up_arrow; }
	inline void setUpArrow(bool newvalue) {up_arrow=newvalue; }
	inline bool getDownArrow() {return down_arrow; }
	inline void setDownArrow(bool newvalue) {down_arrow=newvalue; }
	inline bool getLeftArrow() {return left_arrow; }
	inline void setLeftArrow(bool newvalue) {left_arrow=newvalue; }
	inline bool getRightArrow() {return right_arrow; }
	inline void setRightArrow(bool newvalue) {right_arrow=newvalue; }
	inline bool getA() {return a; }
	inline void setA(bool newvalue) {a=newvalue; }
	inline bool getB() {return b; }
	inline void setB(bool newvalue) {b=newvalue; }
	inline bool getC() {return c; }
	inline void setC(bool newvalue) {c=newvalue; }
	inline bool getD() {return d; }
	inline void setD(bool newvalue) {d=newvalue; }
	inline int  getMinDur() {return mindur; }
	inline void setMinDur(int newvalue) {mindur=newvalue; }
	inline int  getMaxDur() {return maxdur; }
	inline void setMaxDur(int newvalue) {maxdur=newvalue; }
	inline int  getDuration() {return duration; }
	inline void setDuration(int newvalue) {duration=newvalue; }
	inline void IncreaseDuration(int time) { duration +=time; }
	bool isEverythingFalse();
	bool CompareStates(GFInputSet *is);
	void Print();
};


#endif //__GF_INPUTSET__
