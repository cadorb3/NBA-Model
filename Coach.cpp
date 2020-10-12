#include "Coach.h"


Coach::Coach(string name, int age, int nbOfWin) :
		NBAMember(name, age), nbOfWin(nbOfWin) {
	std::cout << "\n [The coach " << name << " has been created] ";
}


Coach::Coach() :
		NBAMember("John Doe", 40), nbOfWin(0) {
	std::cout << "\n [The coach " << name << " has been created] ";
}


Coach::~Coach() {
	std::cout << "\n [The coach " << name << " has retired]";
}


Coach::Coach(const Coach &other) :
		NBAMember(other.name, other.age) {
	this->nbOfWin = other.nbOfWin;


}


void Coach::Display() {
	std::cout << "\n The coach " << name << " is " << age
			<< " years old and has a record of " << nbOfWin << " wins";
}


void Coach::operator =(Coach const &other) {


	this->age = other.age;
	this->name = other.name;
	this->nbOfWin = other.nbOfWin;


}
