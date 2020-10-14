/*
 * Mammal.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Mammal.h"

Mammal::Mammal() {
	// Default constructor
	this->nurse = 0;
	this->type = "Mammal";
}

//Basic getters and setters.
int Mammal::getNurse() const{
	return this->nurse;
}

void Mammal::setNurse(int nurse){
	this->nurse = nurse;
	return;
}

