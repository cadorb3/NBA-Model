#ifndef TEAMMEDIC_H_
#define TEAMMEDIC_H_


#include <iostream>
#include <string>
using std::string;


struct TeamMedic {
	// in a C++ struct, default access specifier is public


	string name;
	int age;
	TeamMedic(string name, int age);
	virtual ~TeamMedic();
};


#endif /* TEAMMEDIC_H_ */
