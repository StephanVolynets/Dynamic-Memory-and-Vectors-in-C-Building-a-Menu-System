//
//  main.cpp
//  assignment5
//
//  Created by Stephan Volynets on 9/30/25.
//

#include <iostream>
#include "Menu.hpp"
#include "MenuCommand.h" // accidentally used C style header extension
#include "TrainSDK.h" // accidentally used C style header extension


// Enumeration of menu choices
enum {
    kConnectToController = '1',
    kDisconnectFromController ='2',
    kListEngines = '3',
    kQuit = 'q'
};

/** Main()
 *
 *  • We can now "store" multiple "Commands" in the Menu instance
 *      at compile time we can specify what the cmd(char) + display name are for each MenuCommand.
 *
 *  • new creates new object instance on heap
 *      thus, we must delete with destructor ~Menu when we are done
 *
 *  • Implement takeAction(): Responsible for executing the step with char(cmd)
 *
 *  • Only ONE Menu object is created: Menu theMenu;
 *
 *  • FOUR MenuCommand objects are created immediately (right where you call new MenuCommand(...) in main), not
 *     later when the user types something.
 *
 *  • The menu prints its options by looping over the stored commands and calling each command’s display() method,
 *     which prints lines like 1) Connect to Controller.
 *
 **/

// CONDUCTOR - Translates choice into calls to TrainSDK
void takeAction(char choice, TrainSDK& sdk) {
    switch(choice) {
        case kConnectToController: {
            std::string ip;
            std::cout << "Enter IP Address to connect to: ";
            std::cin >> ip;
            
            CmdError err = sdk.connect(ip);
            if (err == kCmdNoError) {
                std::cout << "Connected to " << ip << std::endl;
            } else {
                std::cout << "Error connecting: " << err << std::endl;
            }
            break;
        }
        case kDisconnectFromController: {
            CmdError err = sdk.disconnect();
            if (err == kCmdNoError) {
                std::cout << "Disconnected." << std::endl;
            } else {
                std::cout << "Error disconnecting: " << err << std::endl;
            }
            break;
            }
            case kListEngines: {
            if (!sdk.isConnected()) {
                std::cout << "Error, not connected" << std::endl;
            } else {
                std::vector<Engine> engines;
                sdk.getEngines(engines);
                std::cout << "ENGINES:\n";
                for (const auto& e : engines) {
                    std::cout << "# " << e.engineID << "   " << e.engineName << "(" << e.engineNumber << ")\n";
                }
            }
            break;
            }
            case kQuit:
                std::cout << "All done!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice." << std::endl;
                break;
            }
        }

int main(int argc, const char * argv[]) {
    Menu theMenu;
    TrainSDK sdk; // single instance for the whole program/session
    bool keepGoing = true;
    char choice;
    
    // Add the menu items
    theMenu.addMenuCommand(new MenuCommand(kConnectToController,"Connect to Controller"));
    theMenu.addMenuCommand(new MenuCommand(kDisconnectFromController,"Disconnect from controller"));
    theMenu.addMenuCommand(new MenuCommand(kListEngines,"List Engines"));
    theMenu.addMenuCommand(new MenuCommand(kQuit,"Quit"));
    
    // Main loop
    while (keepGoing) {
        std::cout << "\nMAIN MENU\n---------------------\n";
        theMenu.displayMenu();
        
        if (theMenu.promptUser(choice)) {
            takeAction(choice, sdk);
            if (choice == kQuit) {
                keepGoing = false;
            }
        } else {
            std::cout << "Invalid choice entered.\n";
        }
    }
    
    return 0;
}
