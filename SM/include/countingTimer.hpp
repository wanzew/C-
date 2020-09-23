#ifndef countingTimer_hpp
#define countingTimer_hpp
countingTimer_hpp
#include <iostream>
#include "countingTimer.hpp"
using namespace std;


class CountingTimer
{
public:
	CountingTimer(int durationInMs, int cycleTime);

	void tick();

	bool isElapsed() const { return m_currentTimeInMs >= m_durationInMs; }

	int getTime() const { return m_currentTimeInMs; }

	void reset() { m_currentTimeInMs = 0U; }

	void setDurationAndReset(int durationInMs) {
		m_durationInMs = durationInMs;
		m_currentTimeInMs = 0U;
	}

	void setDuration(int durationInMs) { m_durationInMs = durationInMs; }

	void stop() { m_currentTimeInMs = m_durationInMs; }

protected:
	int m_durationInMs;
	int m_currentTimeInMs;
	int m_cycleTime;

};


class CountingTimerT20 : public CountingTimer
{
public:
	explicit CountingTimerT20(int durationInMs)
		: CountingTimer(durationInMs, int 20)
	{

	}
};


#endif // !countingTimer_hpp
