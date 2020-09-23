#ifndef DEBOUNCERSUPPRESSIONBOOL_HPP
#define DEBOUNCERSUPPRESSIONBOOL_HPP

#include <iostream>
#include "countingTimer.hpp"
using namespace std;


class DebouncerSuppressionBool
{
public:
	DebouncerSuppressionBool(int debouceTimeInMs, int cycleTime);

	bool getDebounceValueAfterGivenTime(const bool signalToDebounce);

	void setDuration(const int debounceTimeInMs) {
		m_timer.setDuration(debounceTimeInMs);
	}

	void resetTimer() { m_timer.reset(); }

private:
	CountingTimer m_timer;
};

class DebouncerSuppressionBoolT20 : public DebouncerSuppressionBool
{
public:
	explicit DebouncerSuppressionBoolT20(int durationInMs)
		: DebouncerSuppressionBool(durationInMs, 20U)
	{ }
}

#endif // !DEBOUNCERSUPPRESSIONBOOL_HPP
