#include "Subsystem.hpp"
#include "Power.hpp"
#include "Drive.hpp"
#include "Navigation.hpp"
#include "Communications.hpp"
#include "Lifting.hpp"
#include "Picking.hpp"
#include "fake_clock.hh"
#include "SystemIntegrationSimulation.hpp"
#include <iostream>
 






int main()
{


//Scenario 1: Initialisation
	
	
	//Initialise each Class

	Power Subsystem_Power{ 0, 1 };	
	Lifting Subsystem_Lifting{ 1,1 };
	Drive Subsystem_Drive{ 2, 1 };
	Communications Subsystem_Communications{ 3, 1 };
	Navigation Subsystem_Navigation{ 4, 1 };
	Picking Subsystem_Picking{ 5,1 };

	//Define Global Constants

	int const ChargingLocationCode{ 0 };

	//Initialise each Class Attribute with CSV information

	Subsystem_Power.InitialiseAttributesfromCSV();
	Subsystem_Drive.InitialiseAttributesfromCSV();
	Subsystem_Navigation.InitialiseAttributesfromCSV();
	Subsystem_Communications.InitialiseAttributesfromCSV();
	Subsystem_Lifting.InitialiseAttributesfromCSV();
	Subsystem_Picking.InitialiseAttributesfromCSV();

	//Check if Battery needs charging (Function), If not continue

	if (Subsystem_Power.getBATT_HEALTH_FLAG() == 0)  //If health low then wait for battery to be replaced
	{

		Subsystem_Power.writetoConsoleCSV("Battery health low, please manually replace at earliest convenience", testing::fake_clock::now());
		return Subsystem_Power.getSYS_ID();

	}

	if (Subsystem_Power.getBATT_TEMP_FLAG() == 0) //if temp too high then wait until low again
	{
		
		Subsystem_Power.BatteryCooldownRoutine();


	}

	if (Subsystem_Power.getBATT_SOC_FLAG() == 0)
	{
		
		
		Subsystem_Drive.Drive_To_Location(Subsystem_Navigation.getRoutetoLocation(Subsystem_Communications.getLOCATIONCODECOORDS(0))); //to Finalise functions
		
		Subsystem_Power.ChargingRoutine();
		

	}

	//End -> Scenario 1
	
//Scenario 2: Job Interface Fetching

	//verify connection to HUB
	//Read in Jobs  from CSV and assign the active order
	
	while (Subsystem_Communications.getNETCONNECTION_FLAG() == 0)
	{
		Subsystem_Communications.InitialiseAttributesfromCSV();

	}

	Subsystem_Communications.readNew_Order_Data_fromCSV();
	Subsystem_Communications.viewITEMinORDER(1);
	Subsystem_Communications.viewITEMinORDER(2);
	Subsystem_Communications.viewITEMinORDER(3);


	//End -> Scenario 2

//Scenario 3: Travelling to ActiveItem in order
	
	Subsystem_Drive.Drive_To_Location(Subsystem_Navigation.getRoutetoLocation(Subsystem_Communications.getLOCATIONCODECOORDS(Subsystem_Communications.getACTIVEITEM().LOCATIONCODE)));
	



	
	
	
	






	system("pause");



























	//InitialisePicking(ItemCode)
	
	

	
	

	

//Item_Travelling_Routine
	
	//Calculate Route to Current Item (Nav)

	//Drive to Item/Odemetry (Drive)
	
		//IF ObstacleDetected (Nav)
			//Report to Fleet (Comms)
			//GOTO Item_Travelling_Routine (Control)
			
		//Else 
			//Return Confirmation Value & Continue (Control)

//Item_Retrieval_Routine

	//Lift to Shelf (Lifting)
	
	//Identifying Correct Box using Barcode (Picking?)
						
	//Arm Rotates to Box Top/Opening (Lifting)

	//Identify Item in Box (Picking)

	//Reach Down into Box (Picking/Lifting)

	//Grip Item (Picking)

	//Remove Item from Box (Picking)

	//Place in Storage (Picking)

	//Arm Returns to Neutral (Lifting)

	//Return Confirmation Value &Continue (Control)

//Job_Interrupt_Routine (Between Picking of Each item)

	//Switch to Next Item in Job (Control)
	
	//IF AnotherIteminjob
		//GOTO Item_Travelling_Routine (Control)
	//Else 
		//Return Confirmation Value & Continue(Control)

//Job_Finish_Routine

	//Calculate Route to Packing Area (Nav)
	//Drive to Packing Area (Drive)
	//Place Item/Order at end point (Lifting)
	//Return Confirmation Value & Continue (control)

//Job_Transition_Routine

	//Call Charging_Routine
	//Call Job Initialisation_Routine




		


	



}

