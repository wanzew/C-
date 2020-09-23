#include "latFcp.hpp"

void LatFcp::processCond(const Fip& fip) {
	m_offConditions.calculateCondition(&fip);
	m_passiveConditions.calculateCondition(&fip);
	m_activeTiplConditions.calculateCondition(&fip);
	m_failureConditions.calculateCondition(&fip);
	m_blindnessConditions.calculateCondition(&fip);
}