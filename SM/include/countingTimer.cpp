#include "countingTimer.hpp"

CountingTimer::CountingTimer(int durationInMs, int cycleTime)
	: m_durationInMs(durationInMs)
	, m_currentTimeInMs(0U)
	, m_cycleTime(cycleTime)
{

}

void CountingTimer::tick() {
	if (m_currentTimeInMs < m_durationInMs) {
		m_currentTimeInMs += m_cycleTime;
	}
}