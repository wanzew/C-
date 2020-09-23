#include "FailureState.hpp"

void LatFailureState::handleState(StateMachineTJA* pcontext)
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


	if (fcp->getOffConditionFulfilled()) {
		pcontext->setState(pcontext->getOffState());
		return;
	}
}