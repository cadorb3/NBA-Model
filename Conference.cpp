#include "Conference.h"


int Conference :: nbOfConf=0;


Conference::Conference(string coast, vector <Division*> &divisions):coast(coast),divisions(divisions) {
	if(nbOfConf==2){
		throw 2;
	}else if(divisions.size()>3){
		throw 3;
	}
	Construct();
}


//  This destructor deletes all divisions in the conference, which is necessary as the divisions are
//pointers hence do not delete themselves at the end of the main function
Conference::~Conference() {
for(int i=0; i<divisions.size();i++){
	delete divisions[i];
}
std::cout<<"\n [The "<<coast<<" conference has been deleted]";
			}


void Conference :: Construct(){
	nbOfConf++;
}
