/*
 * Goose.h
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include "Oviparous.h"

using namespace std;

class Goose: public Oviparous {
public:
	Goose();
	Goose(int numOfEggs);
};

#endif /* GOOSE_H_ */
