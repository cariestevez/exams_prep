#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	
	public:
		ASpell();
		ASpell &operator=(const ASpell &source);
		ASpell(const ASpell &source);
		ASpell(const std::string &name, const std::string &effects); //reference or not??
		virtual ~ASpell();
		
		const std::string &getName() const; //reference or not??
		const std::string &getEffects() const; //reference or not??

		virtual ASpell *clone() const = 0;
		
		void launch(const ATarget &targetObj) const;
};	

#endif
