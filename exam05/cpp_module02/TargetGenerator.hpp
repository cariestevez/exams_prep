#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class TargetGenerator
{
	private:
		TargetGenerator &operator=(const TargetGenerator &source);
		TargetGenerator(const TargetGenerator &source);
	
		std::map<std::string, ATarget *> _catalog;

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *targetObj);
		void forgetTargetType(const std::string &targetType);
		ATarget *createTarget(const std::string &targetType);
};	

#endif
