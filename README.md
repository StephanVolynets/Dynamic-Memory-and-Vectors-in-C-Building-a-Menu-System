## 📖 Overview
This assignment implements a **dynamic menu system** in C++. The program models a main menu that allows the user to:
1. Connect to a train controller (via `TrainSDK`)
2. Disconnect from the controller
3. List available engines
4. Quit the program

It demonstrates **object-oriented programming, dynamic memory management, and STL containers** by using a `Menu` class that owns multiple `MenuCommand` objects.

---

## 🎯 Learning Objectives
- Understand **classes** and how to define both data (state) and behavior (methods).
- Work with **vectors** (`std::vector`) to store multiple objects.
- Use **dynamic allocation** (`new` / `delete`) and implement a destructor to avoid memory leaks.
- Practice the concept of **ownership** (the `Menu` owns all its `MenuCommand` pointers).
- Reinforce the **difference between headers and source files** in a multi-file C++ project.
- Begin thinking about **polymorphism** and why future versions may use smart pointers (`std::unique_ptr`) instead of raw pointers.

---

## 🗂 File Structure
- `main.cpp` — Drives the program, sets up the menu, and maps user choices to actions via `takeAction()`.
- `Menu.h` / `Menu.cpp` — Defines and implements the `Menu` class, which stores and manages `MenuCommand` objects.
- `MenuCommand.h` — Defines the `MenuCommand` class (header-only).
- `TrainSDK.h` / `TrainSDK.cpp` — Provided SDK simulating a train controller; supports connecting, disconnecting, and listing engines.

---

## ⚙️ How It Works
- At program start, `main.cpp` creates a single `Menu` object.
- Four `MenuCommand` objects are dynamically allocated and added to the `Menu`:
  - `'1'` — Connect to controller
  - `'2'` — Disconnect from controller
  - `'3'` — List Engines
  - `'q'` — Quit
- The menu is displayed by iterating through the vector of commands and calling `display()` on each one.
- The user enters a character; `Menu::promptUser()` validates it by checking against each stored command.
- If valid, `takeAction()` executes the appropriate behavior by calling into `TrainSDK`.
- When the program ends, `Menu::~Menu()` deletes all dynamically allocated commands
