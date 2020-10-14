/*
 * Pelican.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Pelican.h"

Pelican::Pelican() {
	// Basic Constructors both default and one we'll use that includes the number of eggs.
	Oviparous();
	this->subType = "Pelican";
}
Pelican::Pelican(int numOfEggs){
	Oviparous();
	this->subType = "Pelican";
	this->setNumOfEggs(numOfEggs);
}

