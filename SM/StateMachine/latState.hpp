#ifndef LATSTATE_HPP
#define LATSTATE_HPP

#include "abstractState.hpp"
#include "../include/enum.hpp"

class StateMachineTJA;

class LatState : public AbstractState<LatS_State, StateMachineTJA>
{
public:
	LatState(){}
	//virtual void handleState(StateMachineTJA* pcontext);
};

#endif // !LATSTATE_HPP
