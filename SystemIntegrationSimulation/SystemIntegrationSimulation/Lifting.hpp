#ifndef _LIFTING_H_
#define _LIFTING_H_
#include "Subsystem.hpp"


class Lifting : public Subsystem
{


	const double L_Level_Spacing{ 400 };			//Spacing between lifts in mm
	const double L_FloortoRacking_Spacing{700}; //Spacing between floor and Level 1
	const double L_FloortoLiftBase_Spacing{ 500 }; //spacing between lift base and floor
	const double L_Lift_Height_Max{ 3000 };

private:

	std::vector<std::string> AttributeNameList
	{
		{"L_Lift_Level", "L_Lift_Height", "L_Lift_Storage_Actuator", "L_Weight_Of_Item"}

	};

	std::string AttributeCSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Lifting_Attributes.csv" };



	int L_Lift_Level{ 0 };
	double L_Lift_Height{ 0 };			//Actual Lift height in mm
	bool   L_Lift_Storage_Actuator{ false };
	int L_Weight_Of_Item;

public:

	Lifting(const int SYS_ID, int SYS_OP);    //Class Constructor

	int getLift_Level();					 //Functions for gettimg values					
	double getLift_Height();
	bool getLift_Storage_Actuator();
	
	int changeLift_Level(int New_Lift_Level);                 //Functions for changing lift status, return 1 if successful and 0 if not
	int changeLift_Height(double New_Lift_Height);
	int changeLift_Storage_Actuator(bool Storage_Actuator_Bool);


	void InitialiseAttributesfromCSV(); //Initialisation of system from external CSV file
	void writeAttributestoCSV(); //Store Attributes to CSV to allow continuous program running //Weight of item, Lift height
	

protected:

	



};

#endif


//TO DO::
//			Define all Getting/setting functions
//          Define function for lifting subroutine 
//			Response and iteration for if lift height is wrong
//			Outputs are Lift Height, 
