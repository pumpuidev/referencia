#ifndef ENOR_STRING_H
#define ENOR_STRING_H

#include<iostream>

class Enor_string
{
	public:
		Enor_string(std::string s);
		void First();
		void Next();
		bool End() const;
		char Current() const;
	private:
		size_t i;
		std::string s;
};

#endif // ENOR_STRING_H
