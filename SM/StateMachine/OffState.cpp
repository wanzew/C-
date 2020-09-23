#include "OffState.hpp"

void LatOffState::handleState(StateMachineTJA* pcontext)
{
	LatFcp* fcp = pcontext->getFcp();


	if (fcp->getFailureConditionFulfilled()) {
		pcontext->setState(pcontext->getFailureState());
		return;
	}

	if (fcp->getBlindnessConditionFulfilled()) {
		pcontext->setState(pcontext->getBlindnessState());
		return;
	}

	if (!fcp->getPassiveConditionFulfilled()) {
		pcontext->setState(pcontext->getPassiveState());
		return;
	}

}