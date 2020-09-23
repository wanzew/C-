#include "BlindnessConditions.hpp"

void BlindnessConditions::calculateCondition(
	const Fip*			fip
) {
	m_suppressionContainer.calculate(fip);
}