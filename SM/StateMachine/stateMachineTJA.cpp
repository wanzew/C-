#include "stateMachineTJA.hpp"

StateMachineTJA::StateMachineTJA() 
	: StateMachine<LatS_State, LatFcp>(&m_offState, SM_TJA)
{
	m_offState.setStateId(LatS_Off);
	m_passiveState.setStateId(LatS_Passive);
	m_activeRequestState.setStateId(LatS_ActiveRequest);
	m_activeControlState.setStateId(LatS_ActiveControl);
	m_blindnessState.setStateId(LatS_Blindness);
	m_failureState.setStateId(LatS_Failure);
}

void StateMachineTJA::init()
{}

void StateMachineTJA::operate() {

	setPreviousCycleState(m_currentState);
	m_currentState->handleState(this);

	if (
		(LatS_ActiveControl == m_currentState->getStateId())
		|| (LatS_ActiveRequest == m_currentState->getStateId())
		) {
		setArbitrationRequest(true);
	}
	else {
		setArbitrationRequest(false);
	}

}