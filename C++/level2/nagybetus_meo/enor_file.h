#ifndef ENOR_FILE_H
#define ENOR_FILE_H

#include<iostream>
#include<fstream>

enum Status { Norm, Abnorm };

class Enor_file
{
    public:
		Enor_file(std::string filenev);
		void First();
		void Next();
		bool End() const;
		char Current() const;
	private:
		std::ifstream x;
		Status sx;
		char dx;
};

#endif // ENOR_FILE_H
