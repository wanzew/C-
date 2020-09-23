#include "ActiveCondition.hpp"

void ActiveControlConditions::calculateCondition(
	const Fip*			fip
) {
	m_suppressionContainer.calculate(fip);
}