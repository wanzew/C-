#ifndef SUPPRESSIONREASON_HPP
#define SUPPRESSIONREASON_HPP

#include <iostream>
#include "../include/AbstractSuppression.hpp"

using ThresholdTime = TimerDurationThresholds;

class SuppYawrate : public AbstractSuppression {
public:
	SuppYawrate() : AbstractSuppression() {}

	virtual void calculate(const Fip* fip) override;

	ThresholdTime getDebounceTimeThresholds() const override;
};


#endif // !SUPPRESSIONREASON_HPP
