#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball()
{
}

ASpell *Fireball::clone() const
{
	return new Fireball(*this); // creates a new object on the heap, using the current object to initialize it through the copy constructor.
}
