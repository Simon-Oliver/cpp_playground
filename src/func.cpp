#include <iostream>
#include "func.h"
#include <string>
#include <vector>
#include <fstream>

void menu(std::vector<std::string> options)
{
    std::cout << "--------------- MENU ---------------" << std::endl;
    for (size_t i = 0; i < options.size(); i++)
    {
        std::cout << "\t[" << std::to_string(i + 1) << "]"
                  << " " + options[i] << std::endl;
    };
    std::cout << "------------------------------------" << std::endl;
};

int getInput(std::string message, int maxOption)
{
    int input = 0;
    bool hasInput = false;
    while (!hasInput)
    {
        std::cout << message;
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cout << "Input must be an integer between 1 and " + std::to_string(maxOption) + "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (input > maxOption | input < 1)
        {
            std::cout << "Menu options must be between 1 and " + std::to_string(maxOption) + "." << std::endl;
        }
        else
        {
            hasInput = true;
        }
    }
    return input;
};

void createItem(std::string itemName, float price, std::string description)
{
    std::ofstream itemFile("./items.txt", std::ofstream::app);
    if (itemFile)
    {
        itemFile << itemName << "," << price << "," << description << std::endl;
    }

    itemFile.close();
    std::cout << itemName << " " << price << " " << description << std::endl;
};

void addItems()
{
    bool addingItems = true;
    while (addingItems)
    {
        std::string name;
        std::string price;
        std::string desc;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter item name: ";

        std::getline(std::cin, name);
        std::cout << "Enter price: ";

        std::getline(std::cin, price);
        std::cout << "Enter description: ";

        std::getline(std::cin, desc);

        createItem(name, std::stof(price), desc);
        std::string input;
        std::cout << "Add another item? (y/n): ";
        std::cin >> input;

        if (input == "n")
        {
            addingItems = false;
            break;
        };
    };
};

std::vector<std::string> split(std::string str, std::string deli = " ")
{
    std::vector<std::string> tokens;
    int start = 0;
    int end = str.find(deli);
    while (end != -1)
    {
        tokens.push_back(str.substr(start, end - start));
        // std::cout << str.substr(start, end - start) << std::endl;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    tokens.push_back(str.substr(start, end - start));
    // std::cout << str.substr(start, end - start) << std::endl;
    return tokens;
}

std::vector<std::vector<std::string>> readItemsFile()
{
    std::string deli = ",";
    std::ifstream itemFile("./items.txt");
    std::string line;
    std::vector<std::vector<std::string>> items;

    if (!itemFile)
    {
        std::cout << "No items file found. Please create and item first." << std::endl;
    }
    std::cout << "--------- Test File Output ------------" << std::endl;
    while (std::getline(itemFile, line))
    {
        items.push_back(split(line, ","));
    };
    return items;
};

void getItems()
{
    std::vector<std::vector<std::string>> items = readItemsFile();
    std::cout << "Printing the vector -----" << std::endl;
    for (size_t i = 0; i < items.size(); i++)
    {

        std::cout << "ID: " << i << std::endl;
        std::cout << "Name: " << items[i][0] << std::endl;
        std::cout << "-------------------" << std::endl;
    }
};

void deleteItem(int id)
{
    std::vector<std::vector<std::string>> items = readItemsFile();
    items.erase(items.begin() + id);
    std::cout << "+++++++ Items left +++++++" << std::endl;

    std::ofstream itemFile("./items.txt");
    if (itemFile)
    {
        for (size_t i = 0; i < items.size(); i++)
        {
            itemFile << items[i][0] << "," << items[i][1] << "," << items[i][2] << std::endl;
        }

        itemFile.close();
    }
}

std::vector<std::string> getItem(int id)
{
    std::vector<std::string> item;
    std::vector<std::vector<std::string>> items = readItemsFile();
    return item = items[id];
}