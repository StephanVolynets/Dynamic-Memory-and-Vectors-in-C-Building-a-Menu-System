//
//  MenuCommand.h
//  assignment5
//
//  Created by Stephan Volynets on 9/30/25.
//

#pragma once // header guard, only compile once
#include <string>
#include <iostream>

class MenuCommand{
    /**
     * @file MenuCommand.h
     * Specification for a single selectable menu item.
     *
     * ## Overview
     * MenuCommand models one choice in a menu: it has a selection key
     * (e.g., '1', '2', 'q') and a human-readable title (e.g., "Connect to controller", "Quit").
     *
     * ## Public Interface
     * - MenuCommand(char cmdChar, std::string argTitle) — construct with a selection key and title.
     * - void display() — print this command’s line as it should appear in the menu.
     * - char getCommandChar() — return the character that selects this command.
     *
     * ## Responsibilities
     * - Render its own label/choice line via display().
     * - Expose its selection key via getCommandChar().
     *
     * ## State
     * - char commandChar — printable character used to select this item; should be unique within its owning menu.
     * - std::string title — non-empty, user-facing label shown in the menu.
     *
     * ## Polymorphism & Usage
     * - Designed to be a base type so derived commands can customize behavior (e.g., specialized display() or additional actions).
     * - Store/pass MenuCommand objects by pointer or reference to avoid object slicing and enable runtime polymorphism.
     * - MenuCommand does not own a collection
     *
     * ## Ownership & Lifetime
     * - In this assignment, a Menu will hold a std::vector of **raw** MenuCommand*.
     *   The Menu class is responsible for deleting those pointers in its destructor to prevent leaks.
     * - Future improvement: replace raw pointers with smart pointers (std::unique_ptr/std::shared_ptr) for safer lifetime management.
     *
     * ## Invariants & Expectations
     * - title should be a valid, user-readable string.
     * - commandChar should be unique within a given Menu and remain stable after construction.
     */
public:
    MenuCommand(char cmdChar, std::string argTitle){
        commandChar = cmdChar; // always initialize members in the order they are declared in class
        title = argTitle;
    }
    
    // const so obj member variables cant be altered
    void display() const {  // Prints out this "command" as a "choice" in the menu it belongs, "x) Title"
        std::cout << commandChar << ") " << title << std::endl;
    }
    char getCommandChar() const {  // Accessor - returns the stored char for Menu to check if input matches
        return commandChar;
    }
    
private:
    char commandChar;
    std::string title; //used to store the "name" of the choice
    
    
}; // end classes with ;
