#include "ATarget.hpp"

ATarget::ATarget() : _type() {}

ATarget::ATarget(const ATarget &source)
{
	*this = source;
}

ATarget &ATarget::operator=(const ATarget &source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	return *this;
}

ATarget::ATarget(const std::string &type) : _type(type)
{
}

ATarget::~ATarget()
{
}

const std::string &ATarget::getType() const {return _type;}

void ATarget::getHitBySpell(const ASpell &spellObj) const
{
	std::cout << _type << " has been " << spellObj.getEffects() << "!" << std::endl;
}
