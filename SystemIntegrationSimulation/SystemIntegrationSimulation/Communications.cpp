#include "Communications.hpp"
#include <iostream>


Communications::Communications(const int SYS_ID, int SYS_OP)
	:Subsystem{ SYS_ID, SYS_OP }             //Constructor Definitions including Parent Members
{
}

int Communications::getNETCONNECTION_FLAG() {

	return C_NETCONNECTION_FLAG;

};

int Communications::addORDER()
{
	int ORDERNUMBER;
	ORDERNUMBER = C_ORDER_LIST.size() + 1;
	std::vector<C_ITEM> EMPTYITEMLIST;
	STATUSTEMPLATE ORDERSTATUS;
	ORDERSTATUS = NOT_STARTED;

	C_ORDER_LIST.push_back({ ORDERNUMBER, EMPTYITEMLIST, ORDERSTATUS });

	std::cout << "ORDER ADDED. ORDER#: " << ORDERNUMBER << "\n\n";

	return 0;
}

int Communications::addORDER(int ORDERNUMBER)
{
	std::vector<C_ITEM> EMPTYITEMLIST;
	STATUSTEMPLATE ORDERSTATUS;
	ORDERSTATUS = NOT_STARTED;

	for (int i = 0; i < C_ORDER_LIST.size(); i++)
	{
		if (C_ORDER_LIST[i].ORDERNUMBER == ORDERNUMBER) {
			return 0;

		}


	} 


	C_ORDER_LIST.push_back({ ORDERNUMBER, EMPTYITEMLIST, ORDERSTATUS });

	std::cout << "ORDER ADDED. ORDER#: " << ORDERNUMBER << "\n\n";

	return 0;
}


void Communications::addITEMtoORDER(int ORDERNUMBER, double ITEMCODE, double ITEMNAME, int LOCATIONCODE,  double ITEMWEIGHT, bool ITEMPRIORITY )
{
	double ITEMNUMBER;
	
	

	


	ITEMNUMBER = C_ORDER_LIST[ORDERNUMBER-1].ITEMLIST.size() + 1;                  //Checks Order size to assign item number
	STATUSTEMPLATE ITEMSTATUS{ NOT_STARTED };
	

	C_ORDER_LIST[ORDERNUMBER-1].ITEMLIST.push_back({ITEMNUMBER, ITEMCODE, ITEMNAME, LOCATIONCODE, ITEMWEIGHT, ITEMSTATUS, ITEMPRIORITY  });     //Assigns inputs to Item

	std::cout << "ITEM# " << ITEMNUMBER <<" ADDED TO ORDER# " << ORDERNUMBER << "\n\n";



}



void Communications::viewITEMinORDER(int ORDERNUMBER, double ITEMNUMBER)      //Prints out singular ITEM details
{

	if ((ORDERNUMBER - 1 < C_ORDER_LIST.size()) && (ITEMNUMBER - 1 < C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST.size()))    //Conditions for vector indexing to complete
	{
		printITEM(ORDERNUMBER, ITEMNUMBER);
	}

	 
}

void Communications::viewITEMinORDER(int ORDERNUMBER)					// Function overload that Prints out all items in order when only ordernumber specified
{

	for (double i = 1; i < C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST.size()+1; i++) {

		printITEM(ORDERNUMBER, i);

	}


	


}

	
void Communications::viewORDER(int ORDERNUMBER)
{

	printORDER(ORDERNUMBER);


}


void Communications::viewORDER()
{

	for (double i = 1; i < C_ORDER_LIST.size() + 1; i++) {

		printORDER(i);

	}


}

void Communications::printITEM(int ORDERNUMBER, double ITEMNUMBER)
{

	std::cout << "ITEM DETAILS FOR ORDER#: " << ORDERNUMBER << ", ";
	std::cout << "ITEM NUMBER: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMNUMBER << '\n';
	std::cout << "ITEM CODE: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER- 1].ITEMCODE << ", ";
	std::cout << "ITEM NAME: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMNAME << ", ";
	std::cout << "LOCATION CODE: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].LOCATIONCODE << ", ";
	std::cout << "ITEM WEIGHT: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMWEIGHT << ", ";
	std::cout << "ITEM PRIORITY: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMPRIORITY << ", ";
	std::cout << "ITEM STATUS: " << STATUSTEMPLATE_MAP[C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMSTATUS] << "\n\n";


}



void Communications::printORDER(int ORDERNUMBER)
{

	std::cout << "ORDER DETAILS FOR ORDER#: " << ORDERNUMBER << '\n';
	std::cout << "ORDER SIZE: " << C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST.size() << " ITEMS, ";
	std::cout << "ORDER STATUS: " << STATUSTEMPLATE_MAP[STATUSTEMPLATE(C_ORDER_LIST[ORDERNUMBER - 1].ORDERSTATUS)] << "\n\n";

	
}

