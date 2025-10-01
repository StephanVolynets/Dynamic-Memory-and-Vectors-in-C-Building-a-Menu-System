//
//  Menu.cpp
//  assignment5
//
//  Created by Stephan Volynets on 9/30/25.
//

#include "Menu.hpp"
#include "MenuCommand.h"
#include <iostream>

Menu::~Menu() { // loop through ptr vector, auto asks compiler to determine type by its intializer
    for (auto cmd : commands) // can also use MenuCommand* for type
        delete cmd; // delete
}

void Menu::addMenuCommand(MenuCommand * cmd) { // checks commands against choice inputted
    commands.push_back(cmd); // remember each command given
}

void Menu::displayMenu() {
    for (auto cmd : commands) {
        (*cmd).display(); // access member through pointer syntax (also '->')
    }
}

bool Menu::promptUser(char& choice) {
    std::cout << "Enter Choice: ";
    std::cin >> choice;
    
    for (auto cmd: commands) {
        if ((*cmd).getCommandChar() == choice) {
            return true; //choice matches one of the MenuCommands char's
        }
    }
    return false; //does not match
}
