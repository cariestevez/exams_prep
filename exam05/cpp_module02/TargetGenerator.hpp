#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
	protected:
		TargetGenerator(const TargetGenerator &source);
		TargetGenerator &operator=(const TargetGenerator &source);

		std::map<std::string, ATarget *> _generator;

	public:
		TargetGenerator();
		virtual ~TargetGenerator();
		
		void learnTargetType(ATarget*);
		void forgetTargetType(string const &);
		ATarget* createTarget(string const &);
};

#endif
