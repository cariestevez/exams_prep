#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

/*TargetGenerator &TargetGenerator::operator=(const TargetGenerator &source)
{
	if (this != &source)
	{
		_catalog = source._catalog; //what do I doooo??
	}
	return *this;
}

TargetGenerator::TargetGenerator(const TargetGenerator &source)
{
	*this = source;
}*/

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = _catalog.begin();
	while (it != _catalog.end())
	{
		//std::cout << "deleting catalog" << std::endl;
		delete it->second;
		++it;
	}
	_catalog.clear();
}

void TargetGenerator::learnTargetType(ATarget *targetObj)
{
	if (targetObj)
	{
		std::map<std::string, ATarget *>::const_iterator it = _catalog.find(targetObj->getType());
		if (it != _catalog.end())
		{
			delete it->second;
		}
		_catalog[targetObj->getType()] = targetObj->clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string &targetType)
{
	std::map<std::string, ATarget *>::const_iterator it = _catalog.find(targetType);
	if (it != _catalog.end())
	{
		delete it->second;
		_catalog.erase(it->first);
	}
}

ATarget *TargetGenerator::createTarget(const std::string &tragetType)
{
	if (_catalog.find(tragetType) != _catalog.end())
	{
		return _catalog[tragetType];
	}
	return NULL;
}
  


