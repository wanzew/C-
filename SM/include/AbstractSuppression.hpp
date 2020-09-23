#ifndef ABSTRACTSUPPRESSION_HPP
#define ABSTRACTSUPPRESSION_HPP

#include <vector>
#include <iostream>
#include "../include/debouncerSuppressionBool.hpp"

using namespace std;

class Fip;

class AbstractSuppression {
public:

	AbstractSuppression()
		: m_isSuppressed(false)
		, m_isNotSuppressed(true)
		, m_isDuringPreSuppression(false)
		, m_isDuringEndSuppression(false)
		, m_suppressionConditionFulfilled(false)
		, m_notSuppressionConditionFulfilled(false)
		, m_debouncerIsSuppressed(100)
		, m_debouncerIsNotSuppressed(1000)
	{}

	virtual void calculate(const Fip* fip) = 0;

	virtual ThresholdTime getDebounceTimeThresholds() const = 0;

	bool isSuppressed() const { return m_isSuppressed; }
	bool isNotSuppressed() const { return m_isNotSuppressed; }
	bool isDuringPreSuppression() const { return m_isDuringPreSuppression; }
	bool isDuringEndSuppression() const { return m_isDuringEndSuppression; }

protected:
	bool			m_isSuppressed;
	bool			m_isNotSuppressed;
	bool			m_isDuringPreSuppression;
	bool			m_isDuringEndSuppression;
	bool			m_suppressionConditionFulfilled;
	bool			m_notSuppressionConditionFulfilled;

	DebouncerSuppressionBoolT20 m_debouncerIsSuppressed;
	DebouncerSuppressionBoolT20 m_debouncerIsNotSuppressed;

};

struct TimerDurationThresholds
{
	TimerDurationThresholds()
		: m_timeDurationActivationThreshold(0)
		, m_timeDurationDeactivationThreshold(0)
	{}

	TimerDurationThresholds(
		int f_time1,
		int f_time2
	)
		: m_timeDurationActivationThreshold(f_time1)
		, m_timeDurationDeactivationThreshold(f_time2)
	{}

	int m_timeDurationActivationThreshold;
	int m_timeDurationDeactivationThreshold;
};

class MinimumActivationSuppression : public AbstractSuppression
{
public:
	MinimumActivationSuppression()
		: m_isSuppressionFlag(false)
		, m_isNotSuppressionFlag(false)
		, m_timerStartingDebouncer(2000u)
		, m_timerEndingDebouncer(1000)
	{
	}

	bool debouncedValueAfterGivenTime(const bool signalToDebounce, bool True) {
		if (signalToDebounce && True) {
			if (m_timerStartingDebouncer.isElapsed())
				m_timerStartingDebouncer.stop();
			else
				m_timerStartingDebouncer.tick();
		}
		else if(!signalToDebounce){
			if (m_timerStartingDebouncer.isElapsed())
				m_timerStartingDebouncer.reset();
			else {
				m_timerStartingDebouncer.tick();
				return !signalToDebounce;
			}
		}
		return signalToDebounce;
	}

	void function() {
		if (m_isSuppressed)
			m_isSuppressionFlag = true;
	}

private:
	bool				m_isSuppressionFlag;
	bool				m_isNotSuppressionFlag;
	CountingTimerT20	m_timerStartingDebouncer;
	CountingTimerT20	m_timerEndingDebouncer;
};



#endif // !ABSTRACTSUPPRESSION
