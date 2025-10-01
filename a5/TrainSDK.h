//
// TrainSDK.h
//
// Fictional SDK for controlling a model train
//
// Implementation for Assignment #5
//

#include <string>
#include <vector>

enum CmdError {
	kCmdNoError, 
	kCmdNotConnected,
	kCmdAlreadyConnected,
	kCmdConnectionError,
	kCmdInvalidParameter,
	kCmdInvalidAddress,
	kCmdSendError
} ;


class Engine {
public:
	Engine(int id, std::string name, std::string number) {
		engineName = name;
		engineNumber = number;
		engineID = id;
	}
	
public:
	std::string engineName;
	std::string engineNumber;
	int engineID;
};



class TrainSDK { // Reviever - performs connect and disconnects
public:    // Constructor
	TrainSDK() {
		ipAddr = "";
	}
	
public:    // API Calls
	CmdError connect(std::string ipAddress);
	CmdError disconnect();
	void getEngines(std::vector<Engine> &engines); // Engine type vector
	bool isConnected();
	
private:
	std::string ipAddr;	 	
};
