#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

/*Dummy::Dummy(const Dummy &source) : ATarget(source) {}

Dummy &Dummy::operator=(const Dummy &source)
{
	if (this != &source)
	{
		ATarget::operator=(source);
	}

	return *this;
}

Dummy::Dummy(const std::string &type)
{
	_type = type;

}*/

Dummy::~Dummy()
{
}

/*const std::string &Dummy::getType() const
{
	return _type;
}
		
void Dummy::getHitBySpell(const ASpell &spellObj)
{
	std::cout << _type << " has been " << spellObj.getEffects() << "!" << std::endl;
}*/

ATarget *Dummy::clone() const
{
	return new Dummy(*this);
}
