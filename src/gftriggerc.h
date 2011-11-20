#ifndef __GF_TRIGGER_C__
#define __GF_TRIGGER_C__

#include <stdio.h>
#include <string.h>

//Functions 
#ifdef __cplusplus
extern "C" {		
#endif
	typedef int  (*TstateMatchValue)(char *name, char *value);	    	
	typedef void (*TsetStateValue)(char *name, char *value);	    	    
#ifdef __cplusplus
}
#endif

// Structures
typedef struct _trigger_data {
	int px, py;
	int pflip;
	char pcurrent_action[1024];
	int acurrent_frame;
	char pcurrent_trajectory[1024];	
	int tcurrent_point;
	TstateMatchValue stateMatchValue;
	#define _stateMatchValue (*(data->stateMatchValue))
	TsetStateValue setStateValue;	
	#define _setStateValue (*(data->setStateValue))
} trigger_data;


#define SET_ACTION(X) strcpy(data->pcurrent_action, X)
#define SET_TRAJ(X) strcpy(data->pcurrent_trajectory, X)
#define SET_STATE(X,Y) _setStateValue(X, Y)
#define CHECK_STATE(X,Y) _stateMatchValue(X, Y)

#endif //__GF_TRIGGER_C__
