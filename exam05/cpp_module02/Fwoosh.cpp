#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

/*Fwoosh::Fwoosh(const Fwoosh &source) : ASpell(source) {}

Fwoosh &Fwoosh::operator=(const Fwoosh &source)
{
	if (this != &source)
	{
		ASpell::operator=(source);
	}

	return *this;
}

//Fwoosh::Fwoosh(const std::string &name, const std::string &effects)
//{
//	_name = name;
//	_effects = effects;
//
//}*/

Fwoosh::~Fwoosh()
{
}

/*const std::string &Fwoosh::getName() const
{
	return _name;
}

const std::string &Fwoosh::getEffects() const
{
	return _effects;
}

void Fwoosh::launch(const ATarget &targetObj)
{
	targetObj.getHitBySpell(*this);
}*/

ASpell *Fwoosh::clone() const
{
	return new Fwoosh(*this); // creates a new object on the heap, using the current object to initialize it through the copy constructor.
}
