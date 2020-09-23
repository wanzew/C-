#ifndef FailureSTATE_HPP
#define FailureSTATE_HPP

#include "latState.hpp"
#include "../Conditions/latFcp.hpp"
#include "../StateMachine/stateMachineTJA.hpp"

class LatFailureState : public LatState
{
public:
	LatFailureState() {}

	virtual ~LatFailureState() {}

	virtual void handleState(StateMachineTJA* pcontext) override;

private:
	LatFailureState(const LatFailureState&);
	LatFailureState& operator=(const LatFailureState&);
};


#endif // !OFFSTATE_HPP

