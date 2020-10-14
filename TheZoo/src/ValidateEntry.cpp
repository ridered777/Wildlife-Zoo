/*
 * ValidateEntry.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: 1746961_snhu
 */

#include "ValidateEntry.h"
#include <string>
#include <iostream>
#include <algorithm> //library with the for_each function.

using namespace std;

//This class helps validate the entry of the data entities with known parameters.
//This will make displaying and entering the data for those entities easier and quicker since the error handling can be re-used.

//Function to validate the entry of tracking numbers
int inputTrackNumber(){
	string entryAsString;
	int trackNum;
	bool validEntry;
	do{
		validEntry = true;
		try{ //Use try/catch loop per feedback in project 2
			cout << "Enter Tracking Number with no leading zeros: " << endl;
			cin >> entryAsString;
			cin.ignore();
			if(entryAsString.length() > 6){
				throw runtime_error("Please enter a valid entry. Should not exceed 6 characters.");
			}
			trackNum = stoi(entryAsString);
			if(trackNum < 0){
				throw runtime_error("Please enter a valid entry. Should be greater than 0.");
			}
		}catch(runtime_error& excpt){ //catch the runtime errors
			cout << excpt.what() << endl;
			cout << endl;
			validEntry = false;
		}
	}while(!validEntry);
	return trackNum;
}

//Function to validate the entry of animal names.
string inputAnimalName(){
	string animalName;
	bool validEntry;

	do{
		validEntry = true;
		try{
			cout << "Please enter the Animal Name: " << endl;
			getline(cin, animalName);
			if(animalName.length() > 15){ // per tech specs, names cannot exceed 15 characters
				throw runtime_error("Please enter a valid entry. Should be less than 15 characters.");
			}
		}catch(runtime_error& excpt){ // catch the runtime errors
			cout << excpt.what() << endl;
			cout << endl;
			validEntry = false;
		}
	}while(!validEntry);
	//Keep the naming of Sea Lion's consistent.
	if(animalName == "Sea Lion"){
		animalName = "SeaLion";
	}
	return animalName;
}

//Function to validate the entry of animal types
string inputAnimalType(){
	string animalType;
	bool validEntry;

	do{
		validEntry = true;
		try{
			cout << "Please enter the Animal Type: " << endl;
			getline(cin, animalType);
			//Check for the proper animal type. Accept if first letter is capitalized or not.
			if((animalType != "mammal") && (animalType != "Mammal") && (animalType != "oviparous") && (animalType != "Oviparous")){
				throw runtime_error("Please enter a valid entry. Should be Mammal or Oviparous.");
			}
		}catch(runtime_error& excpt){
			cout << excpt.what() << endl;
			cout << endl;
			validEntry = false;
		}
	}while(!validEntry);
	return animalType;
}

//Function to validate the entry of animal sub types
string inputAnimalSubType(string animalType){
	string animalSubType;
	bool validEntry;

	do{
		validEntry = true;
		try{
			cout << "Please enter the Animal SubType: " << endl;
			getline(cin, animalSubType);
			//Convert each character of string to lowercase to make comparisons easier.
			for_each(animalSubType.begin(), animalSubType.end(), [](char & c){
				c = ::tolower(c);
			});
			//Verify valid entries for the mammal Type
			if((animalType == "mammal") && (animalSubType != "bat") && (animalSubType != "sea lion") && (animalSubType != "whale")){
				throw runtime_error("Please enter a valid sub-type for Mammal.");
			}
			//Verify valid entries for the oviparous Type
			if((animalType == "oviparous") && (animalSubType != "goose") && (animalSubType != "crocodile") && (animalSubType != "pelican")){
				throw runtime_error("Please enter a valid sub-type for Oviparous.");
			}
		}catch(runtime_error& excpt){
			cout << excpt.what() << endl;
			cout << endl;
			validEntry = false;
		}
	}while(!validEntry);
	return animalSubType;
}

//Function for validating entry of nursing flag based on the animal type
int inputNurse(string animalType){
	string entryAsString;
	int nurse;
	bool validEntry;

	if((animalType == "oviparous") || (animalType == "Oviparous")){
		cout << "Nursing Flag isn't applicable for Oviparous animal Types." << endl;
		nurse = 0;
	}else{
		do{
			validEntry = true;
			try{
				cout << "Enter Nursing Flag. 1 for Yes, 0 for no.: " << endl;
				cin >> entryAsString;
				cin.ignore();
				nurse = stoi(entryAsString);
				if((nurse != 0) || (nurse != 1)){
					throw runtime_error("Please enter a valid flag, 0 or 1.");
				}
			}catch(runtime_error& excpt){
				cout << excpt.what() << endl;
				cout << endl;
				validEntry = false;
			}
		}while(!validEntry);
	}
	return nurse;
}

//Function for validating entry of egg number and keeping it with only the applicable animal type
int inputEggs(string animalType){
	string entryAsString;
	int numOfEggs;
	bool validEntry;

	if ((animalType == "mammal") || (animalType == "Mammal")){
		cout << "Egg count isn't applicable for Mammals." << endl;
		numOfEggs = 0;
	}else{
		do{
			validEntry = true;
			try{
				cout << "Enter # of Eggs: " << endl;
				cin >> entryAsString;
				cin.ignore();
				numOfEggs = stoi(entryAsString);
				if(numOfEggs < 0){
					throw runtime_error("Please enter a valid positive number.");
				}
			}catch(runtime_error& excpt){
					cout << excpt.what() << endl;
					cout << endl;
					validEntry = false;
				}
			}while(!validEntry);
		}
	return numOfEggs;
}


