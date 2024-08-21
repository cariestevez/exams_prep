#ifndef Fireball_HPP
#define Fireball_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class Fireball : public ASpell
{
	public:
		Fireball();
		virtual ~Fireball();
		
		virtual Fireball *clone() const;
};

#endif
