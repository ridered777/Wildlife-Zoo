/*
 * ValidateEntry.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef VALIDATEENTRY_H_
#define VALIDATEENTRY_H_
#include <string>
using namespace std;

class ValidateEntry {
public:
	int inputTrackNumber();
	string inputAnimalName();
	string inputAnimalType();
	string inputAnimalSubType();
	int inputEggs(string animalType);
	int inputNurse(string animalType);
};

#endif /* VALIDATEENTRY_H_ */
