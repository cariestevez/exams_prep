#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	//protected:
		//std::string _name;
		//std::string _effects;
	public:
		Fwoosh();
		//Fwoosh(const Fwoosh &source);
		//Fwoosh &operator=(const Fwoosh &source);
		//Fwoosh(const std::string &name, const std::string &effects);
		virtual ~Fwoosh();

		//const std::string &getName() const;
		//const std::string &getEffects() const;
		
		virtual ASpell *clone() const;
		
		//void launch(const ATarget &targetObj);
};

#endif
