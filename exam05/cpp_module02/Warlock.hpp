#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class SpellBook;

class ASpell;

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _book;

		Warlock();
		Warlock(const Warlock &source);
		Warlock &operator=(const Warlock &source);
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		
		void introduce() const;

		void learnSpell(ASpell *spellObj);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, const ATarget &targetObj);
};

#endif
