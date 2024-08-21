#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class SpellBook
{
	private:

		std::map<std::string, ASpell *> _book;

		SpellBook(const SpellBook &source);
		SpellBook &operator=(const SpellBook &source);
	
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spellObj);
		void forgetSpell(const std::string &spellName);
		ASpell* createSpell(const std::string &spellName);
};

#endif
