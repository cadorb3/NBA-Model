#ifndef TEAM_H_
#define TEAM_H_


#include <iostream>
#include <vector>
#include <string>
#include "NBAMember.h"
#include "Player.h"
#include "Coach.h"


using std::string;
using std::vector;


class Team {
protected:
	static int nbOfTeams;


private:
	string town;
	string name;
	int nbOfWin;
	//Here using a vector to contain pointers to Player objects
	vector<Player*> roster;
	vector<int> test;
	Coach coach;
	void construct();


public:
	Team(string town, string name, Coach &coach, vector <Player*> &roster);
	Team(string town, string name,int &nbOfWin);// Overloading constructor to allow the creation of an empty team
//that could be "filled" after creation
	Team(const Team &other);
	virtual ~Team();
	void AddPlayer(Player &player);
	void AddCoach(const Coach &Newcoach);
	void SetName(string NewName){name=NewName;};
	void SetTown (string NewTown){town=NewTown;};
	void GameWon(){nbOfWin++;};
	string GetName(){return name;};
	void Display();
	void operator = (Team *other);
};


#endif /* TEAM_H_ */
