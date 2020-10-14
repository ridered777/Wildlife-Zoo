/*
 * Animal.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>

using namespace std;

class Animal {
public:
	Animal(); //Constructor
	virtual ~Animal() = 0; //Destructor

	string getName() const;
	int getTrackNum() const;
	string getType() const;
	string getSubType() const;

	//virtual functions to look at subclasses and return the egg# or nursing flag
	virtual int getNumOfEggs() const;
	virtual int getNurse() const;

	void setName(string name);
	void setTrackNum(int trackNum);
	virtual void setNumOfEggs(int numOfEggs);
	virtual void setNurse(int nurse);

private:
	string name;
	int trackNum;
protected:
	string type;
	string subType;
};


#endif /* ANIMAL_H_ */
