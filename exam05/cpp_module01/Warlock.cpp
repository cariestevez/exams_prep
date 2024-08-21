#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock &Warlock::operator=(const Warlock &source)
{
	if (this != &source)
	{
		_name = source._name;
		_title = source._title;
		_book = source._book;
	}
	return *this;
}

Warlock::Warlock(const Warlock &source)
{
	*this = source;
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell *>::iterator it = _book.begin();
	while (it != _book.end())
	{
		//std::cout << "deleting book" << std::endl;
		delete it->second;
		_book.erase(it);
		++it;
	}
	_book.clear();
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string &name, const std::string &title)
{
	_name = name;
	_title = title;
	
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
	if (spellObj)
	{
		/*std::map<std::string, ASpell *>::const_iterator it = _book.begin();
		while (it != _book.end())
		{
			if (it->first == spellObj->getName())
			{
				delete it->second;
			}
			++it;
		}
		_book[spellObj->getName()] = spellObj->clone();*/
		_book[spellObj->getName()] = spellObj->clone();
	}
}

void Warlock::forgetSpell(std::string spellName)
{
	/*std::map<std::string, ASpell *>::const_iterator it = _book.begin();
	while (it != _book.end())
	{
		if (it->first == spellName)
		{
			delete it->second;
			_book.erase(it);
		}
		++it;
	}*/
	if (_book.find(spellName) != _book.end())
	{
		delete _book[spellName];
		_book.erase(spellName);
	}
}

void Warlock::launchSpell(std::string spellName, const ATarget &targetObj)
{
	/*std::map<std::string, ASpell *>::const_iterator it = _book.begin();
	while (it != _book.end())
	{
		if (it->first == spellName)
		{
			it->second->launch(targetObj);
		}
		++it;
	}*/
	std::map<std::string, ASpell*>::const_iterator it = _book.find(spellName);

    	if (it != _book.end())
    	{
    	 	//targetObj.getHitBySpell(*_spellBook.at(spellName));
        // Use the found iterator to access the spell object
       		it->second->launch(targetObj);
    	}
}
  


