#ifndef OFFSTATE_HPP
#define OFFSTATE_HPP

#include "latState.hpp"
#include "../Conditions/latFcp.hpp"
#include "../StateMachine/stateMachineTJA.hpp"

class LatOffState : public LatState
{
public:
	LatOffState() {}

	virtual ~LatOffState() {}

	virtual void handleState(StateMachineTJA* pcontext) override;

private:
	LatOffState(const LatOffState&);
	LatOffState& operator=(const LatOffState&);
};


#endif // !OFFSTATE_HPP