void Communications::refreshORDER_STATUS(int ORDERNUMBER) {

	std::vector<C_ITEM>* x = &C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST;
	int FINISHEDITEMS{ 0 };
	int INPROGRESSITEMS{ 0 };
	int NOTSTARTEDITEMS{ 0 };



	for (double i = 1; i < x->size() + 1; i++) {

		switch (x->at(i - 1).ITEMSTATUS)
		{
		case FINISHED:

			FINISHEDITEMS++;

			break;

		case IN_PROGRESS:

			INPROGRESSITEMS++;

			break;

		case NOT_STARTED:

			NOTSTARTEDITEMS++;

			break;

		}

	}

		if ((FINISHEDITEMS > 0) && (INPROGRESSITEMS == 0) && (NOTSTARTEDITEMS == 0)) {

			C_ORDER_LIST[ORDERNUMBER - 1].ORDERSTATUS = FINISHED;

		}

		else if ((FINISHEDITEMS == 0) && (INPROGRESSITEMS == 0) && (NOTSTARTEDITEMS > 0)) {

			C_ORDER_LIST[ORDERNUMBER - 1].ORDERSTATUS = NOT_STARTED;

		}

		else if ((FINISHEDITEMS >= 0) && (INPROGRESSITEMS >= 0) && (NOTSTARTEDITEMS >= 0)) {

			C_ORDER_LIST[ORDERNUMBER - 1].ORDERSTATUS = IN_PROGRESS;

		}

		


	
}

void Communications::changeITEM_STATUS(int ORDERNUMBER, double ITEMNUMBER, int ITEM_STATUS) {


	switch (ITEM_STATUS) {

	case 0:

		C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER-1].ITEMSTATUS = NOT_STARTED;

		break;

	case 1:

		C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMSTATUS = IN_PROGRESS;

		break;

	case 2:

		C_ORDER_LIST[ORDERNUMBER - 1].ITEMLIST[ITEMNUMBER - 1].ITEMSTATUS = FINISHED;

		break;

	}

	refreshORDER_STATUS(ORDERNUMBER);


}





Communications::C_ORDER Communications::getACTIVEORDER() {

	for (double i = 1; i < C_ORDER_LIST.size() + 1; i++) {

		if ((C_ORDER_LIST[i - 1].ORDERSTATUS == NOT_STARTED) || (C_ORDER_LIST[i - 1].ORDERSTATUS == IN_PROGRESS)) {

			return C_ORDER_LIST[i - 1];

		}

	}


}


Communications::C_ITEM Communications::getACTIVEITEM() {

	std::vector<Communications::C_ITEM> ActiveOrder{ getACTIVEORDER().ITEMLIST };


	
	for (double i = 1; i < ActiveOrder.size() + 1; i++) {

		if ((ActiveOrder[i-1].ITEMSTATUS == NOT_STARTED) || (ActiveOrder[i - 1].ITEMSTATUS == IN_PROGRESS)) {

			return ActiveOrder[i-1];

		}

	}

}

Communications::COORDS Communications::getLOCATIONCODECOORDS(int LocationCode) {

	COORDS temp;


	if (LocationCode== 0)
	{
		temp.X = 0;
		temp.Y = 0;
		temp.Theta = 0;

		return temp;
	}



	for (int i = 0; i < COORDS_OFFSET_TABLE.size(); i++) {

		if (COORDS_OFFSET_TABLE[i].LOCATIONCODE == LocationCode){

			temp.X = COORDS_OFFSET_TABLE[i].COORDSCURRENT.X;
			temp.Y = COORDS_OFFSET_TABLE[i].COORDSCURRENT.Y;
			temp.Theta= COORDS_OFFSET_TABLE[i].COORDSCURRENT.Theta;

			return temp;
			}

	}



}

void Communications::InitialiseAttributesfromCSV()
{

	std::vector<double> Temp{ Sub_readAttributesfromCSV(Initialisation_AttributeNameList, Initialisation_Attribute_CSVAddress) };

	C_NETCONNECTION_FLAG = (int)Temp[0];
	

}

void Communications::readUnexpected_Object_Report_fromCSV() {

	



}

void Communications::readNew_Order_Data_fromCSV() {

	std::vector<std::vector <double>> Temp{ Col_readAttributesfromCSV(RobotNewOrderData_AttributeNameList, RobotNewOrderData_CSVAddress) };

	std::vector<double> ItemList;
	ItemList.resize(10);
	
	for (int i = 0; i < Temp[i].size(); i++) {
		
		addORDER(Temp[0][i]);


		for (int y = 0; y < Temp.size(); y++) {

			
			ItemList[y] = Temp[y][i];


		}

		addITEMtoORDER(ItemList[0], ItemList[2],ItemList[3],ItemList[5], ItemList[4], ItemList[1]);

		
		C_COORD_OFFSET TEMP;
		
		TEMP.LOCATIONCODE = ItemList[5];
		TEMP.COORDSCURRENT.X = ItemList[6];
		TEMP.COORDSCURRENT.Y = ItemList[7];
		TEMP.COORDSCURRENT.Theta = ItemList[9];

		COORDS_OFFSET_TABLE.push_back(TEMP);


				

		

				

		



	}



}


void Communications::writeRobot_Telemetry_toCSV()
{

	
}

void Communications::writeRobot_Order_Complete_toCSV() {





}


