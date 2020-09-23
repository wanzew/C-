#include "FailureConditions.hpp"

void FailureConditions::calculateCondition(
	const Fip*			fip
) {
	m_suppressionContainer.calculate(fip);
}