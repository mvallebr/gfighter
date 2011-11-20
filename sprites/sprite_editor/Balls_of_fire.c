
if (_stateMatchValue("state1", "on_traj1")) {
	strcpy(data->pcurrent_action, "Balls-of-Fire");
	strcpy(data->pcurrent_trajectory, "Balls-of-Fire");
	data->acurrent_frame = 0;
}

return 0;
