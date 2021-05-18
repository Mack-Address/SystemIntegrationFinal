#include "Navigation.hpp"

Navigation::Navigation(const int SYS_ID, int SYS_OP)
	:Subsystem{ SYS_ID, SYS_OP }
{
}

double Navigation::getX_CURRENT() {

	return N_X_CURRENT;
}

double Navigation::getY_CURRENT() {

	return N_Y_CURRENT;


}

double Navigation::getTHETA_CURRENT() {


	return N_THETA_CURRENT;

}


void Navigation::InitialiseAttributesfromCSV()
{

	std::vector<double> Temp{ Sub_readAttributesfromCSV(AttributeNameList, AttributeCSVAddress) };

	N_X_CURRENT = (double)Temp[0];
	N_Y_CURRENT = (double)Temp[1];
	N_THETA_CURRENT = (double)Temp[2];

}

void Navigation::writeAttributestoCSV()
{

	std::vector<double> Temp;


	Temp.push_back((double)N_X_CURRENT);
	Temp.push_back((double)N_Y_CURRENT);
	Temp.push_back((double)N_THETA_CURRENT);


	Sub_writeAttributestoCSV(AttributeNameList, AttributeCSVAddress, Temp);

}


std::vector<Subsystem::COORDS> Navigation::getRoutetoLocation(COORDS COORDS) {

	
	std::string statusmessage;

	statusmessage = "Retrieving Route... Current Coordinates are X:  " + std::to_string(N_X_CURRENT) + " Y: " + std::to_string(N_Y_CURRENT) + " THETA: " + std::to_string(N_THETA_CURRENT);

	writetoConsoleCSV(statusmessage, testing::fake_clock::now());

	N_X_CURRENT = COORDS.X;
	N_Y_CURRENT = COORDS.Y;
	N_THETA_CURRENT = COORDS.Theta;
	
	writeAttributestoCSV();

	std::vector<Subsystem::COORDS> TEMPCOORDS;
	TEMPCOORDS.resize(50, COORDS);

	return TEMPCOORDS;
}
