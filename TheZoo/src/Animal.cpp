/*
 * Animal.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Animal.h"

using namespace std;

Animal::Animal() {
	//Constructor
	this ->name = "none";
	this ->trackNum = 0;

}

Animal::~Animal() {
	// Destructor
}
string Animal::getName() const{
	return this->name;
}

int Animal::getTrackNum() const{
	return this->trackNum;
}
string Animal::getType() const{
	return this->type;
}

string Animal::getSubType() const{
	return this->subType;
}

int Animal::getNurse() const{
	return 0;
}

int Animal::getNumOfEggs() const{
	return 0;
}

void Animal::setName(string name){
	this->name = name;
	return;
}

void Animal::setTrackNum(int trackNum){
	this->trackNum = trackNum;
	return;
}

void Animal::setNumOfEggs(int numOfEggs){
	return;
}

void Animal::setNurse(int nurse){
	return;
}
