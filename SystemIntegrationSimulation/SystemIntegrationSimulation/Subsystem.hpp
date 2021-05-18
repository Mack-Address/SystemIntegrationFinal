#ifndef _SUBSYSTEM_H_
#define _SUBSYSTEM_H_
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include "fake_clock.hh"
#include "rapidcsv.h"

class Subsystem
{
private:
	
	int S_SYS_OP;				//Attributes
	int S_SYS_ID;

	
	

public:							//Methods

	
	struct COORDS {

		double X;
		double Y;
		double Theta;


	};
	
	
	
	Subsystem(const int SYS_ID, int SYS_OP=0);	//ClassConstructor
	
	int getSYS_OP();            //Retrieve SYSOP	
	const int getSYS_ID();

	void setSYS_OP(int NEW_SYS_OP);

	int writetoConsoleCSV(std::string Status_Message, testing::fake_clock::time_point);

	std::vector<double> Sub_readAttributesfromCSV(std::vector<std::string> AttributeList, std::string FileAddress);
	std::vector<std::vector<double>> Col_readAttributesfromCSV(std::vector<std::string> AttributeList, std::string FileAddress);


	void Sub_writeAttributestoCSV(std::vector<std::string> AttributeList, std::string FileAddress, std::vector<double> AttributeValues);

	std::string getSYSTEM_TIME();


	
	

	

	

protected:

	
};


#endif


//TO DO:
//       Create functions to read/write vector of generic struct to CSV file (Include system time in filename)
//      Create function to turn subsystem on and off
