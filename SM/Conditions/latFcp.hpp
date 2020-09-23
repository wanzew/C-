#ifndef LATFCP_HPP
#define LATFCP_HPP

#include "ActiveConditionTipl.hpp"
#include "PassiveConditions.hpp"
#include "SuppressionReasons.hpp"
#include "../include/enum.hpp"
#include "abstractFcp.hpp"
#include "OffConditions.hpp"
#include "FailureConditions.hpp"
#include "BlindnessConditions.hpp"

class LatFcp : public AbstractFcp
{
public:
	LatFcp()
		: m_offConditions()
		, m_passiveConditions()
		, m_activeTiplConditions()
		, m_failureConditions()
		, m_blindnessConditions()
	{}

	void processCond(const Fip& fip);

	OffConditions			getOffConditions()			{ return m_offConditions;							}
	PassiveConditions		getPassiveConditions()		{ return m_passiveConditions;						}
	ActiveTiplConditions	getActiveTiplConditions()	{ return m_activeTiplConditions;					}
	FailureConditions		getFailureConditions()		{ return m_failureConditions;						}
	BlindnessConditions		getBlindnessConditions()	{ return m_blindnessConditions;						}

	bool getOffConditionFulfilled()						{ return m_offConditions.getConditions();			}
	bool getPassiveConditionFulfilled()				{ return m_passiveConditions.getConditions();		}
	bool getActiveTiplConditionFulfilled()				{ return m_activeTiplConditions.getConditions();	}
	bool getFailureConditionFulfilled()				{ return m_failureConditions.getConditions();		}
	bool getBlindnessConditionFulfilled()				{ return m_blindnessConditions.getConditions();		}


private:
	OffConditions			m_offConditions;
	PassiveConditions		m_passiveConditions;
	ActiveTiplConditions	m_activeTiplConditions;
	FailureConditions		m_failureConditions;
	BlindnessConditions		m_blindnessConditions;
};


#endif