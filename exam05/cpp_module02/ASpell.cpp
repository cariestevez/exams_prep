#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell &ASpell::operator=(const ASpell &source)
{
	if (this != &source)
	{
		_name = source._name;
		_effects = source._effects;
	}
	return *this;
}

ASpell::ASpell(const ASpell &source)
{
	*this = source;
}

ASpell::~ASpell()
{
}

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects) {}

const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}

void ASpell::launch(const ATarget &targetObj) const
{
	targetObj.getHitBySpell(*this);
}

