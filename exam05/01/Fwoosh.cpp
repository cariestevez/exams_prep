#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : _name("Fwoosh"), _effects("fwooshed") {}

Fwoosh &Fwoosh::operator=(const Fwoosh &source)
{
	if (this != &source)
	{
		_name = source._name;
		_effects = source._effects;
	}
	
	return (*this);
}

Fwoosh::Fwoosh(const Fwoosh &source)
{
	*this = source;
}

Fwoosh::Fwoosh(const std::string &name, const std::string &effects)
{
	_name = name;
	_effects = effects;
}

Fwoosh::~Fwoosh()
{
}

const std::string &Fwoosh::getName() const
{
	return _name;
}

const std::string &Fwoosh::getEffects() const
{
	return _effects;
}

void Fwoosh::launch(const ATarget &targetSource)
{
	targetSource.getHitBySpell(*this);
}

Fwoosh *Fwoosh::clone() const
{
	return new Fwoosh;
}
