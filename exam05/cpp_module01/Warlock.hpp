#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class Warlock
{
	private:
		Warlock &operator=(const Warlock &source);
		Warlock(const Warlock &source);

		std::string _name;
		std::string _title;
		std::map<std::string, ASpell *> _book;
	
	public:
		Warlock();
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &name);
		void introduce() const;

		void learnSpell(ASpell *spellObj);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget &targetObj);
};	

#endif
