#ifndef PASSIVESTATE_HPP
#define PASSIVESTATE_HPP

#include "latState.hpp"
#include "../Conditions/latFcp.hpp"
#include "../StateMachine/stateMachineTJA.hpp"

class LatPassiveState : public LatState
{
public:
	LatPassiveState() {}

	virtual ~LatPassiveState() {}

	virtual void handleState(StateMachineTJA* pcontext) override;

private:
	LatPassiveState(const LatPassiveState&);
	LatPassiveState& operator=(const LatPassiveState&);
};

#endif // !PASSIVESTATE_HPP
