#include "Warlock.hpp"

Warlock::Warlock() {}

/*Warlock &Warlock::operator=(const Warlock &source)
{
	if (this != &source)
	{
		_name = source._name;
		_title = source._title;
	}
	return *this;
}

Warlock::Warlock(const Warlock &source)
{
	*this = source;
}*/

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

const std::string &Warlock::getName() const
{
	return _name;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string &title) : _title(title) {}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;

}

void Warlock::learnSpell(ASpell *spellObj)
{
	_book.learnSpell(spellObj);
}

void Warlock::forgetSpell(std::string spellName)
{
	_book.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget &targetObj)
{
	//need to make sure the spell exists(createSpell returns !=NULL)
    	//_book.createSpell(spellName)->launch(targetObj); --> possible segfault
    	ASpell *theSpell = _book.createSpell(spellName);
    	if (theSpell)
    		theSpell->launch(targetObj);
}
  


