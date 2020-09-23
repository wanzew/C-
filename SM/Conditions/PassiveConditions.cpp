#include "PassiveConditions.hpp"

void PassiveConditions::calculateCondition(
	const Fip*			fip
) {
	m_suppressionContainer.calculate(fip);
}