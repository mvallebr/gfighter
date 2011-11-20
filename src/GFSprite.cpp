
#include <exception>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>

#include "GFSprite.h"
#include "gfighter.h"
#include "GFXmlParser.h"
#include "GFVector.h"

using std::string;
using std::cout;
using std::istringstream;
using std::map;
using std::transform;
using std::tolower;

GFSprite *current_sprite=NULL;
void setCurrentSprite(GFSprite *sp) {
	current_sprite = sp;
}
GFSprite *getCurrentSprite() {
	return current_sprite;
}

void GFSprite::GFSPrite(){	
	x = y = 0;
	flip = false;

	current_action = 0;
	current_input=-1;
	current_trajectory=0;
	aframes=1.0;
}

GFSprite::~ GFSprite() {

}


int 
GFSprite::LoadTriggerData(GFTrigger *trigger) {
	//GFighter *gf;
	//gf = global_system();
	GFSprite *sprite = this;
	trigger_data *data;
	data = &(trigger->data);
	data->px = (int)sprite->getX();
	data->py = (int)sprite->getY();
	data->pflip = sprite->getFlip();	
	GFAction *action = sprite->getAction(sprite->getCurrentAction());
	GFTrajectory *trajectory = sprite->getTrajectory(sprite->getCurrentTrajectory());
	strcpy(data->pcurrent_action, (char *) action->getName());
	strcpy(data->pcurrent_trajectory, (char *) trajectory->getName());
	data->acurrent_frame = 0;
	data->tcurrent_point = 0;
	cout << "@@@ data->pcurrent_action loaded to " << data->pcurrent_action << " action->getName()= " << action->getName() <<"\n";
	cout << "@@@ data->pcurrent_trajectory loaded to " << data->pcurrent_trajectory << " trajectory->getName()= " << trajectory->getName() <<"\n";
	if (action)
		data->acurrent_frame = action->getCurrentFrame();
	if (trajectory)
		data->tcurrent_point = trajectory->getCurrentPoint();
	return 0;
}

int 
GFSprite::SaveTriggerData(GFTrigger *trigger) {
	//GFighter *gf;
	//gf = global_system();
	GFSprite *sprite = this;
	trigger_data *data;
	data = &(trigger->data);
	sprite->setX(data->px);
	sprite->setY(data->py);
	sprite->setFlip( (data->pflip==1) ? true : false);

	int curAction = sprite->FindAction(data->pcurrent_action);
	if (curAction>-1)
		sprite->setCurrentAction(curAction);
	else
		cerr << "ERROR! Action not found: '" << data->pcurrent_action << "' \n" ;
	sprite->setCurrentTrajectory(sprite->FindTrajectory(data->pcurrent_trajectory));

	GFAction *action = sprite->getAction(sprite->getCurrentAction());
	GFTrajectory *trajectory = sprite->getTrajectory(sprite->getCurrentTrajectory());
	
	cout << "@@@ data->pcurrent_action changed to " << curAction << ": " << data->pcurrent_action << " action->getName()= " << action->getName() <<"\n";
	cout << "@@@ data->pcurrent_trajectory changed to " << data->pcurrent_trajectory << " trajectory->getName()= " << trajectory->getName() <<"\n";

	//trajectory or action has changed
	if ( (action->getCurrentFrame()!=data->acurrent_frame) 	|| 
			(trajectory->getCurrentPoint()!=data->tcurrent_point) ) {
		action->setCurrentAdvFrame(0.0);
		trajectory->setPointFrames(0.0);
		
	}
	if (action)
		action->setCurrentFrame(data->acurrent_frame);
	if (action->getCurrentFrame() >= action->getNumFrames())
		action->setCurrentFrame(0);
	if (trajectory)
		trajectory->setCurrentPoint(data->tcurrent_point);
	if (trajectory->getCurrentPoint() >= trajectory->getNumPoints())
		trajectory->setCurrentPoint(0);
	return 0;
}


