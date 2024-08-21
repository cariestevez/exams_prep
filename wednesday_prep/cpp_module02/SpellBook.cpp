#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::const_iterator iter = _book.begin();
	while (iter != _book.end() && iter->second)
	{
		delete iter->second;
	}
	_book.clear();

}


void SpellBook::learnSpell(ASpell *spellObj)
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

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::const_iterator iter = _book.find(spellName);
	if (iter != _book.end())
	{
		delete iter->second;
		_book.erase(spellName);
	}
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::const_iterator iter = _book.find(spellName);
	if (iter != _book.end())
	{
		ASpell *theSpell = iter->second;
		if (theSpell)
		{
			return theSpell;
		}
	}
	return NULL;
}







