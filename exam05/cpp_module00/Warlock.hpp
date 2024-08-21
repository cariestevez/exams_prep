#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
	private:
		Warlock &operator=(const Warlock &source);
		Warlock(const Warlock &source);

		std::string _name;
		std::string _title;
	
	public:
		Warlock();
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		
		const std::string &getName() const;
		const std::string &getTitle() const;
		
		void setTitle(const std::string &name);
		
		void introduce() const;
};	

#endif