bool 
GFSprite::LoadFromFile(string full_vfs_path) {	
	string path =	full_vfs_path;
	path += "sprite.xml";
	cout << full_vfs_path << "\n";
	vfspath = full_vfs_path;

	cout << "Loading file '" << path.c_str() << "'...\n";
	GFXmlDocument *xmldoc = GFXmlParser::getInstance()->parse(path.c_str());

	//Now really load everything
	GFXmlElement *rootNode = xmldoc->getRootElement();
	//  -------------  screen -------------
	GFXmlElement *sprite = rootNode->getChild("sprite"); // get sprite
	GFXmlElement *eactions = rootNode->getChild("Actions");// get Actions
	// ----------------------------------------
	//Iterate over Actions childs (action tag)
	GF_XML_MMAP childs =  eactions->getChilds();
	GF_XML_MMAP::iterator iter;   
  for( iter = childs.begin(); iter != childs.end(); iter++ ) {
		GFXmlElement *action = iter->second;
		//Action Attributes
		GFAction *newaction = new GFAction(action->getAttributeValueAsString("name").c_str());									
		newaction->setNextAction(action->getAttributeValueAsString("nextaction").c_str());				
		newaction->setSoundFile(action->getAttributeValueAsString("soundfile").c_str());				
		newaction->setTrigger(action->getAttributeValueAsString("trigger").c_str());
		// ----------------------------------------
		//Iterate over action childs (frame tag)
		GF_XML_MMAP childs2 =  action->getChilds();
		GF_XML_MMAP::iterator iter2;   
		for( iter2 = childs2.begin(); iter2 != childs2.end(); iter2++ ) {
			GFXmlElement *frame = iter2->second;
			//Frame Attributes	
			string name, state, imagefile;
			int centerx = 0; int centery = 0;
			string vfsfile = vfspath;

			name = frame->getAttributeValueAsString("name");				
			cout << "	Scaning Frame '" << name << "'...\n";
			state = frame->getAttributeValueAsString("state");
			imagefile = frame->getAttributeValueAsString("imagefile");
			centerx = frame->getAttributeValueAsInteger("centerx");
			centery = frame->getAttributeValueAsInteger("centery");
			vfsfile += "images/";
			vfsfile += imagefile;
			newaction->addFrame(name.c_str(), state.c_str(), vfsfile.c_str(), centerx, centery);
			// ----------------------------------------
			//Iterate over frame childs (poly tag)
			GF_XML_MMAP childs3 =  frame->getChilds();
			GF_XML_MMAP::iterator iter3;   
			for( iter3 = childs3.begin(); iter3 != childs3.end(); iter3++ ) {
				GFXmlElement *poly = iter3->second;
				//Poly attributes
				GFPoly *newpoly;
				string pname, ptrigger;
				int priority;
				int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
								
				pname = poly->getAttributeValueAsString("name");	
				cout << "	Scaning Poly '" << pname << "'...\n";
				ptrigger = poly->getAttributeValueAsString("trigger");
				newpoly = new GFPoly(pname.c_str());
				newpoly->setTrigger(ptrigger.c_str());
				priority = poly->getAttributeValueAsInteger("priority");
				p1x = poly->getAttributeValueAsInteger("p1x");
				p1y = poly->getAttributeValueAsInteger("p1y");
				p2x = poly->getAttributeValueAsInteger("p2x");
				p2y = poly->getAttributeValueAsInteger("p2y");
				p3x = poly->getAttributeValueAsInteger("p3x");
				p3y = poly->getAttributeValueAsInteger("p3y");
				p4x = poly->getAttributeValueAsInteger("p4x");
				p4y = poly->getAttributeValueAsInteger("p4y");
				newpoly->setPriority(priority);
				newpoly->setVectorPoint(0, p1x, p1y);
				newpoly->setVectorPoint(1, p2x, p2y);
				newpoly->setVectorPoint(2, p3x, p3y);
				newpoly->setVectorPoint(3, p4x, p4y);
				cout << "Added poly to frame, " << 
					" p1x=" << p1x << " p1y=" << p1y << 
					" p2x=" << p2x << " p2y=" << p2y << 
					" p3x=" << p3x << " p3y=" << p3y << 
					" p4x=" << p4x << " p4y=" << p4y << 
					" priority =" << priority << 
					" trigger  =" << ptrigger << 
					"\n";
				newaction->getFrame(newaction->getNumFrames()-1)->addPoly(newpoly);
			}
			// ----------------------------------------	
		}
		// ----------------------------------------
		actions.Push(newaction);	
	}
	// ----------------------------------------
	
	GFXmlElement *etrajectories = rootNode->getChild("Trajectories");// get Trajectories
	// ----------------------------------------
	//Iterate over Trajectories childs (TRAJECTORY tag)
	GF_XML_MMAP childs4 =  etrajectories->getChilds();  
	cout << "SIZE " << childs4.size() << "\n";
	GF_XML_MMAP::iterator iter4;  
  for( iter4 = childs4.begin(); iter4 != childs4.end(); iter4++ ) {
		GFXmlElement *trajectory = iter4->second;
		//TRAJECTORY Attributes
		string name = trajectory->getAttributeValueAsString("name");
		GFTrajectory *newtrajectory = new GFTrajectory(	name.c_str());
		newtrajectory->setTrigger(											trajectory->getAttributeValueAsString("trigger").c_str());
		newtrajectory->setNextTraj(											trajectory->getAttributeValueAsString("nexttraj").c_str());
		newtrajectory->setWidth(												trajectory->getAttributeValueAsInteger("width"));
		newtrajectory->setHeight(												trajectory->getAttributeValueAsInteger("height"));
		cout << "Loading trajectory, name='" << newtrajectory->getName() 
			<< "', trigger='" << newtrajectory->getTrigger() 
			<< "', next_traj='" << newtrajectory->getNextTraj() 
			<< "', width=" << newtrajectory->getWidth()
			<< ", height=" << newtrajectory->getHeight() 
			<< "\n \tpoints:\n";
		// ----------------------------------------
		//Iterate over TRAJECTORY childs (POINT tag)
		GF_XML_MMAP childs5 =  trajectory->getChilds();
		GF_XML_MMAP::iterator iter5;  
		for( iter5 = childs5.begin(); iter5 != childs5.end(); iter5++ ) {
			GFXmlElement *point = iter5->second;
			GFTrajPoint *newtrajpoint = new GFTrajPoint(	point->getAttributeValueAsString("name").c_str());					
			newtrajpoint->setAFrames(											point->getAttributeValueAsInteger("aframes"));
			newtrajpoint->setTime(												point->getAttributeValueAsInteger("time"));
			newtrajpoint->setX(														point->getAttributeValueAsInteger("x"));
			newtrajpoint->setY(														point->getAttributeValueAsInteger("y"));	
			cout << "Adding point to trajectory '" << newtrajectory->getName() 
				<< "': point name='" << newtrajpoint->getName() 
				<< "', aframes=" << newtrajpoint->getAFrames()
				<< ", time=" << newtrajpoint->getTime() 
				<< ", x=" << newtrajpoint->getX()
				<< ", y=" << newtrajpoint->getY() 
				<< "\n";
			newtrajectory->addPoint(newtrajpoint);
		}
		// ----------------------------------------
		trajectories.Push(newtrajectory);
	}
	// ----------------------------------------


	GFXmlElement *etriggers = rootNode->getChild("Triggers");// get Actions
	// ----------------------------------------
	//Iterate over Triggers childs (TRIGGER tag)
	GF_XML_MMAP childs6 =  etriggers->getChilds(); 
	GF_XML_MMAP::iterator iter6;  
  for( iter6 = childs6.begin(); iter6 != childs6.end(); iter6++ ) {
		GFXmlElement *trigger = iter6->second;
		//TRIGGER Attributes
			cout << "loading trigger "<< vfspath << "\n";
			string trigName = trigger->getAttributeValueAsString("name");
			GFTrigger *newtrigger = new GFTrigger(
				trigName, 
				vfspath
				);
			triggers.Push(newtrigger);
	}
	// ----------------------------------------

	GFXmlElement *einputs = rootNode->getChild("Inputs");// get Inputs
	// ----------------------------------------
	//Iterate over Inputs childs (INPUT tag)
	GF_XML_MMAP childs7 =  einputs->getChilds(); 
	GF_XML_MMAP::iterator iter7;  
  for( iter7 = childs7.begin(); iter7 != childs7.end(); iter7++ ) {
		GFXmlElement *input = iter7->second;
		//INPUT Attributes
		int numberOfInputsets=0, i=0;
		GFInput *newinput = new GFInput(	input->getAttributeValueAsString("name").c_str());
		newinput->setTrigger(							input->getAttributeValueAsString("trigger").c_str());
		newinput->setTriggerRelease(			input->getAttributeValueAsString("triggerRelease").c_str());
		cout << "loading input "	<<	input->getAttributeValueAsString("name")
			<< " trigger= '"	<<	newinput->getTrigger()
			<< "' trigger release= '"	<<	newinput->getTriggerRelease()
			<< "'\n";
		// ----------------------------------------
		//Iterate over INPUT childs (INPUTSET tag)
		//First, calc the last non zero inputset
		GF_XML_MMAP childs8 =  input->getChilds();
		GF_XML_MMAP::iterator iter8;  
		for( iter8 = childs8.begin(); iter8 != childs8.end(); iter8++ ) {
			GFXmlElement *inputset = iter8->second;
			i++;
			GFInputSet *newinputset= new GFInputSet();
			newinputset->setLeftArrow(	inputset->getAttributeValueAsBool("LEFT"));
			newinputset->setRightArrow(	inputset->getAttributeValueAsBool("RIGHT"));
			newinputset->setUpArrow(		inputset->getAttributeValueAsBool("UP"));
			newinputset->setDownArrow(	inputset->getAttributeValueAsBool("DOWN"));
			newinputset->setA(	inputset->getAttributeValueAsBool("A"));
			newinputset->setB(	inputset->getAttributeValueAsBool("B"));
			newinputset->setC(	inputset->getAttributeValueAsBool("C"));
			newinputset->setD(	inputset->getAttributeValueAsBool("D"));
			newinputset->setMinDur(	inputset->getAttributeValueAsInteger("mindur"));
			newinputset->setMaxDur(	inputset->getAttributeValueAsInteger("maxdur"));
			if (!newinputset->isEverythingFalse()) {
				numberOfInputsets = i;
			}
			delete newinputset;
		}
		// ----------------------------------------
		//Iterate over INPUT childs (INPUTSET tag)
		//Now, really scan
		i = 0; 
		for( iter8 = childs8.begin(); iter8 != childs8.end(); iter8++ ) {
			GFXmlElement *inputset = iter8->second;
			i++;
			if (i>numberOfInputsets) break;
			GFInputSet *newinputset= new GFInputSet();
			newinputset->setLeftArrow(	inputset->getAttributeValueAsBool("LEFT"));
			newinputset->setRightArrow(	inputset->getAttributeValueAsBool("RIGHT"));
			newinputset->setUpArrow(		inputset->getAttributeValueAsBool("UP"));
			newinputset->setDownArrow(	inputset->getAttributeValueAsBool("DOWN"));
			newinputset->setA(	inputset->getAttributeValueAsBool("A"));
			newinputset->setB(	inputset->getAttributeValueAsBool("B"));
			newinputset->setC(	inputset->getAttributeValueAsBool("C"));
			newinputset->setD(	inputset->getAttributeValueAsBool("D"));
			newinputset->setMinDur(	inputset->getAttributeValueAsInteger("mindur"));
			newinputset->setMaxDur(	inputset->getAttributeValueAsInteger("maxdur"));
			newinput->inputsets.Push(newinputset);
			cout << "\n****Loaded inputset: \n";
			newinputset->Print();
		}
		// ----------------------------------------
		cout << "**** **** Registered new input, len=" << newinput->inputsets.Length() << "\n";
		//newinput->setCurrent(0);
		inputs.Push(newinput);
	}
	// ----------------------------------------
	current_action = 0;
	current_trajectory = 0;
	flip = false;
	cout.flush();
	return true;
}

