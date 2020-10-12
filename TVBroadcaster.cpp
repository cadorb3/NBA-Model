#include "TVBroadcaster.h"


TVBroadcaster::TVBroadcaster(string name, int age, string position, float PPG, int nbOfWin): NBAMember (name, age),
Player(name, age, position, PPG), Coach (name, age ,nbOfWin){




}


TVBroadcaster::~TVBroadcaster() {
}


void TVBroadcaster :: Display(){
	std::cout<<"\n The TVBroadcaster "<<name<<" is a former NBA Player and coach, he is "<<age<<" years old, he played "<<position;
	std::cout<<" and averaged "<<PPG<<" PPG. As a coach, he won "<<nbOfWin<<" games.";
}
