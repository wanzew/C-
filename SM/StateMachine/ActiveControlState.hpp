#ifndef ActiveControlSTATE_HPP
#define ActiveControlSTATE_HPP

#include "latState.hpp"
#include "../Conditions/latFcp.hpp"
#include "../StateMachine/stateMachineTJA.hpp"

class LatActiveControlState : public LatState
{
public:
	LatActiveControlState() {}

	virtual ~LatActiveControlState() {}

	virtual void handleState(StateMachineTJA* pcontext) override;

private:
	LatActiveControlState(const LatActiveControlState&);
	LatActiveControlState& operator=(const LatActiveControlState&);
};


#endif // !OFFSTATE_HPP

