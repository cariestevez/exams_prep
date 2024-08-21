#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::const_iterator iter = _catalog.begin();
	while (iter != _catalog.end() && iter->second)
	{
		delete iter->second;
		++iter;
	}
	_catalog.clear();

}


void TargetGenerator::learnTargetType(ATarget *targetObj)
{
	if (targetObj)
	{
		std::map<std::string, ATarget *>::const_iterator iter = _catalog.find(targetObj->getType());
		if (iter != _catalog.end() && iter->second)
		{
			delete iter->second;
		}
		_catalog[targetObj->getType()] = targetObj->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string name)
{
	std::map<std::string, ATarget *>::const_iterator iter = _catalog.find(name);
	if (iter != _catalog.end())
	{
		delete iter->second;
		_catalog.erase(name);
	}
}

ATarget *TargetGenerator::createTarget(const std::string &targetName)
{
	std::map<std::string, ATarget *>::const_iterator iter = _catalog.find(targetName);
	if (iter != _catalog.end())
	{
		ATarget *theSpell = iter->second;
		if (theSpell)
		{
			return theSpell;
		}
	}
	return NULL;
}