bool 
GFSprite::ProcessTrajectory() {
	double frames=0;
	int old;
	GFighter *gf;
	gf = global_system();

	old = current_trajectory;
	frames = getTrajectory(old)->advanceInFrames(1.0);
	//cout << "frames = " << frames << "\t";
	const GFVector result = getTrajectory(old)->getVector();
	aframes = getTrajectory(old)->getAFrames();
	setX((getX()+result.x));
	setY((getY()+result.y));
	//cout << "x=" << result.x  << "\n";
	cout.flush();
	if  (getY() < gf->getLevel()->getYGround() ){
		setY(gf->getLevel()->getYGround());
		//cout << "teste\n";
	}

	//cout << "teste2" << result.y << "\n";
	while (frames>0.0) { //Reached the end of the trajectory, go to next and call trigger		
		const char * trajname = getTrajectory(current_trajectory)->getNextTraj();
		current_trajectory = FindTrajectory(trajname);
		if (current_trajectory<0) {
			cerr << "FATAL ERROR! Trajectory not found: " << trajname;
			current_trajectory = old;
		}
		frames = getTrajectory(current_trajectory)->advanceInFrames(1.0);
		const GFVector result2 = getTrajectory(current_trajectory)->getVector();
		aframes = getTrajectory(current_trajectory)->getAFrames();
		setX((getX()+result2.x));
		setY((getY()+result2.y));
		if  (getY() < gf->getLevel()->getYGround() ){
			setY(gf->getLevel()->getYGround());
		}
		//cout << "frames = " << frames << "\t";
		CallTrigger(getTrajectory(old)->getTrigger());
		return true;
	}	
	return false;
}

