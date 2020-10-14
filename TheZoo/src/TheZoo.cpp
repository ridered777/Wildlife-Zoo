#include <iostream>
#include <stdexcept> //error handling library
#include <string>
#include <fstream> // for file reading/writing
#include <cctype> //used for tolower()
#include <vector>
#include <jni.h>

#include "Animal.h"
#include "ValidateEntry.h"
#include "bat.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "SeaLion.h"
#include "Whale.h"
//No need to explicitly include the Type files (Mammal and Oviparous) and it would be redundant.

using namespace std;

/*
 * Wildlife Zoo RFID Program
 * CIS 210 - Project 3
 * October 2020
 * Craig Harrigan (and "unnamed Supervisor")
 */

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD (BUT: I Cleaned up whitespace and typos)
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
     //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
     //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialization options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

//Function to assist with errors while loading each of the file inputs to reduce redundant code
bool readFileInput(ifstream &inputFile, string &inputVariable) {
	bool isSuccessful = true;		// flag to return indicating success
	inputFile >> inputVariable;
	if(inputFile.fail()) {			// Catch a failure
		cout << "Error reading certain input from file." << endl;
		isSuccessful = false;
	}
	return isSuccessful;
}

void AddAnimal(vector<Animal*>& zooAnimals){
     /*
            Prompt for data entry, add object to the vector
            Use the input functions with built in verification for the given data types
     */
	//TODO: Get the entry input working through the ValidateEntry
	int trkNumber;
	string anmlName;
	string anmlType;
	string anmlSubType;
	int numOfEggs;
	int nurse;
	char confirmEntry;

	cout << "Enter Tracking Number: "  << endl;
	cin >> trkNumber;
	cout << "Enter Animal Name: " << endl;
	cin >> anmlName;
	cout << "Enter Animal Type: " << endl;
	cin >> anmlType;
	cout << "Enter Animal Sub Type: " << endl;
	cin >> anmlSubType;
	cout << "Enter Animal Egg Count: " << endl;
	cin >> numOfEggs;
	cout << "Enter Animal Nurse Value: " << endl;
	cin >> nurse;
	cout << endl;

	cout << "Add Data? (Y)es or (N)o:";
	// Using a try/catch statement per feedback in project 2.
	try{ // Verify the input
		cin >> confirmEntry;
		cin.ignore();
		confirmEntry = tolower(confirmEntry);
		if((confirmEntry != 'y') && confirmEntry != 'n'){
			throw runtime_error("Invalid Input. Use Y/N Characters");
		}
	}
	catch(runtime_error& excpt){
		cout << excpt.what() << endl;
		cout << endl;
	}
	if(confirmEntry == 'y'){ // if the input is yes, make the animal based on the subtype
		cout << "Entry Confirmed" << endl;
		Animal* animal = nullptr;
		if(anmlSubType == "Bat"){
			animal = new Bat(nurse);
		}else if(anmlSubType == "Crocodile"){
			animal = new Crocodile(numOfEggs);
		}else if(anmlSubType == "Goose"){
			animal = new Goose(numOfEggs);
		}else if(anmlSubType == "Pelican"){
			animal = new Pelican(numOfEggs);
		}else if(anmlSubType == "SeaLion"){
			animal = new SeaLion(nurse);
		}else if(anmlSubType == "Whale"){
			animal = new Whale(nurse);
		}else{
			cout << "Please enter a VALID sub type. Addition Failed." << endl;
		}
		animal ->setTrackNum(trkNumber); // Set the vector values
		animal ->setName(anmlName);
		zooAnimals.push_back(animal); // Add animal to the zooAnimals
		cout << "Animal addition successful. " << endl;
		cout << endl;
	}
	else{
		cout << "Animal addition cancelled. " << endl;
		cout << endl;

	}
	return;

}


