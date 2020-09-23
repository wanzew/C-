#ifndef BLINDNESSSTATE_HPP
#define BLINDNESSSTATE_HPP

#include "latState.hpp"
#include "../Conditions/latFcp.hpp"
#include "../StateMachine/stateMachineTJA.hpp"

class LatBlindnessState : public LatState
{
public:
	LatBlindnessState() {}

	virtual ~LatBlindnessState() {}

	virtual void handleState(StateMachineTJA* pcontext) override;

private:
	LatBlindnessState(const LatBlindnessState&);
	LatBlindnessState& operator=(const LatBlindnessState&);
};


#endif // !OFFSTATE_HPP

