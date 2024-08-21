#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class SpellBook
{
	private:
		SpellBook &operator=(const SpellBook &source);
		SpellBook(const SpellBook &source);

		std::map<std::string, ASpell *> _book;
	
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spellObj);
		void forgetSpell(const std::string &spellName);
		ASpell *createSpell(const std::string &spellName);
};	

#endif
