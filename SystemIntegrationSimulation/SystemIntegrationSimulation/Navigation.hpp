#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_
#include "Subsystem.hpp"

class Navigation : public Subsystem
{
private:

					//not used to alter Program flow  (RAW DATA)												
	std::vector<COORDS> Current_Route();
	double N_X_CURRENT;
	double N_Y_CURRENT;
	double N_THETA_CURRENT;
	friend class Drive;

public:

	Navigation(const int SYS_ID, int SYS_OP);    //Class Constructor

	std::vector<std::string> AttributeNameList{

				{"N_X_CURRENT", "N_Y_CURRENT",  "N_THETA_CURRENT"}


	};


	std::string AttributeCSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Navigation_Attributes.csv" };
	
	void InitialiseAttributesfromCSV(); //Initialisation of system from external CSV file
	void writeAttributestoCSV(); //Store Attributes to CSV to allow continuous program running

	std::vector<COORDS> getRoutetoLocation(COORDS COORDS ); //function to get to order TOCOMPLETE

	double getX_CURRENT();				           //Units In Cm																		
	double getY_CURRENT();
	double getTHETA_CURRENT();


protected:

	void REFRESH_N_STATUS();   //Refreshing Values




};


// TO DO :
// Define all relevant attributes associated with system (X y and theta)
//Assign methods for retrieving these as well as reading and writing to CSV (FRIEND CLASS WITH DRIVE?)
// Speak to greg about CSV output format



#endif