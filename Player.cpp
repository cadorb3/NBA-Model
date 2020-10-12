#include "Player.h"




Player::Player(string name, int age, string position, float PPG) : NBAMember(name,age), position(position), PPG(PPG){
	std::cout<<"\n [The player "<<name<<" has been created]";
}


Player::~Player() {
	std::cout<<"\n [The player "<<name<<" has retired]";
}


Player::Player(const Player &other):NBAMember(other.name,other.age), position(other.position),PPG(other.PPG) {
	std::cout<<"\n [The player "<<name<<" has been created]";


}
// Here are the three over-loaded operators
void Player :: operator = (const Player &other){
	this->age=other.age;
	this->name=other.name;
	this->position=other.position;
	this->PPG=other.PPG;
}


bool Player :: operator ==(const Player &other){
	if(this->name==other.name && this->age==other.age){
		std::cout<< "\n The two players are the same";
		return true;
	}
	else{
		std::cout<<"\n The two players are different";
		return false;
	}
}


bool Player :: operator > (const Player &other){
	if (PPG > other.PPG ){
	std::cout<<"\n "<<this->name<<" scores more than "<<other.name;
	return true;
	}else if(PPG==other.PPG){
		std::cout<<"\n The two players average the same number of PPG";
		return false;
	}else{
		std::cout<<"\n "<<other.name<<" scores more than "<<this->name;
		return false;
	}
}




void Player :: Display(){ //  This over-rides the method of the NBAMember class
	std::cout<<"\n The player "<<name<<" is "<<age<<" years old, he plays "<<position<<" and averages "<<PPG<<" ppg";
}


int Player :: RandomStat(){
	// Use of static cast to downgrade a float to an int to generate a random stat
	return static_cast<int>(PPG)*age;
}

