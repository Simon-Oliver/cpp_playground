#pragma once
#include <string>
#include <vector>

void menu(std::vector<std::string> options);
int getInput(std::string message, int maxOption);
void createItem(std::string itemName, float price, std::string description);
void getItems();