/*
 * Goose.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Goose.h"

Goose::Goose() {
	// Basic Constructors, both a default one and one we'll use that includes egg count.
	Oviparous();
	this->subType = "Oviparous";
}
Goose::Goose(int numOfEggs){
	Oviparous();
	this->subType = "Oviparous";
	this->setNumOfEggs(numOfEggs);
}

