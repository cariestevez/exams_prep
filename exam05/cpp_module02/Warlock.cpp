#include "Warlock.hpp"

Warlock::Warlock() : _name(), _title() {}

Warlock::Warlock(const Warlock &source)
{
	*this = source;
}

Warlock &Warlock::operator=(const Warlock &source)
{
	if (this != &source)
	{
		_name = source._name;
		_title = source._title;
		_spellBook = source._spellBook;
	}

	return *this;
}

Warlock::Warlock(const std::string &name, const std::string &title)
{
	_name = name;
	_title = title;
	
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return _name;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spellObj)
{
	_spellBook->learnSpell(spellObj);
}

void Warlock::forgetSpell(const std::string spellName)
{
	_spellBook->forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string spellName, const ATarget &targetObj) const
{
	ASpell *theSpell = _spellBook->createSpell(spellName);

	if (theSpell)
    		theSpell->launch(targetObj);
}




