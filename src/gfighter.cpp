
#include <iostream>
#include "gfighter.h"

//-----------------------------------------------------------------------------

// The global pointer to gfighter
GFighter *gfighter;
GFighter *global_system() {
		return gfighter;
}

GFighter::GFighter () {
	levelName="";
	p1Name="";
	p2Name="";

	level   = NULL;
	player1 = NULL;
	player2 = NULL;
	level_vfs_path = "";
	current_input = NULL;
	screenbox = new GFRect();
}

GFighter::~GFighter ()
{	
	/*if (level_vfs_path) delete level_vfs_path;
	if (player1) delete player1;
	if (player2) delete player2;
	if (level) delete level;*/
	delete screenbox;
}

GFLevel  *
GFighter::LoadLevel(const char *vfs_path) {
	GFLevel  *l;
	string full_vfs_path;	
	full_vfs_path = GFSystem::getInstance()->getAppPath();
	full_vfs_path += "/levels/";
	full_vfs_path += vfs_path;
	full_vfs_path += "/";		
	level_vfs_path = full_vfs_path;

	/*cout << "exists = " << vfs->Exists("/levels/level01/level.xml") << "\n";
	csRef<iStrVector> stra = vfs->FindFiles  ("/levels/level01/");
	cout << "stra->length() = " << stra->Length() << "\n";
	for (int i=0; i< stra->Length(); i++) {
		cout << "stra["<<i<<"]="<<stra->Get(i)<<"\n";
	}*/
	
	l = new GFLevel();
	if (!l->LoadFromFile(full_vfs_path)) {
		delete l; 
		cerr << "Error loading file '" << full_vfs_path << "'\n";
		return NULL;
	}
	return l;
}

GFSprite *
GFighter::LoadSprite(const char *vfs_path) {
	GFSprite *spr;	

	string full_vfs_path;	
	full_vfs_path = GFSystem::getInstance()->getAppPath();
	full_vfs_path+="/sprites/";
	full_vfs_path+=vfs_path;
	full_vfs_path+="/";		

	spr = new GFSprite();
	if (!spr->LoadFromFile(full_vfs_path)) {
		delete spr; 
		cerr << "Error loading file '" << full_vfs_path << "'\n";
		return NULL;
	}
	return spr;	
}

bool GFighter::LoadLevels() {
	cout << "Loading level: name = '" << levelName << "'\n";
	level = LoadLevel(levelName);
	if (!level) {
		cerr << "Error loading level";
		return false ;
	}
	return true;
}

bool GFighter::LoadPlayers() {
	// Load p1
	cout << "Loading player 1: p1Name = " << p1Name << "\n";
	player1 = LoadSprite(p1Name);
	if (!player1) {
		cerr << "Error loading player 1";
		return false;
	}
	player1->setY(level->getYGround());
	player1->setX(-200);

	// Load p2
	cout << "Loading player 2: p2Name = " << p2Name << "\n";
	player2 = LoadSprite(p2Name);
	if (!player2) {
		cerr << "Error loading player 2";
		return false;
	}
	player2->setY(level->getYGround());
	player2->setX(200);

	return true;
}

bool GFighter::LoadInputs(){
	current_input = new GFInput("gameinput");
	if (!current_input) {
		cerr << "Error creating current_input handler";
		return false;
	}
	return true;
}

void GFighter::processFrame ()
{
	// First get elapsed time from the virtual clock.
	//static csTicks elapsed_time=0;
	static unsigned int elapsed_time=0;
	//TODO - implement line bellow using irrlicht
	//cout << "elapsed_time = "<<  elapsed_time << "\n";
	elapsed_time += GFSystem::getInstance()->getElapsedTime();
	//cout << "elapsed_time = "<<  elapsed_time << "\n";
	//Number of miliseconds to wait (1/20 seconds)
	const int periodMS = 1000/60;
	//const int periodMS = 1000;
	if (elapsed_time<(periodMS)) return;
	elapsed_time = elapsed_time % (periodMS);	

	current_input->VerifyKeyboard();

	static int lastinputtype=-1;
	//Call input triggers, if should so
	//cout << "----------------------------------\nComparing player input... \n";
	for (int i=0; i<player1->getNumInputs(); i++) { 
		// Check each player input
		GFInput *pinput = player1->getInput(i);
		if (pinput->compareTo(current_input)) {	//input detected
			if (lastinputtype!=0) { //checks if this is the current input being processed
				player1->setCurrentInput(i); //it isn't, process it
				player1->CallTrigger(pinput->getTrigger());

				lastinputtype=0;
			}
			break;
		} else if (i==player1->getCurrentInput()) {
			//First, execute Release trigger from last input
			if (lastinputtype!=1) { //check if this is the current input being processed 
				player1->CallTrigger(
					player1->getInput(player1->getCurrentInput() )->getTriggerRelease());			

				lastinputtype=1; 
			}
		}
	}
	
	GFSystem::getInstance()->beginDraw();
	//g3d->BeginDraw(CSDRAW_2DGRAPHICS | CSDRAW_CLEARSCREEN);
	//g3d->Clear(g2d->FindRGB(0,0,0));
	getScreenBox();
	level->setOffsetX((screenbox->xmax + screenbox->xmin)/2);	
	level->setOffsetY((int)(player1->getY() + player2->getY())/2
		- (level->getYGround())
		);	
	player1->ProcessTrajectory();
	player2->ProcessTrajectory();
	//flip according to the x position
	if (player1->getX() <= player2->getX() ) {
		player1->setFlip(false);
		player2->setFlip(true);
	} else {
		player1->setFlip(true);
		player2->setFlip(false);
	}	
	player1->verifyCollisions(player2);
	
	level->Render(1, 100000);	
	player1->Render();	
	player2->Render();
	level->Render(0, 1);	

	GFSystem::getInstance()->endDraw();
}

bool GFighter::initialize (int argc, char* argv[]) {
	//Set reference to this as the global system
	gfighter = this;

	if (argc<4) {
		cerr << "ERROR: Unsuficiet number of arguments!";
		return false;
	}	
	levelName = argv[1];
	p1Name		=	argv[2];
	p2Name		=	argv[3];

	return true;
}

void GFighter::gameLoop()
{
	while (GFSystem::getInstance()->run()) {
		if (GFSystem::getInstance()->getKeyPressedState(GFSystem::ESC))
			break;
		processFrame();
	}
}
void
GFighter::run() {
	LoadLevels();
	LoadPlayers();
	LoadInputs();

  gameLoop();
}

/*---------------------------------------------------------------------*
 * Main function
 *---------------------------------------------------------------------*/
int main (int argc, char* argv[])
{
	for (int i=0; i<argc; i++) cout << "argv[i]=" << argv[i] << "\n";
	GFSystem::getInstance()->initialize(argc, argv, 800,600);
	
	GFighter gf;
	gf.initialize(argc, argv);
	gf.run();

	GFSystem::getInstance()->finish();
	return 0;
}


