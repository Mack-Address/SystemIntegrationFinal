#include "Lifting.hpp"

Lifting::Lifting(const int SYS_ID, int SYS_OP)     //Class Constructor

	:Subsystem {SYS_ID , SYS_OP }
{
}



int Lifting::getLift_Level() {


	return L_Lift_Level;



}

double Lifting::getLift_Height() {


	return L_Lift_Height;

}

bool Lifting::getLift_Storage_Actuator() {


	return L_Lift_Storage_Actuator;

}


int Lifting::changeLift_Level(int New_Lift_Level) {


	if (((L_FloortoRacking_Spacing - L_FloortoLiftBase_Spacing) + (New_Lift_Level * L_Level_Spacing)) <= L_Lift_Height_Max) {

		L_Lift_Level = New_Lift_Level;
		changeLift_Height((L_FloortoRacking_Spacing - L_FloortoLiftBase_Spacing) + (New_Lift_Level * L_Level_Spacing));

		return 1;


	}

	else {

		return 0;
	}

}

int Lifting::changeLift_Height(double New_Lift_Height) {


		if (New_Lift_Height <= L_Lift_Height_Max) {
			
			L_Lift_Height = New_Lift_Height;

			return 1;
		}

		else {

			return 0;
		}
		

}

int Lifting::changeLift_Storage_Actuator(bool Storage_Actuator_Bool) {


	L_Lift_Storage_Actuator = Storage_Actuator_Bool;

	return 1;
		

}

void Lifting::InitialiseAttributesfromCSV()
{

	std::vector<double> Temp{ Sub_readAttributesfromCSV(AttributeNameList, AttributeCSVAddress) };

	L_Lift_Level = (double)Temp[0];
	L_Lift_Height = (double)Temp[1];
	L_Lift_Storage_Actuator = (double)Temp[2];
	L_Weight_Of_Item = (double)Temp[2];

}

void Lifting::writeAttributestoCSV()
{

	std::vector<double> Temp;

	Temp.push_back((int)L_Lift_Level);
	Temp.push_back((double)L_Lift_Height);
	Temp.push_back((bool)L_Lift_Storage_Actuator);
	Temp.push_back((int)L_Weight_Of_Item);

	Sub_writeAttributestoCSV(AttributeNameList, AttributeCSVAddress, Temp);
	
}