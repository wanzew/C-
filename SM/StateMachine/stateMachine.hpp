#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "../include/enum.hpp"
#include "stateMichineInterface.hpp"


template <class StateType, class FcpType>
class StateMachine : public StateMachineInterface
{
public:
	StateMachine(StateType* pState, StateMachine_Type stateMachineType)
		: m_currentState(pState)
		, m_pPreviousCycleState(pState)
		, m_pLastState(pState)
		, m_arbitrationRequest(false)
		, m_stateMachineType(stateMachineType)
		, m_fcp()
	{

	}

	void preProcessing(const Fip& fip) override { m_fcp.processCond(fip); }

	void setState(StateType* pState) {
		m_pLastState = pState;
		m_currentState = pState;
	}

	void setPreviousCycleState(StateType* pState) {
		m_pPreviousCycleState = pState;
	}

	int getCurrentStateID() const override {
		return static_cast<int>(m_currentState->getStateId());
	}

	int getPreviousCycleStateID() const override {
		return static_cast<int>(m_pPreviousCycleState->getStateId());
	}
	
	FcpType* getFcp() override {
		return &m_fcp;
	}

	FcpType* getFcp() const { return &m_fcp; }

	void setArbitrationRequest(bool value) { m_arbitrationRequest = value; }
	bool setArbitrationRequest() { return m_arbitrationRequest; }

protected:
	StateType*			m_currentState;
	StateType*			m_pLastState;
	StateType*			m_pPreviousCycleState;
	bool				m_arbitrationRequest;
	StateMachine_Type	m_stateMachineType;
	FcpType				m_fcp;
};



#endif // !STATEMACHINE_HPP
