#include "ActiveConditionTipl.hpp"

void ActiveTiplConditions::calculateCondition(
	const Fip*			fip
) {
	m_suppressionContainer.calculate(fip);
}