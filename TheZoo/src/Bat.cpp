/*
 * Bat.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Bat.h"

Bat::Bat() {
	// Basic Constructors, both a default one and one that we'll use to apply the nursing flag.
	Mammal();
	this->subType = "Bat";

}

Bat::Bat(int nurse){
	Mammal();
	this->subType = "Bat";
	this->setNurse(nurse);
}

