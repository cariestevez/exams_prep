#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string _type;
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget &operator=(const ATarget &source);
		ATarget(const ATarget &source);
		virtual ~ATarget();
		
		const std::string &getType() const;
		void getHitBySpell(const ASpell &spellSource) const;
		
		//clone pure method that returns a pointer to ATarget
		virtual ATarget *clone() const = 0;
};

#endif
