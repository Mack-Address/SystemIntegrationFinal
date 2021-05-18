#ifndef _DRIVE_H_
#define _DRIVE_H_
#include "Subsystem.hpp"



class Drive : public Subsystem
{

	friend class Communications;

private:


	

	
	std::vector<std::string> AttributeNameList{
			
			"DriveStatus"

	};
	
	std::string AttributeCSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Drive_Attributes.csv" };




public:

	Drive(const int SYS_ID, int SYS_OP);    //Class Constructor
	

	enum DriveStatusTemplate
	{
		STATIONARY, MOBILE
	};

	DriveStatusTemplate DriveStatus;
	void setDriveStatus(DriveStatusTemplate New_DriveStatus);
	
	

	int Drive_To_Location(std::vector<COORDS> Route); //HeaderFile Function

	

	void InitialiseAttributesfromCSV();
	void writeAttributestoCSV(); //Store Attributes to CSV to allow continuous program running (every time function)

protected:


	



};

#endif


//TO DO::
//			Define all Getting/setting functions
//          Define functions for driving to order
