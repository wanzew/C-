#ifndef BlindnessCONDITION_HPP
#define BlindnessCONDITION_HPP

#include <iostream>
#include "../include/SuppressionList.hpp"
#include "../include/debouncerSuppressionBool.hpp"
#include "SuppressionReasons.hpp"
#include "../include/enum.hpp"

class BlindnessConditions {

public:
	BlindnessConditions()
		: m_suppressionContainer()
		, m_suppressionYawrate()
	{
		m_suppressionContainer.add(m_suppressionYawrate);
	}

	void calculateCondition(
		const Fip*		fip
	);

	bool getConditions() const {
		return m_suppressionContainer.isSuppressed();
	}

private:
	SuppressionList			m_suppressionContainer;
	SuppYawrate*			m_suppressionYawrate;

};



#endif // !PASSIVECONDITION_HPP
#ifndef FailureCONDITION_HPP
#define FailureCONDITION_HPP

#include <iostream>
#include "../include/SuppressionList.hpp"
#include "../include/debouncerSuppressionBool.hpp"
#include "SuppressionReasons.hpp"
#include "../include/enum.hpp"

class FailureConditions {

public:
	FailureConditions()
		: m_suppressionContainer()
		, m_suppressionYawrate()
	{
		m_suppressionContainer.add(m_suppressionYawrate);
	}

	void calculateCondition(
		const Fip*		fip,
		const bool		isLongActive,
		const LatS_State latState
	);

	bool getConditions() const {
		return m_suppressionContainer.isSuppressed();
	}

private:
	SuppressionList			m_suppressionContainer;
	SuppYawrate*			m_suppressionYawrate;

};



#endif // !PASSIVECONDITION_HPP
