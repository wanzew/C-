#ifndef ABSSTATE_HPP
#define ABSSTATE_HPP

template<typename StateEnum, class StateMachineClassType>
class AbstractState
{
public:
	typedef StateEnum states_enum;
	AbstractState() : m_stateId(0) {}

	explicit AbstractState(StateEnum stateId) : m_stateId(stateId) {}

	virtual ~AbstractState() {}

	StateEnum getStateId() const { return m_stateId; }

	void setStateId(StateEnum stateId) { m_stateId = stateId; }

	virtual void handleState(StateMachineClassType* pcontext) = 0;

private:
	StateEnum m_stateId;
};

#endif // !ABSSTATE_HPP
