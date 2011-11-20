#include <iostream>

//#include "gfighter.h"
#include "GFInput.h"
#include "GFSystem.h"

using std::cout;

GFInput::GFInput(const char *name){	
	this->name.Replace(name);
	this->trigger.Replace("");
	current = -1;
}

GFInput::~GFInput() {

}


bool 
GFInput::VerifyKeyboard() {
	//GFighter *gf;
	//gf = global_system();
		
	GFInputSet *is = new GFInputSet();
	is->setLeftArrow(		GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_LEFT));
	is->setRightArrow(	GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_RIGHT));
	is->setUpArrow(			GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_UP));
	is->setDownArrow(		GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_DOWN));
	is->setA(						GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_A));
	is->setB(						GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_B));
	is->setC(						GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_C));
	is->setD(						GFSystem::getInstance()->getKeyPressedState(GFSystem::P1_D));
//	is->setRightArrow(	gf->kbd->GetKeyState (CSKEY_RIGHT)	);	
//	is->setUpArrow(		gf->kbd->GetKeyState (CSKEY_UP)		);
//	is->setDownArrow(	gf->kbd->GetKeyState (CSKEY_DOWN)	);	
//	is->setA(	gf->kbd->GetKeyState ('z'));
//	is->setB(	gf->kbd->GetKeyState ('x'));
//	is->setC(	gf->kbd->GetKeyState ('c'));
//	is->setD(	gf->kbd->GetKeyState ('v'));	
	if ((current>=0) && (current<inputsets.Length())) { // if it is not the first inputset taken, 
		if (is->CompareStates(getInputSet(current))) { // checks if it is the same as the last one
			getInputSet(current)->IncreaseDuration(1);   //Yes it is, so increase the duration instead of creating a new one
			if (!getInputSet(current)->isEverythingFalse()) {
				//cout << "Increase duration of last input set!!! current = " << current << " \n";
				//cout.flush();
			}
			delete is;
			return false;
		}
	}
	//cout << "input " << current << " len=" << inputsets.Length() << "\n";
	//cout.flush();
				
	//cout << "DO NOT Increase duration of last input set!!! current = " << current << " \n";
	//cout.flush();

	current++; //It is a inputset different than the last one. Put it on the list
	if (current>=inputsets.Length())  { // if the list is smaller than needed, 
		if (inputsets.Length() < MAX_INPUTSETS) { // Checks if it can grow
			inputsets.Push(is);											// yes, grow the queue
			current = inputsets.Length()-1;
		} else {
			current = 0;														// Queue is on size limit. restart from beginning, cyclic
		}
	}
	inputsets.setData(current, is); 
	cout << "\n\ninput ("<< current << ") set to  ---";
	((GFInputSet*)inputsets.Get(current))->Print();	
	is->setDuration(1);
	return true;
}

//Compares this inputsets with arg input inputsets
bool 
GFInput::compareTo(GFInput *input) {
	bool printDebug = false;
	int i, j;
	//Gets the start compare index for each input
	i = (this->getCurrent()>-1)		? this->getCurrent()	: this->inputsets.Length()-1;  
	j = (input->getCurrent()>-1)	? input->getCurrent() : input->inputsets.Length()-1;

	//Compare only intersection set. Inputsets that belongs to both sets should be equal to return true
	int minLenght = (this->inputsets.Length()>input->inputsets.Length()) ? input->inputsets.Length() : this->inputsets.Length();
	int k=0;
	if (printDebug) 
			cout << " INPUTS COMPARE BEGIN\n" << minLenght;
	while (k<minLenght) {
		//Decreace i and j by k, cyclic
		int l,m;
		l = (i - k + this->inputsets.Length()) % this->inputsets.Length();
		m = (j - k + input->inputsets.Length()) % input->inputsets.Length();
		//Compare i and j
		if (printDebug) 
				cout << " Comparing "<< "l=" << l << " m=" << m << " i=" << i << " j=" << j << " this->Cur="<<this->getCurrent()<<" \n";
		if (!this->getInputSet(l)->CompareStates(input->getInputSet(m))) {
			if (printDebug) 
				cout << " Comparing "<< "l=" << l << " m=" << m << " i=" << i << " j=" << j << " - INPUTS COMPARE RETURNED FALSE\n";
			return false;
		}
		k++;
	}
	//Verify durations
	//	if ( ( (getInputSet(l)->getMinDur()!=0) && 
	//		 (input->getInputSet(j)->getDuration()<getInputSet(l)->getMinDur()) )
	//		 ||
	//		 ( (getInputSet(l)->getMaxDur()!=0) && 
	//		 (input->getInputSet(j)->getDuration()>getInputSet(l)->getMaxDur()) )
	//		 ) {
	//		return false;
	//		}
	//	if ( ( (input->getInputSet(j)->getMinDur()!=0) && 
	//		 (getInputSet(l)->getDuration()<input->getInputSet(j)->getMinDur()) )
	//		 ||
	//		 ( (input->getInputSet(j)->getMaxDur()!=0) && 
	//		 (getInputSet(l)->getDuration()>input->getInputSet(j)->getMaxDur()) )
	//		 ) {
	//		return false;
	//		}
	if (printDebug) 
			cout << " INPUTS COMPARE RETURNED TRUE\n";
	return true;
}




