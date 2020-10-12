#ifndef DIVISION_H_
#define DIVISION_H_


#include <iostream>
#include <vector>
#include "Team.h"


using std::string;
using std::vector;


class Division {
private: //States are privates as Division will not have any child class
	static int nbOfDiv;
	vector <Team*> teams;
	string name;
	string coast;


	void Construct();


public:
	Division(const vector <Team*> &teams, string name,string coast);
	virtual ~Division();
	void AddTeam(Team &team);
	vector <Team*> operator + (Division &other);
	void operator = (Division &division);
	void SetName (string NewName);
	void SetCoast (string NewCoast);
	void Display();


};


#endif /* DIVISION_H_ */
