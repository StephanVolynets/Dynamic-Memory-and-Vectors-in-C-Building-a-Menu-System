//
//  Menu.hpp
//  assignment5
//
//  Created by Stephan Volynets on 9/30/25.
//

#pragma once
#include <vector>

class MenuCommand; // forward declaration, avoiding cyclical include

class Menu {
    /** Menu Class - UI Invoker
     * @file Menu.h
     * Specification for a menu that owns and manages multiple MenuCommand items.
     *
     * ## Overview
     * Menu is a container for MenuCommand choices. It holds dynamically allocated
     * commands (as raw pointers) in a std::vector and provides operations to
     * add new commands, display the menu, and validate user input.
     *
     * ## Public Interface
     * - void addMenuCommand(MenuCommand* cmd) — takes ownership of a command and stores it.
     * - void displayMenu() — iterates over commands and prints them (via MenuCommand::display()).
     * - bool promptUser(char& choice) — reads a char from input, verifies it matches a commandChar, and returns success/failure.
     * - ~Menu() — destructor; frees all dynamically allocated commands.
     *
     * ## Responsibilities
     * - Own a collection of MenuCommand objects (via raw pointers).
     * - Ensure memory is cleaned up by deleting owned commands in the destructor.
     * - Provide user interaction helpers (displaying the menu and validating choices).
     *
     * ## State
     * - std::vector<MenuCommand*> commands — collection of owned commands.
     *
     * ## Ownership & Lifetime
     * - Menu assumes full ownership of all MenuCommand* added with addMenuCommand().
     * - On destruction, Menu will delete each stored pointer to prevent memory leaks.
     * - Copying is unsafe with raw pointers, so copy constructor/assignment should be disabled (Rule of Three).
     *
     * ## Polymorphism & Future Work
     * - For now: stores raw MenuCommand pointers.
     * - Future: replace with smart pointers (std::unique_ptr<MenuCommand>) for automatic memory management.
     * - Supports polymorphism if derived classes extend MenuCommand and override virtual methods.
     *
     * ## Invariants & Expectations
     * - commands vector should contain only valid, heap-allocated MenuCommand pointers.
     * - Each MenuCommand’s commandChar should be unique within the Menu.
     */
    public:
        ~Menu();
    
        void addMenuCommand(MenuCommand *);
        void displayMenu();
        bool promptUser(char &);
        
    private:
        std::vector<MenuCommand*> commands;
};
