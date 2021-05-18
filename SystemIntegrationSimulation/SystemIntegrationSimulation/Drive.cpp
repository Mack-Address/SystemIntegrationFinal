#include "Drive.hpp"


Drive::Drive(const int SYS_ID, int SYS_OP)     //Class Constructor
:Subsystem{SYS_ID , SYS_OP}
{
}



void Drive::InitialiseAttributesfromCSV()
{

	std::vector<double> Temp{ Sub_readAttributesfromCSV(AttributeNameList, AttributeCSVAddress) };

	DriveStatus = (DriveStatusTemplate)Temp[0];

}


void Drive::writeAttributestoCSV()
{
	
	std::vector<double> Temp;
	
	Temp.push_back((double)DriveStatus);
	

	Sub_writeAttributestoCSV(AttributeNameList, AttributeCSVAddress, Temp);



}

void Drive::setDriveStatus(DriveStatusTemplate New_DriveStatus) {


	DriveStatus = New_DriveStatus;

}

int Drive::Drive_To_Location(std::vector<COORDS> LocationCoords) {


	std::string message;
	
	COORDS Destination = LocationCoords.back();
	int Drivetime = LocationCoords.size();

	message = "Driving to X: " + std::to_string(Destination.X) + " Y: " + std::to_string(Destination.Y) + " THETA: " + std::to_string(Destination.Theta);
	
	writetoConsoleCSV(message, testing::fake_clock::now());
	testing::fake_clock::advance(std::chrono::seconds(Drivetime));
	DriveStatus = DriveStatusTemplate::MOBILE;
		writeAttributestoCSV();
	writetoConsoleCSV("Robot has Arrived at Destination ", testing::fake_clock::now());
	DriveStatus = DriveStatusTemplate::STATIONARY;

		writeAttributestoCSV();

		return 1;

}