#include "Warlock.hpp"

Warlock::Warlock() : _name(), _title() {}

Warlock &Warlock::operator=(const Warlock &source)
{
	if (this != &source)
	{
		_name = source._name;
		_title = source._title;
	}
	
	return (*this);
}

Warlock::Warlock(const Warlock &source)
{
	*this = source;
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


//* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
void Warlock::learnSpell(ASpell *spellSource)
{
	if (spellSource)
	{
		if (_spellBook.find(spellSource->getName()) == _spellBook.end()) //check to avoid cloning on top of previously allocated memory
		{
			_spellBook[spellSource->getName()] = spellSource->clone();
			std::cout << "in learnSpell: " << spellSource->getName() << " learned" << std::endl;
		}
	}
}

//* forgetSpell, takes a string corresponding a to a spell's name, and makes the
// Warlock forget it. If it's not a known spell, does nothing.
void Warlock::forgetSpell(const std::string spellName)
{
	if (_spellBook.find(spellName) != _spellBook.end())
	{
		_spellBook.erase(_spellBook.find(spellName));
		std::cout << "in forgetSpell: " << spellName << " erased: " << std::endl;
	}
}

//* launchSpell, takes a string (a spell name) and a reference to ATarget, that
// launches the spell on the selected target. If it's not a known spell, does
// nothing.
void Warlock::launchSpell(const std::string spellName, ATarget &targetSource)
{
	std::cout << "in launchSpell:" << spellName << std::endl;
	if (_spellBook.find(spellName) != _spellBook.end())
	{
		std::cout << spellName << " found" << std::endl;
		_spellBook[spellName]->launch(targetSource);
	}
}
