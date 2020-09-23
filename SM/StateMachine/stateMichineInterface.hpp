#ifndef STATEMACHINEINTERFACE_HPP
#define STATEMACHINEINTERFACE_HPP

#include "../include/enum.hpp"

class Fip;
class AbstractFcp;

class StateMachineInterface
{
public:
	StateMachineInterface(){}
	StateMachineInterface(const StateMachineInterface&) = delete;
	StateMachineInterface& operator=(const StateMachineInterface&) = delete;

	virtual ~StateMachineInterface() {}


	virtual void preProcessing(const Fip& pFip) = 0;
	virtual void operate() = 0;
	virtual int getCurrentStateID() = 0;
	virtual int getLastStateID() = 0;
	virtual int getPreviousCycleStateID() = 0;
	virtual StateMachine_Type getStateMachineType() const = 0;
	virtual AbstractFcp* getFcp() = 0;
	virtual bool getArbitrationRequest() const = 0;
	virtual void init() = 0;
};









#endif // !STATEMACHINEINTERFACE_HPP
