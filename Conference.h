#ifndef CONFERENCE_H_
#define CONFERENCE_H_


#include <iostream>
#include<vector>
#include "Division.h"


using std::string;
using std::vector;


class Conference {
//  Here in a C++ class, default access specifier is private
	static int nbOfConf;
	string coast;
	vector <Division*> divisions;


	void Construct();


public:
	Conference(string coast, vector<Division*> &divisions);
	virtual ~Conference();
};


#endif /* CONFERENCE_H_ */
