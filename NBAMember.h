#ifndef NBAMEMBER_H_
#define NBAMEMBER_H_


#include <iostream>
#include <string>
using  std::string;


class NBAMember {
protected:
	string name;
	int age;
public:
	NBAMember(string name, int age);
	virtual ~NBAMember();
	virtual void SetAge(int NewAge){age=NewAge; std::cout<<"\n The                NBAMember has changed age";};
	void SetName(string NewName){name=NewName; std::cout<<"\n The NBAMember has changed name";};
	virtual void Display()=0; // This line makes the NBAMember class abstract : all children should override  the Display() function
};


#endif /* NBAMEMBER_H_ */
