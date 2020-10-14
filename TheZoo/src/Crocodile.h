/*
 * Crocodile.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"

using namespace std;

//Inherits Oviparous which inherits Animal
class Crocodile: public Oviparous {
public:
	Crocodile();
	Crocodile(int numOfEggs);
};

#endif /* CROCODILE_H_ */
