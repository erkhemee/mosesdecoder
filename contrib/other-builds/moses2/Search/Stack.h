/*
 * Stack.h
 *
 *  Created on: 24 Oct 2015
 *      Author: hieu
 */

#ifndef STACK_H_
#define STACK_H_
#include <boost/unordered_set.hpp>
#include "Hypothesis.h"
#include "moses/Util.h"

class StackAdd
{
public:
	bool added;
	const Hypothesis *other;

	StackAdd(bool vadded,
			const Hypothesis *vother)
	:added(vadded)
	,other(vother)
	{
	}
};

class Stack {
protected:
	  typedef boost::unordered_set<const Hypothesis*, Moses::UnorderedComparer<Hypothesis>, Moses::UnorderedComparer<Hypothesis> > _HCType;
	  _HCType m_hypos;
public:
  typedef _HCType::iterator iterator;
  typedef _HCType::const_iterator const_iterator;
  //! iterators
  const_iterator begin() const {
	return m_hypos.begin();
  }
  const_iterator end() const {
	return m_hypos.end();
  }

	Stack();
	virtual ~Stack();


	size_t GetSize() const
	{ return m_hypos.size(); }

	StackAdd Add(const Hypothesis *hypo);

	std::vector<const Hypothesis*> GetBestHypos(size_t num) const;
	std::vector<const Hypothesis*> GetSortedHypos() const;

protected:
};

#endif /* STACK_H_ */