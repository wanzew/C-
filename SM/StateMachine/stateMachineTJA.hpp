#ifndef STATEMACHINETJA_HPP
#define STATEMACHINETJA_HPP

#include "stateMachine.hpp"
#include "latState.hpp"
#include "PassiveState.hpp"
#include "ActiveRequestState.hpp"
#include "OffState.hpp"
#include "ActiveControlState.hpp"
#include "FailureState.hpp"
#include "BlindnessState.hpp"

class Fip;
class LatFcp;

class StateMachineTJA : public StateMachine<LatState, LatFcp>
{
public:

	StateMachineTJA();
	~StateMachineTJA(){}

	void init() override;
	virtual void operate();
	StateMachineTJA(const StateMachineTJA&) = delete;
	StateMachineTJA& operator=(const StateMachineTJA&) = delete;

	LatState* getOffState()				{ return &m_offState; }
	LatState* getPassiveState()			{ return &m_passiveState; }
	LatState* getActiveRequestState()	{ return &m_activeRequestState; }
	LatState* getActiveControlState()	{ return &m_activeControlState; }
	LatState* getFailureState()			{ return &m_failureState; }
	LatState* getBlindnessState()		{ return &m_blindnessState; }

private:
	LatOffState				m_offState;
	LatPassiveState			m_passiveState;
	LatActiveRequestState	m_activeRequestState;
	LatActiveControlState	m_activeControlState;
	LatFailureState			m_failureState;
	LatBlindnessState		m_blindnessState;
};

#endif // !STATEMACHINETJA_HPP
