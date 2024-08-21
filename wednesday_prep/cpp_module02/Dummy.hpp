#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget
{
	public:
		Dummy();
		virtual ~Dummy();
		
		virtual Dummy *clone() const;
};

#endif
