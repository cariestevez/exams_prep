#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	private:
		Warlock();
		Warlock &operator=(const Warlock &source);
		Warlock(const Warlock &source);
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell *> _spellBook;
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
		
		void learnSpell(ASpell *spellSource);
		void forgetSpell(const std::string spellName);
		void launchSpell(const std::string spellName, ATarget &targetSource);
};

#endif
