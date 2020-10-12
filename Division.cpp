#include "Division.h"


int Division :: nbOfDiv=0;


Division::Division(const vector <Team*> &teams, string name, string coast): name(name) , coast (coast) , teams(teams) {
	// If the number was 2, the program would throw an error,
	// as 3 divisions are created in the main function and nbOfTeam is incremented every time
	// a team is created
	if(nbOfDiv==6){
	throw 6;
}
else if(teams.size()>5){
	throw 5;
}
Construct();
}


Division::~Division() {
	for(int i=0;i<teams.size();i++){
		delete teams[i];
	}
	std::cout<<"\n [The division "<<name<<" has been deleted]";
}


void Division ::Construct(){
	nbOfDiv++;
}


void Division :: AddTeam(Team &team){
	Team *ptr=&team;
	if(teams.size()!=5){
		teams.push_back(ptr);
		std::cout<<"\n [A team has been added to the Division]";
	}
	else{
		throw 5;
	}
}


vector <Team*> Division :: operator +(Division &other){
	vector <Team*> result;
	for(int i=0; i!=2; i++){
		result.push_back(teams[i]);
		result.push_back(other.teams[i]);
	}
	return result;
}


void Division :: Display(){
	std::cout<<"\n The teams in the "<<name<<" division are : ";


	for(int i=0; i<teams.size()-1; i++){
		std::cout<<teams[i]->GetName()<<", ";
	}
	std::cout<<" and "<<teams[teams.size()]->GetName();
}
