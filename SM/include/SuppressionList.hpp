#ifndef SUPPRESSIONLIST_HPP
#define SUPPRESSIONLIST_HPP

#include <iostream>
#include <vector>
#include "AbstractSuppression.hpp"

class Fip;

class SuppressionList {

public:
	SuppressionList()
		: m_suppressionContainer()
		, m_isSuppressed()
		, m_isNotSuppressed()
	{ }

	void add(AbstractSuppression* suppression) {
		m_suppressionContainer.push_back(suppression);
	}

	void calculate(const Fip* fip) {
		for (auto suppression : m_suppressionContainer) {
			if (suppression != nullptr) {
				suppression->calculate(fip);
			}
		}
	}
	
	vector<AbstractSuppression*> getSuppressionLists() const {
		return m_suppressionContainer;
	}

	bool isSuppressed() const {
		bool value = false;
		for (auto suppression : m_suppressionContainer) {
			if (suppression != nullptr) {
				value = value || suppression->isSuppressed();
			}
		}
		return value;
	}

	bool isNotSuppressed() const {
		bool value = true;
		for (auto suppression : m_suppressionContainer) {
			if (suppression != nullptr) {
				value = value && suppression->isNotSuppressed();
			}
		}
		return value;
	}

private:
	vector<AbstractSuppression* > m_suppressionContainer;
	bool						m_isSuppressed;
	bool						m_isNotSuppressed;
};



#endif // !SUPPRESSIONLIST_HPP
