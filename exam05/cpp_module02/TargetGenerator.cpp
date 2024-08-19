#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() : _name(), _effects() {}

TargetGenerator::TargetGenerator(const TargetGenerator &source)
{
	*this = source;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &source)
{
	if (this != &source)
	{
		std::map<std::string, ATarget *>::iterator it = _generator.begin();
		while (it != _generator.end())
		{
			delete it->second;
			++it;
		}
		_generator.clear();

		std::map<std::string, ASpell *>::const_iterator itSource = source._generator.begin();
		while (itSource != source._generator.end())
		{
			delete itSource->second;
			_generator[itSource->first] = itSource->second->clone();
			++itSource;
		}
	}

	return *this;
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *targetObj)
{
	if (targetObj)
	{
		std::map<std::string, ATarget *>::iterator it = _generator.find(targetObj->getName());
		if (it != _generator.end())
		{
			delete it->second;
		}
		_generator[targetObj->getName()] = targetObj.clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string &targetName)
{
	std::map<std::string, TargetGenerator *>::iterator it = _generator.find(targetName);
	if (it != _generator.end())
	{
		delete it->second;
		_generator.erase(targetName);
	}
}

ATarget *TargetGenerator::createTarget(const std::string &targetName)
{
	std::map<std::string, ATarget *>::iterator it = _generator.find(targetName);
	if (it != _generator.end())
	{
		return it->second;
	}
	return NULL;
}

