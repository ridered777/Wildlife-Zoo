/*
 * Bat.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef BAT_H_
#define BAT_H_

#include "Mammal.h"

using namespace std;

//Inherits Mammal (which inherits Animal)
class Bat: public Mammal {
public:
	Bat();
	Bat(int nurse);
};

#endif /* BAT_H_ */
