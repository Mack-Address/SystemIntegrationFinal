#include "Picking.hpp"

Picking::Picking(const int SYS_ID, int SYS_OP)

	:Subsystem{SYS_ID, SYS_OP}
{
}


std::vector<double> Picking::InitiatePicking(double ITEMCODE, int LOCATIONCODE)
{

	std::vector<double> Offset;



	return Offset;

}


int Picking::getPickingStatus() {

	return PickingStatus;

}

void Picking::InitialiseAttributesfromCSV()
{

	std::vector<double> Temp{ Sub_readAttributesfromCSV(AttributeNameList, AttributeCSVAddress) };

	PickingStatus = (int)Temp[0];


}

