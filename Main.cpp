#include <iostream>
#include <vector>
#include <algorithm>
#include "Output.h"
#include"Player.h"
#include "Coach.h"
#include "Team.h"
#include "Division.h"
#include "Conference.h"
#include "NBAMember.h"
#include "TeamMedic.h"
#include "TVBroadcaster.h"
using std::string;
using std::vector;




int main(){


	const int AverageWin=41;
	try{


/*** CREATING OBJECTS FOR DEMONSTRATION PURPOSE ***/


Player Curry("Stephen Curry", 31,"Point guard", 23.5);
Player GeminiCurry("John Doe",1,"Not a player", 3);
TeamMedic Cole ("Brian Cole", 40);
NBAMember *VanGundy=new TVBroadcaster("Jeff VanGundy", 50, "Guard", 12,100);


//Use of const_cast to pass a constant value to a function that modifies this value
//then use of reinterpret cast to create a pointer to the same object as demo, using conversion of address to long
//then convert long to an address
Team *Demo= new Team ("Paris","Panthers",*const_cast<int*>(&AverageWin));
long addr=reinterpret_cast<long>(Demo);
Team *Test=reinterpret_cast<Team*>(addr);


vector <Player> vect={Curry, GeminiCurry};


/*** CREATING THE PLAYERS FOR THE TEAMS ***/


NBAMember *Markannen= new Player ("Lauri Markannen", 20,"Power Forward", 24);
Player *LaVinne= new Player("Zach Lavine", 23, "Guard", 25);
Player *CarterJr= new Player ("Wendell Carter Jr", 20,"Center",10);
Player *White= new Player ("Coby White",20,"Point Guard",12);
Player *PorterJr= new Player ("Otto Porter Jr",22,"Guard",18);


Player *Lebron = new Player("Lebron James", 34, "Forward", 28);
Player *AD= new Player ("Anthony Davis", 25, "Power Forward", 29);
Player *Rondo = new Player("Rajon Rondo", 31, "Point Guard", 12);
Player *Howard = new Player("Dwight Howard", 32, "Center", 7);
Player *Bradley = new Player("Avery Bradley", 30, "Guard", 10);


Player *Embiid = new Player("Joel Embiid", 20,"Center", 26);
Player *Simmons = new Player("Ben Simmons",20,"Point Guard", 20);
Player *Horford = new Player("Al Horford",31,"Center",19);
Player *Harris =new Player("Tobias Harris", 29, "Forward", 19.5);
Player *Burke = new Player ("Trey Burke", 24,"Guard",1.5);


Player *Walker = new Player("Kemba Walker",29,"Point Guard",22);
Player *Tatum=new Player ("Jason Tatum",21,"Forward",20.3);
Player *Brown=new Player("Jaylen Brown",23,"Guard",17.3);
Player *Hayward=new Player ("Gordon Hayward",29,"Forward",16.3);
Player *Kanter=new Player("Enes Kanter",27,"Center",12);


Player *Rose=new Player("Derrick Rose",30,"Point Guard",20);
Player *Snell =new Player("Tony Snell",25,"Guard",12);
Player *Griffin=new Player("Blake Griffin",30,"Power Forward",0);
Player *Morris=new Player("Markieff Morris",30,"Forward",18);
Player *Kennard=new Player("Luke Kennard",25,"Guard",15);


Player *Leonard=new Player("Kawhi Leonard",27,"Forward",28);
Player *Beverley=new Player("Patrick Beverley",30,"Point Guard",12);
Player *George=new Player("Paul George",30,"Forward",23);
Player *Harrell=new Player("Montrezl Harrell",30,"Forward",14);
Player *Patterson=new Player("Patrick Patterson",30,"Forward",10);




vector <Player*> B = { dynamic_cast<Player*>(Markannen), LaVinne, CarterJr, White, PorterJr}; //POINT 12 :
 //dynamic_cast used because
 //NBAMember is an Abstract class
vector <Player*> L= {Lebron, AD, Rondo, Howard, Bradley};
vector <Player*> P={Rose, Snell, Griffin,Morris,Kennard};
vector <Player*> S={Embiid, Simmons,Horford,Harris,Burke};
vector <Player*> Bo={Tatum,Brown,Hayward,Kanter,Walker};
vector <Player*> C={Leonard,Beverley,George,Harrell,Patterson};


/*** CREATING THE COACHES ***/


Coach Vogel("Franck Vogel",46,304);
Coach Pop("Greg Poppovich", 60,1000);
Coach Boylen ("James Boylen",50,100);
Coach Rivers("Doc Rivers",50,200);
Coach Casey("Dwane Casey",50,200);
Coach Stevens("Brad Stevens",40,200);
Coach BBrown("Brett Brown",65,100);


/*** CREATING THE TEAMS ***/


//new pointers created, then stored into a vector.
//Those pointers will then be deleted because of the destructors of Conference, Division and Team
Team *Bulls=new Team("Chicago","Bulls",Boylen,B);
Team *Lakers=new Team ("Los Angeles","Lakers", Vogel,L);
Team *Pistons=new Team("Detroit", "Pistons",Casey,P);
Team *Sixers=new Team("Philadelphia","76ers",BBrown,S);
Team *Celtics=new Team("Boston","Celtics",Stevens,Bo);
Team *Clippers=new Team("Los Angeles","Clippers",Rivers,C);


vector <Team*> Pa={Lakers, Clippers};
vector <Team*> A={Celtics, Sixers};
vector <Team*> Ce={Bulls,Pistons};


/*** CREATING DIVISIONS AND CONFERENCE ***/


Division *Pacific=new Division(Pa,"Pacific","West");
Division *Atlantic=new Division(A,"Atlantic","East");
Division *Central=new Division(Ce,"Central","East");


vector <Division*> W={Pacific,Atlantic,Central};


Conference West("Western", W);


/*** DEMONSRATION AND TEST SECTION FOR THE ASSIGNMENT ***/


Curry==GeminiCurry;
Curry>GeminiCurry;
GeminiCurry=Curry;
Curry==GeminiCurry;
Curry>GeminiCurry;


//West.coast="East";  // This line would make the build fail
 	 	  //as default access specifier is private for Conference class


Cole.age=10;		// This is authorized
 	 	 	 // as default access specifier is public for TeamMedic struct
for_each(vect.begin(),vect.end(),Output<Player>()); //  use of an algorithm on a container
VanGundy->Display();
VanGundy->SetAge(70);		   //Calls the TVBroadcaster function as SetAge has been declared virtual
VanGundy->SetName("VanGondy");//Calls NBAMember function as SetName is non-virtual
Demo->Display();//  This will show that the Demo team has won 41, not 42 games
Test->Display();//Test and demo are the same due to the manipulation of addresses with reinterpret_cast
	}
catch(int i){
	switch (i){
	case 30: std::cerr<<"\n Too many teams have been created"; break;


	case 15: std::cerr<<"\n Too many players in a team"; break;


	case 6 : std::cerr<<"\n Too many divisions have been created"; break ;


	case 5 : std::cerr<<"\n Too many teams in a division"; break ;


	case 3 : std::cerr<<"\n Too many divisions in a conference"; break ;


	case 2 : std::cerr<<"\n Too many conferences have been created";
	}
}


	return 0;


}
