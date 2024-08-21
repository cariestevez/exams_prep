#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget &ATarget::operator=(const ATarget &source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	return *this;
}

ATarget::ATarget(const ATarget &source)
{
	*this = source;
}

ATarget::~ATarget()
{
}

ATarget::ATarget(const std::string &type)
{
	_type = type;
}

const std::string &ATarget::getType() const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell &spellObj) const
{
	std::cout << _type << " has been " << spellObj.getEffects() << "!" << std::endl;
}

