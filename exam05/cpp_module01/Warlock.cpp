#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell *>::const_iterator iter = _book.begin();
	while (iter != _book.end() && iter->second)
	{
		delete iter->second;
	}
	_book.clear();

	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const {return _name;}

const std::string &Warlock::getTitle() const {return _title;}

void Warlock::setTitle(const std::string &title) {_title = title;}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spellObj)
{
	if (spellObj)
	{
		std::map<std::string, ASpell *>::const_iterator iter = _book.find(spellObj->getName());
		if (iter != _book.end() && iter->second)
		{
			delete iter->second;
		}
		_book[spellObj->getName()] = spellObj->clone();
	}
}

void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell *>::const_iterator iter = _book.find(name);
	if (iter != _book.end())
	{
		delete iter->second;
		_book.erase(name);
	}
}

void Warlock::launchSpell(std::string name, const ATarget &targetObj)
{
	std::map<std::string, ASpell *>::const_iterator iter = _book.find(name);
	if (iter != _book.end())
	{
		ASpell *theSpell = iter->second;
		if (theSpell)
		{
			theSpell->launch(targetObj);
		}
	}
}








