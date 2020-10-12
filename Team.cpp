#include "Team.h"


int Team :: nbOfTeams=0;


Team::Team(string town, string name,int &newnbOfWin): town(town), name(name) {
	if(nbOfTeams==30){
			throw 30;
		} else if(roster.size()>15){
			throw 15;
		}
	this->nbOfWin=newnbOfWin++;
	construct();
	std::cout<<"\n [The team "<<town<<" "<<name<<" has been created]";


}


Team :: Team(string town, string name, Coach &coach, vector <Player*> &roster): town(town), name(name), coach(coach),roster(roster),
nbOfWin(0){
	if(nbOfTeams==30){
		throw 30;
	} else if(roster.size()>15){
		throw 15;
	}
	std::cout<<"\n[A team has just been created ";
	Display();
	std::cout<<"]";
	construct();
}
//This modified constructor shows the properties of the pass by reference as
// no copy of the other team is created to call the copy constructor


Team :: Team(const Team &other) : name(other.name),town(other.town),nbOfWin(other.nbOfWin),roster(roster),
coach(coach){


	if(nbOfTeams==30){
			throw 30;
		} else if(other.roster.size()>15){
			throw 15;
		}
	std::cout<<"\n[A team has just been created by copy ";
		Display();
		std::cout<<"]";
	construct();
}






Team::~Team() {
	for(int i=0;i<roster.size();i++){
		delete roster[i];
	}
	std::cout<<"\n [The team "<<town<<" "<<name<<" has been destroyed] ";
}


void Team :: construct(){
nbOfTeams++;


}


void Team :: AddPlayer(Player &player){


	Player *ptr=&player;


	if( roster.size()==15){
		throw 15;
	}
	else{
//The object passes itself to the function in order to modify its roster
		roster.push_back(ptr);
		std::cout<<"\n [A player has been added to the team]";
	}


}


void Team :: AddCoach(const Coach &NewCoach){
	coach=NewCoach;
}


void Team :: Display(){
	std::cout<<"\n The roster of the "<<town<<" "<<name<<" is ";
	for(int i=0; i<roster.size();i++ ){
		std::cout<<(roster[i])->GetName()<<" "; //Calling a method for all the pointers contained
												//in the roster, a vector of pointers
	}
	std::cout<<" ,they are coached by "<<coach.GetName()<<" and have won "<<nbOfWin<<" games this season";
}


void Team :: operator =(Team *other) {
		name=other->name;
		town=other->town;
		nbOfWin=other->nbOfWin;
		roster=other->roster;
		coach=other->coach;


}
