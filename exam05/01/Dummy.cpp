#include "Dummy.hpp"

Dummy::Dummy() : _type("Target Practice Dummy") {}

Dummy &Dummy::operator=(const Dummy &source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	
	return (*this);
}

Dummy::Dummy(const Dummy &source)
{
	*this = source;
}

Dummy::Dummy(const std::string &type)
{
	_type = type;
}

Dummy::~Dummy()
{
}

const std::string &Dummy::getType() const
{
	return _type;
}

void Dummy::getHitBySpell(const ASpell &spellSource)
{
	std::cout << _type << " has been " << spellSource.getEffects() << "!" << std::endl;
}

Dummy *Dummy::clone() const
{
	return new Dummy;
}
