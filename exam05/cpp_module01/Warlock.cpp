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

//* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
void Warlock::learnSpell(ASpell *spellObj)
{
	if (spellObj)
	{
		_spellBook[spellObj->getName()] = spellObj;
		//std::cout << "spell " << spellObj->getName() << " learnded by " << _name << std::endl;
	}
}

//* forgetSpell, takes a string corresponding a to a spell's name, and makes the
 // Warlock forget it. If it's not a known spell, does nothing.
void Warlock::forgetSpell(const std::string spellName)
{
	if (_spellBook.find(spellName) != _spellBook.end())
	{
		_spellBook.erase(spellName);
		//std::cout << "spell erased by " << _name << std::endl;
	}
}

//* launchSpell, takes a string (a spell name) and a reference to ATarget, that
//  launches the spell on the selected target. If it's not a known spell, does
//  nothing.
void Warlock::launchSpell(const std::string spellName, const ATarget &targetObj) const
{
	std::map<std::string, ASpell*>::const_iterator it = _spellBook.find(spellName);

    	if (it != _spellBook.end())
    	{
    	 	targetObj.getHitBySpell(*_spellBook.at(spellName));
        // Use the found iterator to access the spell object
       		//it->second->launch(targetObj);
    	}
    	/*if (_spellBook.find(spellName) != _spellBook.end())
	{
		targetObj.getHitBySpell(*_spellBook[spellName]);
		//alternative -> *spellBook[spellName].launch(targetObj);
		//std::cout << "spell launched by " << _name << " to " << targetObj.getType() << std::endl;
	}*/
}




