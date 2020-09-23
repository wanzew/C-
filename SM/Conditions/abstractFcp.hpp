#ifndef ABSFCP_HPP
#define ABSFCP_HPP

#include <vector>
#include "../include/enum.hpp"
#include "../StateMachine/stateMichineInterface.hpp"

using namespace std;

class Fip;
using StateMachineList = vector<StateMachineInterface*>;

class IStateMachineContainer
{
public:
	virtual ~IStateMachineContainer() = default;

	virtual StateMachineList * getStateMachinesList() = 0;
	virtual StateMachineInterface* getStateMachineByType(const StateMachine_Type stateMachineType) = 0;
};

class AbstractFcp
{
public:
	AbstractFcp() : m_stateMachineContainer(nullptr) {}

	virtual ~AbstractFcp() = default;

	virtual void init() = 0;

	virtual void processCond(const Fip& fip) = 0;

	void setStateMachineContainer(IStateMachineContainer* stateMachineContainer) {
		m_stateMachineContainer = stateMachineContainer;
	}

	IStateMachineContainer* getStateMachineContainer() {
		return m_stateMachineContainer;
	}

protected:
	IStateMachineContainer* m_stateMachineContainer;
};


#endif // !ABSFCP_HPP
