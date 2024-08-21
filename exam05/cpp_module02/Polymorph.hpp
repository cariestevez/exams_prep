#ifndef Polymorph_HPP
#define Polymorph_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class Polymorph : public ASpell
{
	public:
		Polymorph();
		virtual ~Polymorph();
		
		virtual Polymorph *clone() const;
};

#endif
