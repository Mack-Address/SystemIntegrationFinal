#include "Subsystem.hpp"


Subsystem::Subsystem(const int SYS_ID, int SYS_OP)     //Class Constructor
	:S_SYS_ID{ SYS_ID }, S_SYS_OP{ SYS_OP }
{
}

int Subsystem::getSYS_OP() {                          //Member Functions

	return S_SYS_OP;

}

const int Subsystem::getSYS_ID() {

	return S_SYS_ID;

}

void Subsystem::setSYS_OP(int NEW_SYS_OP) {

	S_SYS_OP = NEW_SYS_OP;
}

std::string Subsystem::getSYSTEM_TIME() {



	std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string output = std::ctime(&time);

	return output;
}

int Subsystem::writetoConsoleCSV(std::string Status_Message, testing::fake_clock::time_point SystemTime) {

	std::string Subsystem_Name;
	


	switch (S_SYS_ID)
	{
	case 0:

		Subsystem_Name = "Power";

		break;

	case 1:

		Subsystem_Name = "Lifting";

		break;

	case 2:

		Subsystem_Name = "Drive";

		break;

	case 3:

		Subsystem_Name = "Communications";

		break;

	case 4:

		Subsystem_Name = "Navigation";

		break;

	case 5:

		Subsystem_Name = "Picking";

		break;

	}


	time_t Time = testing::fake_clock::to_time_t(SystemTime);

	std::string TimeStringFull = std::ctime(&Time);
	std::string TimeStringAltered = TimeStringFull.substr(11, 8);



	std::cout << "SYSTEM_TIME: " << TimeStringAltered << " SYSTEM_NAME: " << Subsystem_Name << '\n';
	std::cout << "STATUS: " << Status_Message << "\n\n";

	
	return 1;

}

std::vector<double> Subsystem::Sub_readAttributesfromCSV(std::vector<std::string> AttributeList, std::string FileAddress) {

	rapidcsv::Document doc(FileAddress, rapidcsv::LabelParams(0, 0));
	

	std::vector<double> AttributeValues;

	for (int i = 0; i < AttributeList.size(); i++) {

		AttributeValues.push_back(doc.GetCell<double>(AttributeList[i], "VAL"));


	}

	return AttributeValues;



}


std::vector<std::vector<double>> Subsystem::Col_readAttributesfromCSV(std::vector<std::string> AttributeList, std::string FileAddress) {

		rapidcsv::Document doc(FileAddress, rapidcsv::LabelParams(0, 0));


		std::vector<std::vector<double>> AttributeValues;

		for (int i = 0; i < AttributeList.size(); i++) {

			AttributeValues.push_back(doc.GetColumn<double>(AttributeList[i]));


		}

		return AttributeValues;


}

void Subsystem::Sub_writeAttributestoCSV(std::vector<std::string> AttributeList, std::string FileAddress, std::vector<double> AttributeValues) {


	rapidcsv::Document doc(FileAddress, rapidcsv::LabelParams(0, 0));
	

	for (int i = 0; i < AttributeList.size(); i++) {

		doc.SetCell<double>(AttributeList[i], "VAL", AttributeValues[i]);

	}
	
	doc.Save(FileAddress);

}