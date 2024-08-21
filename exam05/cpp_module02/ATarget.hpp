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
		ATarget &operator=(const ATarget &source);
		ATarget(const ATarget &source);
		ATarget(const std::string &type);//reference or not?? const?
		virtual ~ATarget();
		
		const std::string &getType() const; //reference or not?? const?

		virtual ATarget *clone() const = 0;
		
		void getHitBySpell(const ASpell &spellObj) const;
};	

#endif
