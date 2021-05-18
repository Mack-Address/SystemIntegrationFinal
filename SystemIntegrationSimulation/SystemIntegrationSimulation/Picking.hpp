#ifndef _PICKING_H_
#define _PICKING_H_
#include "Subsystem.hpp"


class Picking : public Subsystem
{


private:



	int PickingStatus{ 0 };

	std::vector<std::string> AttributeNameList
	{
		{"PickingStatus"}

	};

	std::string AttributeCSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Picking_Attributes.csv" };

public:

	Picking(const int SYS_ID, int SYS_OP);    //Class Constructor

	int getPickingStatus();
	std::vector<double>	InitiatePicking(double ITEMCODE, int LOCATIONCODE);  //returns offsets

	void InitialiseAttributesfromCSV(); //Initialisation of system from external CSV file
	void writeAttributestoCSV(); //Store Attributes to CSV to allow continuous program running //Weight of item, Lift height

protected:





};

#endif


