#ifndef _COMMUNICATIONS_H_
#define _COMMUNICATIONS_H_
#include "Subsystem.hpp"


class Communications : public Subsystem
{


private:
	
	
	enum STATUSTEMPLATE
	{
		NOT_STARTED, IN_PROGRESS, FINISHED

	};

	struct C_ITEM             //Item Details Structure
	{
		double ITEMNUMBER; //within order
		double ITEMCODE;   // EAN 13 digit bar code
		double ITEMNAME;
		int LOCATIONCODE;
		double ITEMWEIGHT;
		STATUSTEMPLATE ITEMSTATUS;
		bool ITEMPRIORITY;
	};

	struct C_ORDER        //ORDER Details structure
	{
		int ORDERNUMBER;
		std::vector<C_ITEM> ITEMLIST;
		STATUSTEMPLATE ORDERSTATUS;

	};

	struct C_COORD_OFFSET
	{
		int LOCATIONCODE;
		COORDS COORDSCURRENT;
		COORDS COORDSOFFSET;

	};


	std::vector<std::string> Initialisation_AttributeNameList
	{

		{"C_NETCONNECTION_FLAG"}

	};

	std::vector<std::string> RobotNewOrderData_AttributeNameList
	{
		"orderCode", "orderPriority", "itemCode", "itemName", "weight", 
		"warehouseItemLocationCode", "itemXCoordinate", "itemYCoordinate", "itemZCoordinate", "itemTheta"

	};

	std::vector<std::string> RobotOrderComplete_AttributeNameList
	{
		"orderCodeCompleted", "itemCodeCompleted", "warehouseItemLocationCode"
		 "updatedXCoordinate", "updatedYCoordinate", "updatedZCoordinate", "updatedTheta"

	};

	std::vector<std::string> RobotUnexpectedObject_AttributeNameList
	{
		"unexpectedObjectReportStatus","unexpectedObjectXCoordinate", "unexpectedObjectYCoordinate"

	};

	std::vector<std::string> RobotTelemetryData_AttributeNameList
	{
		"currentTime", "currentXCoordinate" , "currentYCoordinate", "battery", "jobStatus", "jobsinQueue", "unexpectedObstacle"

	};

	std::string Initialisation_Attribute_CSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Communications_Attributes.csv" };
	std::string RobotTelemetry_CSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Hub/robotTelemetryData_ID_1.csv" };
	std::string RobotOrderComplete_CSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Hub/robotOrderCompleteData_ID_1.csv" };
	std::string RobotNewOrderData_CSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Hub/newOrderData_ID_1.csv" };
	std::string RobotUnexpectedObject_CSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Hub/unexpectedObjectReportedData_ID_1.csv" };

	

	int C_NETCONNECTION_FLAG;  //Accessible to Program (Flags)

	

	std::vector<C_COORD_OFFSET> COORDS_OFFSET_TABLE
	{
	};

	std::vector<C_ORDER> C_ORDER_LIST   //Multidimensional vector to store orders
	{
	};


	std::vector<std::string> STATUSTEMPLATE_MAP    //Vector for conversion of ENUM values to string
	{
		"NOT_STARTED",
		"IN_PROGRESS",
		"FINISHED"
	};

public:

	Communications(const int SYS_ID, int SYS_OP);    //Class Constructor

	int getNETCONNECTION_FLAG();       //Method Function to obtain Networkconnection Status

	C_ORDER getACTIVEORDER(); //Function to return  entire Orderlist vector
	C_ITEM getACTIVEITEM(); //Function to return Active items
	COORDS getLOCATIONCODECOORDS(int LocationCode);


	int	 addORDER();						// Adds empty order to job list
	int	 addORDER(int ORDERNUMBER);						// Adds empty order to job list
	void addITEMtoORDER(int ORDERNUMBER, double ITEMCODE, double ITEMNAME, int LOCATIONCODE, double ITEMWEIGHT, bool ITEMPRIORITY);  //adds item to specified order
	
	void changeITEM_STATUS(int ORDERNUMBER, double ITEMNUMBER, int ITEM_STATUS);       //promotes ITEM status
	void viewITEMinORDER(int ORDERNUMBER, double ITEMNUMBER);  //views specified item within an order
	void viewITEMinORDER(int ORDERNUMBER);  //function overload that views all items in an order
	void viewORDER(int ORDERNUMBER);	//Prints Order details including size and status
	void viewORDER();					//function overload the views all orders
	
	void writeRobot_Telemetry_toCSV();           //Sent every 5 seconds
	void writeRobot_Order_Complete_toCSV();	//Sent every time an order and all of its items are complete
	void readUnexpected_Object_Report_fromCSV();         // Read in Unexpected object data when it occurs
	void readNew_Order_Data_fromCSV();			//Read Order data in between orders (Part of subroutine) Ensure priority is considered in ordering
	void InitialiseAttributesfromCSV();        //Conducted on System start

protected:
	void printITEM(int ORDERUMBER, double ITEMNUMBER);
	void printORDER(int ORDERNUMBER);
	void refreshORDER_STATUS(int ORDERNUMBER); //checks if items are complete and amends order status if so
	 
};

#endif


//To DO: Write CSV Functions use references to classes