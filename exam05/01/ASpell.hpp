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
		ASpell(const std::string &name, const std::string &effects);
		ASpell &operator=(const ASpell &source);
		ASpell(const ASpell &source);
		virtual ~ASpell();
		
		const std::string &getName() const;
		const std::string &getEffects() const;
		void launch(const ATarget &targetSource);
		
		//clone pure method that returns a pointer to ASpell
		virtual ASpell *clone() const = 0;
};

#endif