void RemoveAnimal(vector<Animal*>& zooAnimals)
{
     string trackNumAsString;
     int trackNumber;
     bool matchFound;
     char confirm;

     //Use try/catch loop for error handling per feedback in project 2.
     try{
    	 cout << "Please enter the Tracking Number to be deleted. Ignore leading zeros.: " << endl;
    	 cin >> trackNumAsString;

    	 if(trackNumAsString.length() > 6){ //verify entry length - we know tracking nums have to be less than 6
    		 throw runtime_error("Invalid Entry");
    	 }
    	 trackNumber = stoi(trackNumAsString); // This will convert the entry into int

     }catch(runtime_error& excpt){
    	 cout << excpt.what() << endl;
    	 cout << endl;
     }
     cout << "Tracking Number Given: " << trackNumber << endl;
     matchFound = false; // set loop flag to false to start
     for(unsigned int i=0; i < zooAnimals.size(); ++i){
    	 if(trackNumber == zooAnimals.at(i)->getTrackNum()){
    		 matchFound = true; // set loop flag for a match, once a match is found we can move forward
    		 break;
    	 }
     }
     if(matchFound){ // Do Deletion
    	 cout << "Found the animal. Do you wish to delete? (Y)es or (N)o." << endl;
    	 try{
    		 cin >> confirm;
    		 confirm = tolower(confirm);
    		 if((confirm != 'y') && confirm != 'n'){ // Verify the input
    			 throw runtime_error("Invalid entry. Please enter Y/N.");
    		 }
    	 }catch(runtime_error& excpt){
    		 cout << excpt.what() << endl;
    		 cout << endl;
    	 }
    	 if(confirm == 'y'){ // Do the Deletion
    		 for(unsigned int i = 0; i < zooAnimals.size(); ++i){
    			 if(trackNumber == zooAnimals.at(i)->getTrackNum()){
    				 cout << trackNumber << " was found. Deleting data." << endl;
    				 delete zooAnimals.at(i); // Delete both the object and pointer to avoid memory leaks
    				 zooAnimals.erase(zooAnimals.begin() + i);
    				 break;
    			 }
    		 }
    		 cout << "Animal successfully deleted" << endl; // This message was specified in tech document
    	 }else{
    		 cout << "Data not Deleted." << endl;
    	 }
     }else{
    	 cout << "Match not found. Data not Deleted." << endl;
     }
     return;

}

void LoadDataFromFile(string fileName, vector<Animal*>& zooAnimals){
     // load data from input file (generated using JNI)into vector/array.
	ifstream inputFile; //input file from which to load data
	string trkNumAsString;
	int trackNum;
	string animalName;
	string animalType;
	string animalSubType;
	string numEggsAsString;
	int numOfEggs;
	string nurseAsString;
	int nurse;

	cout << "Opening file: " << fileName << endl;
	inputFile.open(fileName);
	if(!inputFile.is_open()){ // check if opening was successful
		cout << "File: " << fileName << " could not be opened." << endl;
		cout << endl;
	}else{
		while(!inputFile.eof()){
			//This is where we use our function to handle error checking for each of the file input pieces.
			if(!readFileInput(inputFile, trkNumAsString)){
				break;
			}
			if(!readFileInput(inputFile, animalName)){
							break;
			}
			if(!readFileInput(inputFile, animalType)){
							break;
			}
			if(!readFileInput(inputFile, animalSubType)){
							break;
			}
			if(!readFileInput(inputFile, numEggsAsString)){
							break;
			}
			if(!readFileInput(inputFile, nurseAsString)){
							break;
			}
			//Convert the three ints as strings to ints
			trackNum = stoi(trkNumAsString);
			numOfEggs = stoi(numEggsAsString);
			nurse = stoi(nurseAsString);
		}
		//Create pointer to new object based on input file and build the animal using subtypes
		//This will bring in the egg/nurse flag if needed so we just need to set the tracking number and name afterwards
		Animal* animal = nullptr;
		if(animalSubType == "Bat") {
			animal = new Bat(nurse);
		}else if(animalSubType == "Crocodile") {
			animal = new Crocodile(numOfEggs);
		}else if(animalSubType == "Goose") {
			animal = new Goose(numOfEggs);
		}else if(animalSubType == "Pelican") {
			animal = new Pelican(numOfEggs);
		}else if(animalSubType == "SeaLion") {
						animal = new SeaLion(nurse);
		}else if(animalSubType == "Whale") {
			animal = new Whale(nurse);
		}else {	// break out for invalid (other) entries.
			cout << "Error generating animal object."  << endl;
		}
		animal->setTrackNum(trackNum);
		animal->setName(animalName);
		zooAnimals.push_back(animal); //Add it to the zooAnimals in memory.
	}
	return;

}

