#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		virtual ~Fwoosh();
		
		virtual Fwoosh *clone() const;
};

#endif
