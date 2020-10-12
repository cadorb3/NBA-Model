#ifndef PLAYER_H_
#define PLAYER_H_


#include <iostream>
#include <string>
#include "NBAMember.h"
using std::string;


class Player : public virtual NBAMember{


protected: //  States are protected, as Player has a child class
	string position;
	float PPG;
public: //  Only functions are declared as public
	Player(string name, int age, string position, float PPG);
	virtual ~Player();
	Player(const Player &other);
	virtual void SetPPG(float NewPPG){PPG=NewPPG;};
	virtual void SetPosition (string NewPosition ){position=NewPosition;};
	virtual void SetAge(int NewAge){age=NewAge;};
	void SetName(string NewName){name=NewName; std::cout<<"\n The player has changed name";};
	virtual string GetName() const {return name;};
	virtual void operator = (const Player &other);
	virtual bool operator == (const Player &other);
	virtual bool operator > (const Player &other);
	virtual void Display();
	virtual int RandomStat();
};


#endif /* PLAYER_H_ */