//Function to format a given field with the whitespace and write it to an output file.
//For use to reduce redundant code is SaveDataToFile().
void FileFormattedField(string str, int fieldLength, ofstream &outputFile){
	int strLength = str.length();
	outputFile << str;
	for(int i=strLength; i < fieldLength; ++i){
		outputFile << " ";
	}
	return;
}

//Function to format a given number with zeros and write it to an output file.
//For use to reduce redundant code in SaveDataToFile()
void FileFormattedNumber(int number, int fieldLength, ofstream &outputFile){
	char buffer [10];
	string fillerZeros;
	string numAsString = itoa(number,buffer, 10);
	for(int i = numAsString.length(); i < fieldLength; ++i){
		fillerZeros += "0";
	}
	fillerZeros += numAsString;
	outputFile << fillerZeros;

	return;
}

void SaveDataToFile(string fileName, vector<Animal*>& zooAnimals){
     //store vector/array to file.
	string menu = "What would you like to edit?\n"
					"1-Name\n"
					"2-Egg Count\n"
					"3-Nurse Flag\n"
					"4-Save New Data to File\n"
					"5-Exit to Main Menu\n";
	string inputAsString;
	string trackNumAsString;
	int input;
	int currentNumber;
	string newAnimalName;
	string newAnimalType;
	string newAnimalSubType;
	int tempNurse;
	int tempEggs;
	ofstream outputFile;
	ifstream inputFile;
	bool validEntry;
	bool saveSuccess = false;

	Animal* animalPntr = nullptr; // pointer for the animal instance being edited and saved

	//get the tracking number to be edited/saved, same process from LoadDatatFromFile().

	try{
	    	 cout << "Please enter the Tracking Number to be edited/saved. Ignore leading zeros.: " << endl;
	    	 cin >> trackNumAsString;

	    	 if(trackNumAsString.length() > 6){ //verify entry length - we know tracking nums have to be less than 6
	    		 throw runtime_error("Invalid Entry");
	    	 }
	    	 currentNumber = stoi(trackNumAsString); // This will convert the entry into int

	     }catch(runtime_error& excpt){
	    	 cout << excpt.what() << endl;
	    	 cout << endl;
	     }
	     cout << "Tracking Number Given: " << currentNumber << endl; //Use the given tracking # to find the entry
	     for(unsigned int i=0; i < zooAnimals.size(); ++i){
	    	 if(currentNumber == zooAnimals.at(i)->getTrackNum()){
	    		 animalPntr = zooAnimals.at(i); //Set the pointer to that entry
	    		 break;
	    	 }
	     }
	     cout << menu << endl; //Now that we know what we're editing, show the options

	     while(input != 5){

	    	 do{
	    		 validEntry = true;

				 try{ //do/while and try/catch statements to help with errors.
					 cin >> inputAsString;
					 cin.ignore();
					 input = stoi(inputAsString);
					 if((input < 1)|| (input > 5)){
						 throw runtime_error("Please make a valid selection from 1-5.");
					 }
				 }catch(runtime_error& excpt){
					 cout << excpt.what() << endl;
					 cout << endl;
				 }

	     }while(!validEntry);

	    	 switch(input){ //switch table for the menu selections

	     case 1: //Name Change Case
	    	 cout << "Current name: " << animalPntr->getName() << "Enter New Name: " << endl;
	    	 cin >> newAnimalName;
	    	 animalPntr->setName(newAnimalName);
	    	 cout << "New Name: " << animalPntr->getName() << endl;
	    	 cout << menu;
	    	 break;

	     case 2: //Egg Change Case
	    	 cout << "Current egg number: " << animalPntr->getNumOfEggs() << "Enter New Egg Count: " << endl;
	    	 cin >> tempEggs;
	    	 animalPntr->setNumOfEggs(tempEggs);
	    	 cout << "New egg count: " << animalPntr->getNumOfEggs() << endl;
	    	 cout << menu;
	    	 break;

	     case 3: //Nurse Flag Change Case
	    	 cout << "Current Nurse Flag: " << animalPntr->getNurse() << "Enter New Nurse Flag: " << endl;
	    	 cin >> tempNurse;
	    	 animalPntr->setNurse(tempNurse);
	    	 cout << "New Nurse Flag: " << animalPntr->getNurse() << endl;
	    	 cout << menu;
	    	 break;

	     case 4: //Save Data to File Case
	    	 outputFile.open(fileName, ios_base::app); //Open the file in append mode.
	    	 //Save all the new data to the animal
	    	 currentNumber = animalPntr->getTrackNum();
	    	 newAnimalName = animalPntr->getName();
	    	 newAnimalType = animalPntr->getType();
	    	 newAnimalSubType = animalPntr->getSubType();
	    	 tempEggs = animalPntr->getNumOfEggs();
	    	 tempNurse = animalPntr->getNurse();
	    	 // Use the created functions to save it to file with the correct amount of spacing
	    	 FileFormattedNumber(currentNumber, 6, outputFile);
	    	 FileFormattedField(newAnimalName, 15, outputFile);
	    	 FileFormattedField(newAnimalType, 15, outputFile);
	    	 FileFormattedField(newAnimalSubType, 15, outputFile);
	    	 outputFile << " " << tempEggs << " " << tempNurse << " ";
	    	 saveSuccess = true;
	    	 cout << "Save successfully completed" << endl; // This message was specified in tech document

	    	 break;
	     default:
	    	 break; //All other options, including 5 will exit.
	     }
	     }
	     return;

}
void DisplayAnimalData(vector<Animal*>& zooAnimals) {
	//This function wasn't provided as part of the given documents but its inclusion is necessary for the functionality
		// described in the tech document.

	string headerRow = 	"Track# "
						"Name           "
						"Type           "
						"Sub-Type       "
						"Eggs "
						"Nurse ";

	cout << headerRow << endl;
	// Loop through the vector and output the vector contents
	for (unsigned int i = 0; i < zooAnimals.size(); ++i) {
		Animal* animal = zooAnimals.at(i);

		cout << "Tracking #: " << animal->getTrackNum() << endl;;
		cout << "Animal Name: " << animal ->getName() << endl;
		cout << "Animal Type: " << animal->getType() << endl;
		cout << "Animal SubType: " << animal->getSubType() << endl;
		cout << "Egg Count: " << animal->getNumOfEggs() << endl;
		//verify the egg # is valid
		if (animal->getNumOfEggs() > 9) {
			cout << "   ";
		}
		else if (animal->getNumOfEggs() > 99) {
			cout << "  ";
		}
		else {
			cout << "    ";
		}
		cout << "Nurse Flag: " << animal->getNurse() << "   ";
		cout << endl;
	}
	cout << endl;
}
void DisplayMenu(vector<Animal*> zooAnimals){
     string selectionAsString;
     int selection;
     string menu =	"1 - Load animal data from file\n"
     							"2 - Generate animal data\n"
     							"3 - Display animal data\n"
     							"4 - Add animal record\n"
     							"5 - Remove animal record\n"
     							"6 - Save animal data to file\n"
     							"7 - Exit program"; //Set the menu to a string so it doesn't need to be typed out over and over.

     cout << "----------Wildlife Zoo Menu------------" << endl;
     cout << endl;
     cout << "Please select from the following options" << endl;
     cout << endl;
     while(selection != 7){
    	 try{
    		  cout << menu << endl;
    		  cin >> selectionAsString;
    		  selection = stoi(selectionAsString);
    		  if((selection < 1) || (selection > 7)){
    			  throw runtime_error("Please enter a valid entry");
    		  }
    	 }catch(invalid_argument& excpt){
    		 cout << "Please enter a valid entry" << endl;

    	 }catch(runtime_error& excpt){
    		 cout << excpt.what() << endl;
    		 cout << endl;
    	 }
     }
     switch(selection){
     case 1:
    	 LoadDataFromFile("zoodata.txt", zooAnimals); //Calls the created Load Data Function
    	 break;
     case 2:
    	 GenerateData(); //The provided Java Function
    	 break;
     case 3:
    	 DisplayAnimalData(zooAnimals);
    	 break;
     case 4:
    	 AddAnimal(zooAnimals);
    	 break;
     case 5:
    	 RemoveAnimal(zooAnimals);
    	 break;
     case 6:
    	 SaveDataToFile("zoodata.txt", zooAnimals);
    	 break;
     default:
    	 break;
     }
     return;

}



int main()
{
	//When the assignment was given, GenerateData() was being called here.
	//However, calling the menu (which includes Generate Data()) seems more appropriate.
	vector<Animal*> zooAnimals;
	DisplayMenu(zooAnimals);
	return 1;
}
