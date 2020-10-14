/*
 * Oviparous.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "Oviparous.h"

Oviparous::Oviparous() {
	// Basic constructor for the oviparous type defaults. Will be used to construct applicable subtypes.
	this->numOfEggs = 0;
	this->type = "Oviparous";
}
//Basic setters and getters
int Oviparous::getNumOfEggs() const{
	return this->numOfEggs;
}
void Oviparous::setNumOfEggs(int numOfEggs){
	this->numOfEggs = numOfEggs;
	return;
}

