#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
	private:
		Warlock();
		Warlock(const Warlock &source);
		Warlock &operator=(const Warlock &source);
		std::string _name;
		std::string _title;
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
};

#endif
