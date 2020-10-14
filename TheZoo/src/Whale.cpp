/*
 * Whale.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Whale.h"

Whale::Whale() {
	// Basic Constructors, both a default and one that includes the nursing flag.
	Mammal();
	this->subType = "Mammal";
}
Whale::Whale(int nurse){
	Mammal();
	this->subType = "Mammal";
	this->setNurse(nurse);
}

