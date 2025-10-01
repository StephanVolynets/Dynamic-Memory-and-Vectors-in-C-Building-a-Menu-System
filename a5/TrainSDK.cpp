//
// TrainSDK.cpp
//
// Fictional SDK for controlling a model train
//
// Implementation for Assignment #5
//

#include "TrainSDK.h"

//
// API call to connect to a model train controller.   Takes an IP address as a string
//
CmdError TrainSDK::connect(std::string ipAddress)
{
	if (ipAddr.length() > 0) 
		return kCmdAlreadyConnected;
		
	ipAddr = ipAddress;
	return kCmdNoError;
}

//
// API call to disconnect from a model train controller.     
//
CmdError TrainSDK::disconnect() 
{
	if (ipAddr.length() == 0)
		return kCmdNotConnected;
		
	ipAddr = "";
	return kCmdNoError;
}


//
// API call that checks to see if we are connected
//
bool TrainSDK::isConnected() 
{
	if (ipAddr.length() > 0)
		return true;
		
	return false;
}


//
// API call to retrieve the engines the SDK knows about
//

void TrainSDK::getEngines(std::vector<Engine> &engines)
{
	engines.push_back(Engine(57,"Lehigh Valley SW1"," 112"));
	engines.push_back(Engine(31,"Hallows Eve Doodlebug", "  31"));
	engines.push_back(Engine(48,"Pennsylvania GG1","4877"));
}
