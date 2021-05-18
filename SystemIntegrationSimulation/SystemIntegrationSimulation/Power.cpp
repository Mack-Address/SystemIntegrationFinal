#include "Power.hpp"


Power::Power(const int SYS_ID, int SYS_OP)
	:Subsystem{ SYS_ID, SYS_OP }
{
}


int Power::getBATT_COOLDOWN_TIME() {

	return BATT_COOLDOWN_TIME;

}

int Power::getBATT_SOC_FLAG() {           

	REFRESH_BATT_STATUS(&P_BATT_TEMP,&P_BATT_SOC, &P_BATT_HEALTH);
	return SOC_FLAG;

};

int Power::getBATT_HEALTH_FLAG() {

	REFRESH_BATT_STATUS(&P_BATT_TEMP, &P_BATT_SOC, &P_BATT_HEALTH);

	return HEALTH_FLAG;

};

int Power::getBATT_TEMP_FLAG() {

	REFRESH_BATT_STATUS(&P_BATT_TEMP, &P_BATT_SOC, &P_BATT_HEALTH);
	return TEMP_FLAG;

};


void Power::REFRESH_BATT_STATUS(double* BATT_TEMP, double* BATT_SOC, double* BATT_HEALTH) {


	if (P_BATT_SOC < 20) {

		SOC_FLAG = 0;
	}
	else if (P_BATT_SOC >= 20 && P_BATT_SOC < 40) {

		SOC_FLAG = 1;
	}
	else if (P_BATT_SOC >= 40 && P_BATT_SOC < 60) {

		SOC_FLAG = 2;
	}
	else if (P_BATT_SOC >= 60 && P_BATT_SOC < 80) {

		SOC_FLAG = 3;
	}
	else if (P_BATT_SOC >= 80 && P_BATT_SOC <= 100) {

		SOC_FLAG = 4;
	}

	if (P_BATT_HEALTH < 80) {

		HEALTH_FLAG = 0;
	}
	else
	{
		HEALTH_FLAG = 1;
	}

	if (P_BATT_TEMP >= 40) {

		TEMP_FLAG = 0;
	}
	else if (P_BATT_TEMP < 40)
	{

		TEMP_FLAG = 1;
	}
}


void Power::InitialiseAttributesfromCSV()
{

	std::vector<double> Temp{ Sub_readAttributesfromCSV(AttributeNameList, AttributeCSVAddress) };

	P_BATT_SOC = (double)Temp[0];
	P_BATT_HEALTH = (double)Temp[1];
	P_BATT_TEMP = (double)Temp[2];

}

void Power::writeAttributestoCSV()
{

	std::vector<double> Temp;

	
	Temp.push_back((double)P_BATT_SOC);
	Temp.push_back((double)P_BATT_HEALTH);
	Temp.push_back((double)P_BATT_TEMP);


	Sub_writeAttributestoCSV(AttributeNameList, AttributeCSVAddress, Temp);



}

void Power::ChargingRoutine() {

	int chargetime;
	chargetime = (100 - P_BATT_SOC);
	

	writetoConsoleCSV("Charging to 100% SOC", testing::fake_clock::now());
		P_BATT_SOC = 100;
		testing::fake_clock::advance(std::chrono::minutes(chargetime));
		writetoConsoleCSV("Charged to 100% SOC", testing::fake_clock::now());
		writeAttributestoCSV();
}


void Power::BatteryCooldownRoutine() {


	writetoConsoleCSV("Battery Temperature High, waiting to cool down", testing::fake_clock::now());
	testing::fake_clock::advance(std::chrono::minutes(getBATT_COOLDOWN_TIME()));
	P_BATT_TEMP = (double)35;
	writetoConsoleCSV("Battery Temperature Returned to Normal", testing::fake_clock::now());
	writeAttributestoCSV();
}