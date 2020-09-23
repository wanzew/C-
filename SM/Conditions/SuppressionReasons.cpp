#include "SuppressionReasons.hpp"

SuppYawrate::SuppYawrate() : AbstractSuppression() {}

void SuppYawrate::calculate(const Fip* fip) {
	switch (255U)
	{
	case 0U:{
		m_isSuppressed = false;
		m_isNotSuppressed = true;
		break;
	}
	case 255U: {
		m_debouncerIsSuppressed.setDuration();
		m_debouncerIsNotSuppressed.setDuration();

		m_suppressionConditionFulfilled = false;// yawrate > 0.11 rad/s
		m_notSuppressionConditionFulfilled = true; // 

		m_isSuppressed = m_debouncerIsSuppressed.getDebounceValueAfterGivenTime(m_suppressionConditionFulfilled);

		break;
	}
	default:
		break;
	}
}

ThresholdTime SuppYawrate::getDebounceTimeThresholds() const {

}
