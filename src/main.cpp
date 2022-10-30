#include "func.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int main()
{
    bool isRunning = true;
    // Initiated a vector holding our menu options and rendering the menu
    std::vector<std::string> menuItems;
    std::string line;
    std::ifstream menuFile;

    menuFile.open("./menu.txt");

    if (menuFile.is_open())
    {
        while (std::getline(menuFile, line))
        {
            menuItems.push_back(line);
        };
    }
    else
    {
        std::cout << "Something went wrong!!!" << std::endl;
    };

    menuFile.close();

    menu(menuItems);

    while (isRunning)
    {
        // Get user input and save it as choice
        int choice = getInput("Please choose and option from the menu: ", menuItems.size());
        // Print the choice in the terminal
        if (choice == menuItems.size())
        {
            isRunning = false;
            std::cout << "\nApplication is closing." << std::endl;
        };

        switch (choice)
        {
        case 1:
            addItems();
            break;
        case 4:
            getItems();
        default:
            std::cout << "You choose " + menuItems[choice - 1] << "\r" << std::endl;
            break;
        }
    };
    return 0;
};
