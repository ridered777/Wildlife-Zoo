/*
 * Mammal.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

using namespace std;

class Mammal : public Animal{
	//Inherits Animal base class. To be used by the mammal subtypes.
public:
	Mammal();
	int getNurse() const;
	void setNurse(int nurse);

private:
	int nurse;
};

#endif /* MAMMAL_H_ */
