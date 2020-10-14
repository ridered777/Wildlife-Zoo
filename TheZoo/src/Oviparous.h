/*
 * Oviparous.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "Animal.h"

using namespace std;

class Oviparous: public Animal {
public:
	Oviparous(); //Basic constructor
	int getNumOfEggs() const;
	void setNumOfEggs(int numOfEggs);

private:
	int numOfEggs;
};

#endif /* OVIPAROUS_H_ */
