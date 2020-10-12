#ifndef TVBROADCASTER_H_
#define TVBROADCASTER_H_


#include <iostream>
#include"Player.h"
#include "Coach.h"


class TVBroadcaster : public virtual Player,
	public virtual Coach { //This class inherits both the    
             // player and coach class, but only
             // gets one name state as the base classes have been declared virtual
public:
	TVBroadcaster(string name, int age, string position, float PPG, int nbOfWin);
	virtual ~TVBroadcaster();
	void Display();
	void SetName(string NewName){name=NewName;}
	void SetAge(int NewAge){age=NewAge;}
};


#endif /* TVBROADCASTER_H_ */