void 
GFSprite::Render() {
	int old;
	if ((current_action<0) ||  (current_action>actions.Length())){
		cerr << "FATAL ERROR: There is an error on the sprite! It entered on no action! (action "<< 
			current_action << ")\n";		
		current_action = 0;
		return;
	}		
	if (getAction(current_action)->Render(flip, (int)x, (int)y, aframes)) {
		old = current_action;
		current_action = FindAction(getAction(current_action)->getNextAction());
		getAction(current_action)->setCurrentFrame(0);
		CallTrigger(getAction(old)->getTrigger());
	}
}

int 
GFSprite::FindAction(const char *actionname) {	
	if (actionname[0]=='\0') return current_action;
	for (int i=0; i<actions.Length(); i++) {
		string a(getAction(i)->getName()), b(actionname);
		transform (a.begin(), a.end(), a.begin(), tolower);
		transform (b.begin(), b.end(), b.begin(), tolower);
		if (a==b)
			return i;
	}
	return -1;
}

int 
GFSprite::FindTrajectory(const char *trajectoryname) {	
	if (trajectoryname[0]=='\0') return current_trajectory;
	for (int i=0; i<trajectories.Length(); i++) {
		string a(getTrajectory(i)->getName()), b(trajectoryname);
		transform (a.begin(), a.end(), a.begin(), tolower);
		transform (b.begin(), b.end(), b.begin(), tolower);
		if (a==b)
			return i;
	}
	return -1;
}

