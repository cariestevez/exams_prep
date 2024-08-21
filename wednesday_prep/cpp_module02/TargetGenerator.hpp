#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
	private:

		std::map<std::string, ATarget *> _catalog;

		TargetGenerator(const TargetGenerator &source);
		TargetGenerator &operator=(const TargetGenerator &source);
	
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *targetObj);
		void forgetTargetType(std::string name);
		ATarget *createTarget(const std::string &targetName);
};

#endif
