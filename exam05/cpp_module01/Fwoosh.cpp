#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh()
{
}

ASpell *Fwoosh::clone() const
{
	return new Fwoosh(*this); // pointer is of type fwoosh but passed as ASpell to the main, copying content of Fwoosh
}