int 
GFSprite::CallTrigger(const char *triggername) {
	int tid, ret;
	//cout <<"Calling trigger '"<< triggername << "' \n";
	//cout.flush();
	if ((tid=FindTrigger(triggername))==-1) {
		if ((triggername!=NULL) && (strlen(triggername))>0) {
			cerr << "Trigger '" << triggername << "' not found!!\n'";
			cerr.flush();
		}
		return -1;
	}
	GFTrigger *trigger = (GFTrigger *)(triggers.Get(tid));	
	setCurrentSprite(this);
	LoadTriggerData (trigger);
	ret = trigger->CallTrigger();
	SaveTriggerData (trigger);
	setCurrentSprite(NULL);
	return ret;
}

int 
GFSprite::FindTrigger(const char *triggername) {	
	for (int i=0; i<triggers.Length(); i++) {
		string a(getTrigger(i)->getName()), b(triggername);
		transform (a.begin(), a.end(), a.begin(), tolower);
		transform (b.begin(), b.end(), b.begin(), tolower);
		if ((triggername!=NULL) && (a==b)) {
			//cout << "DEBUG> true when comparing " << triggers.Get(i).getName() << " and " << triggername << "\n";
			return i;
		}
	}
	return -1;
}

void 
GFSprite::addState  (char *name, char *value) {
	int i;
	i = findState(name);
	if (i>=0) { // have found it
		cerr << "Error: trying to add alredy existent state named '"
			<< name << "'. Setting its value instead.\n";
		setStateValue(name, value);
		return ;
	}
	GFState *newstate;
	newstate = new GFState(name, value);
	states.Push(newstate);
}

int  
GFSprite::findState (char * name) {
	int i;	
	if (!name) return -1;
	for (i=0; i<states.Length(); i++) {
		string a(name), b(getState(i)->getName());
		transform (a.begin(), a.end(), a.begin(), tolower);
		transform (b.begin(), b.end(), b.begin(), tolower);
		if (a==b)
			return i;
	}
	return -1;
}
void 
GFSprite::setStateValue(char *name, char *value) {
	int i;
	i = findState(name);
	cout << "Setting value of the state named '" << name << "' to '" << value << "'\n";
	if (i<0) { // haven´t found it
		cout << "Warning: state named '"
			<< name << "' not found, creating it before setting its value.\n";
		addState(name, value);				
	} else { //It exists
		getState(i)->setValue(value);
	}	
}
const char *
GFSprite::getStateValue(char *name) {
	int i;
	const char *returnvalue;
	i = findState(name);
	cout << "Getting value of the state named '" << name << "'\n";
	if (i<0) { // have found it
		cerr << "Error: trying to get value from non existent state named '"
			<< name << "'. Create it or set its value first!\n";		
		returnvalue = NULL;
	} else { //It exists
		returnvalue = getState(i)->getValue();
	}		
	cout << "Returning value '";
	if (returnvalue==NULL) cout << "NULL"; else cout << returnvalue ;
	cout << "'\n";
	return returnvalue;
}

void GFSprite::verifyCollisions(GFSprite *other) {
	char *trigger_name[2]= {NULL, NULL};
	getAction(current_action)->verifyCollisions(
		other->getAction(other->current_action),
		trigger_name[0], trigger_name[1]
		);
	if (trigger_name[0] != NULL) {
		CallTrigger(trigger_name[0]);
	}
	if (trigger_name[1] != NULL) {
		other->CallTrigger(trigger_name[0]);
	}
}