#ifndef ENUM_HPP
#define ENUM_HPP

enum StateMachine_Type
{
	SM_ACC = 0,
	SM_TJA,
};

enum LatS_State
{
	LatS_Off = 0,
	LatS_Passive,
	LatS_ActiveRequest,
	LatS_ActiveControl,
	LatS_Blindness,
	LatS_Failure,
};


#endif // !ENUM_HPP
