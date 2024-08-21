#include "SpellBook.hpp"

SpellBook::SpellBook() {}

/*SpellBook &SpellBook::operator=(const SpellBook &source)
{
	if (this != &source)
	{
		_book = source._book;//wtf??
	}
	return *this;
}

SpellBook::SpellBook(const SpellBook &source)
{
	*this = source;
}*/

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = _book.begin();
	while (it != _book.end())
	{
		//std::cout << "deleting book" << std::endl;
		delete it->second;
		++it;
	}
	_book.clear();
}

void SpellBook::learnSpell(ASpell *spellObj)
{
	if (spellObj)
	{
		std::map<std::string, ASpell *>::const_iterator it = _book.find(spellObj->getName());
		if (it != _book.end())
		{
			delete it->second;
		}
		_book[spellObj->getName()] = spellObj->clone();
	}
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::const_iterator it = _book.find(spellName);
	if (it != _book.end())
	{
		delete it->second;
		_book.erase(it->first);
	}
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
	if (_book.find(spellName) != _book.end())
	{
		return _book[spellName];
	}
	return NULL;
}
  


