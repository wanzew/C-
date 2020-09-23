#ifndef ActiveTiplConditions_hpp
#define ActiveTiplConditions_hpp

#include <iostream>
#include "../include/SuppressionList.hpp"
#include "../include/debouncerSuppressionBool.hpp"
#include "SuppressionReasons.hpp"
#include "../include/enum.hpp"

class ActiveTiplConditions {

public:
	ActiveTiplConditions()
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
