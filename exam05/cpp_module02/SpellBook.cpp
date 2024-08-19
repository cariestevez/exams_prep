#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &source)
{
	*this = source;
}

SpellBook &SpellBook::operator=(const SpellBook &source)
{
	if (this != &source)
	{
		std::map<std::string, ASpell *>::iterator it = _book.begin();
		while (it != _book.end())
		{
			delete it->second;
			++it;
		}
		_book.clear();

		std::map<std::string, ASpell *>::const_iterator itSource = source._book.begin();
		while (itSource != source._book.end())
		{
			delete itSource->second;
			_book[itSource->first] = itSource->second->clone();
			++itSource;
		}
	}

	return *this;
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = _book.begin();
	while (it != _book.end())
	{
		delete it->second;
		++it;
	}
	_book.clear();
}


void SpellBook::learnSpell(ASpell *spellObj)
{
	if (spellObj)
	{
		std::map<std::string, ASpell *>::iterator it = _book.find(spellObj->getName());
		if (it != _book.end())
		{
			delete it->second;
		}
		_book[spellObj->getName()] = spellObj->clone();
	}
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(spellName);
	if (it != _book.end())
	{
		delete it->second;
		_book.erase(spellName);
	}
}

ASpell* createSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(spellName);
	if (it != _book.end())
	{
		return it->second;
	}
	return NULL;
}
