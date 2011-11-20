#include <gftriggerc.h>
int walkright(trigger_data *data) {

SET_TRAJ("walkright");

return 0;

}

int walkleft(trigger_data *data) {

SET_TRAJ("walkleft"); 
 
return 0;

}

int crouch(trigger_data *data) {

SET_ACTION("crouch");

return 0;

}

int walkrightRelease(trigger_data *data) {


SET_TRAJ("stand");

return 0;

}

int walkleftRelease(trigger_data *data) {


SET_TRAJ("stand");
return 0;

}

int crouchRelease(trigger_data *data) {


SET_ACTION("getup");

return 0;

}

int jump(trigger_data *data) {

SET_TRAJ("jump");

return 0;

}

int jumpRelease(trigger_data *data) {


return 0;

}

int jumpRight(trigger_data *data) {
 
SET_TRAJ("jumpRight");
return 0; 

}

int jumpLeft(trigger_data *data) {
 
SET_TRAJ("jumpLeft");

return 0; 

}

