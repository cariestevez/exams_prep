#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph()
{
}

ASpell *Polymorph::clone() const
{
	return new Polymorph(*this); // creates a new object on the heap, using the current object to initialize it through the copy constructor.
}
