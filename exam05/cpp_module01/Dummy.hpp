#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	//private:
	//	std::string _type;
	public:
		Dummy();
		//Dummy(const Dummy &source);
		//Dummy &operator=(const Dummy &source);
		//Dummy(const std::string &type);
		virtual ~Dummy();

		//const std::string &getType() const;
		
		virtual ATarget *clone() const;
		
		//void getHitBySpell(const ASpell &spellObj);
};

#endif
