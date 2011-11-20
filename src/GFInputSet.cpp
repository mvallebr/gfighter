
#include <iostream>

//#include "gfighter.h"
#include "GFInputSet.h"

using std::cout;

GFInputSet::GFInputSet(){	
	up_arrow = down_arrow = left_arrow = right_arrow = false;
	a = b = c = d = false;	
	mindur = maxdur = 0;
	duration = 0;
}

GFInputSet::~ GFInputSet() {

}

bool 
GFInputSet::isEverythingFalse() {
	return ((this->up_arrow	== false) &&
		(this->down_arrow	== false) &&
		(this->left_arrow	== false) &&
		(this->right_arrow	== false) &&
		(this->a==false) &&
		(this->b==false) &&
		(this->c==false) &&
		(this->d==false) 
		);
}

bool 
GFInputSet::CompareStates(GFInputSet *is) {
	bool result;
	result = ((this->up_arrow	==is->up_arrow) &&
		(this->down_arrow	==is->down_arrow) &&
		(this->left_arrow	==is->left_arrow) &&
		(this->right_arrow	==is->right_arrow) &&
		(this->a==is->a) &&
		(this->b==is->b) &&
		(this->c==is->c) &&
		(this->d==is->d) 
		);
	if (result && !isEverythingFalse()) {
		//cout << "\nThe following inputsets are the same:\n";
		//this->Print();
		//is.Print();
	}
	return result;
}

void 
GFInputSet::Print() {
	cout << "Printing inputset: \n up    = " << up_arrow;
	cout << "\n down  = " << down_arrow;
	cout << "\n left  = " << left_arrow;
	cout << "\n right = " << right_arrow;
	cout << "\n a     = " << a;
	cout << "\n b     = " << b;
	cout << "\n c     = " << c;
	cout << "\n d     = " << d;
	cout << "\n mindur= " << mindur;
	cout << "\n maxdur= " << maxdur;
	cout << "\n";
}
