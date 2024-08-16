#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	protected:
		std::string _type;
	public:
		Dummy();
		Dummy(const std::string &type);
		Dummy &operator=(const Dummy &source);
		Dummy(const Dummy &source);
		virtual ~Dummy();
		
		const std::string &getType() const;
		virtual void getHitBySpell(const ASpell &spellSource);
		
		virtual Dummy *clone() const;
};

#endif
