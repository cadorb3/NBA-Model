#ifndef COACH_H_
#define COACH_H_


#include <iostream>
#include <string>
#include "NBAMember.h"


using std::string;


class Coach : public virtual NBAMember {


protected:
	int nbOfWin;
public:
	Coach(string name, int age, int nbOfWin);
	Coach();
	virtual ~Coach();
	Coach(const Coach &other);
	virtual void SetAge(int NewAge){age=NewAge;};
	void SetName (string NewName){name=NewName;};
	virtual void SetNbOfWin(int NewNbOfWin){nbOfWin=NewNbOfWin;};
	virtual string GetName() const {return name;} ;
	virtual void Display();
	virtual void operator = (Coach const &other);
};


#endif /* COACH_H_ */
