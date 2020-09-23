#include "ActiveRequestState.hpp"

void LatActiveRequestState::handleState(StateMachineTJA* pcontext)
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

	if (fcp->getPassiveConditionFulfilled()) {
		pcontext->setState(pcontext->getPassiveState());
		return;
	}

	if (!fcp->getActiveTiplConditionFulfilled()) {
		pcontext->setState(pcontext->getActiveControlState());
		return;
	}
}