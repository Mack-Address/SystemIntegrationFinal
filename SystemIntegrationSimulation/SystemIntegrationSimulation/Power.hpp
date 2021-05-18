#ifndef _POWER_H_
#define _POWER_H_
#include "Subsystem.hpp"

class Power : public Subsystem
{
private:

	const int BATT_COOLDOWN_TIME{ 5 };  //Minutes

	int SOC_FLAG;                  //Accessible to Program flow (FLAGS)
	int HEALTH_FLAG;
	int TEMP_FLAG;
	

	double P_BATT_SOC;				//not used to alter Program flow  (RAW DATA)												
	double P_BATT_HEALTH;
	double P_BATT_TEMP;
	

	std::vector<std::string> AttributeNameList
	{
		{"P_BATT_SOC", "P_BATT_HEALTH", "P_BATT_TEMP"}

	};

	std::string AttributeCSVAddress{ "C:/Users/mackl/source/repos/SystemIntegrationSimulation/SystemIntegrationSimulation/CSV Input Files/Power_Attributes.csv" };

public:

	Power(const int SYS_ID, int SYS_OP);    //Class Constructor

	int getBATT_SOC_FLAG();		// 0= NEEDS CHARGE 1,2 = CHARGE AFTER NEXT ORDER 3,4= NO CHARGE NEEDED													//Functions for Accessing flag Values							
	int getBATT_HEALTH_FLAG(); // 0 = BAD 1 = GOOD
	int getBATT_TEMP_FLAG();	// 0 = >40 1 = <40
	
	
	
	int getBATT_COOLDOWN_TIME();


	void ChargingRoutine(); 
	void BatteryCooldownRoutine();
	
	void InitialiseAttributesfromCSV();
	void writeAttributestoCSV();

protected:

	void REFRESH_BATT_STATUS(double *BATT_TEMP, double *BATT_SOC, double *BATT_HEALTH);   //Computing Flags within the Object

};
  

#endif
