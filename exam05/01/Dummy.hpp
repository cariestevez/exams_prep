#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>

class Dummy
{
	protected:
		std::string _type;
	public:
		Dummy();
		Dummy(const std::string &type);
		Dummy &operator=(const Dummy &source);
		Dummy(const Dummy &source);
		virtual ~Dummy();
		
		const std::string &getType() const;
		void getHitBySpell(const ASpell &spellSource);
		
		virtual Dummy *clone() const;
};

#endif
