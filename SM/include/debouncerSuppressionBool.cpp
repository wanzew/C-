#include "debouncerSuppressionBool.hpp"

DebouncerSuppressionBool::DebouncerSuppressionBool(int debounceTimeInMs, int cycleTime)
	: m_timer(debounceTimeInMs, cycleTime)
{

}

bool DebouncerSuppressionBool::getDebounceValueAfterGivenTime(const bool signalToDebounce)
{
	m_timer.tick();
	const bool outputValue = (signalToDebounce && m_timer.isElapsed());

	if ((outputValue == false) && (signalToDebounce == false)) {
		m_timer.reset();
	}

	return outputValue;
}