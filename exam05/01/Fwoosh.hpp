#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>

class Fwoosh : public ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	public:
		Fwoosh();
		Fwoosh(const std::string &name, const std::string &effects);
		Fwoosh &operator=(const Fwoosh &source);
		Fwoosh(const Fwoosh &source);
		virtual ~Fwoosh();
		
		const std::string &getName() const;
		const std::string &getEffects() const;
		void launch(const ATarget &targetSource);

		virtual Fwoosh *clone() const;
};

#endif
