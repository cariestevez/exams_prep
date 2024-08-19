#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(const SpellBook &source);
		SpellBook &operator=(const SpellBook &source);

		std::map<std::string, ASpell *> _book;
	
	public:
		SpellBook();
		~SpellBook();
		
		void learnSpell(ASpell *spellObj);
		void forgetSpell(const std::string &spellName);
		ASpell* createSpell(const std::string &spellName);
};

#endif
