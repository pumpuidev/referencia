#include "enor_string.h"

Enor_string::Enor_string(std::string s)
{
	this->s = s;
}

void Enor_string::First()
{
	i = 0;
}

void Enor_string::Next()
{
	++i;
}

bool Enor_string::End() const
{
	return i >= s.size();
}

char Enor_string::Current() const
{
	return s[i];
}
