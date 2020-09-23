#ifndef ACTIVEREQUEST_HPP
#define ACTIVEREQUEST_HPP

#include "latState.hpp"
#include "../Conditions/latFcp.hpp"
#include "../StateMachine/stateMachineTJA.hpp"

class LatActiveRequestState : public LatState
{
public:
	LatActiveRequestState() {}

	virtual ~LatActiveRequestState() {}

	virtual void handleState(StateMachineTJA* pcontext) override;

private:
	LatActiveRequestState(const LatActiveRequestState&);
	LatActiveRequestState& operator=(const LatActiveRequestState&);
};


#endif // !ACTIVEREQUEST_HPP

