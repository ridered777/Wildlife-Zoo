/*
 * Crocodile.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Crocodile.h"

Crocodile::Crocodile() {
	// Basic Constructors, both a default and one that we'll use to include the egg count.
	Oviparous();
	this->subType = "Crocodile";
}
Crocodile::Crocodile(int numOfEggs){
	Oviparous();
	this->subType = "Crocodile";
	this->setNumOfEggs(numOfEggs);
}

