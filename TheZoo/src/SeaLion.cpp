/*
 * SeaLion.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "SeaLion.h"

SeaLion::SeaLion() {
	// Basic Constructors that include a default and one with the nursing flag.
	Mammal();
	this->subType = "Mammal";
}
SeaLion::SeaLion(int nurse){
	Mammal();
	this->subType = "Mammal";
	this->setNurse(nurse);
}

