// Author: HAMNA KHALID
// Date: June 18, 2025

// CornerGrocer.cpp
// CS 210 Project Three: Corner Grocer Item Tracker

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

// Class to manage grocery item tracking
class GroceryTracker {
private:
    // Map to store item names and their purchase frequencies
    map<string, int> itemFrequency;

public:
    // Constructor: Loads items from file and saves frequencies to backup file
    GroceryTracker() {
        LoadItems("CS210_Project_Three_Input_File.txt");
        SaveToFile("frequency.dat");
    }

    // Loads item names from a file and counts frequency of each item
    void LoadItems(const string& filename) {
        ifstream inFile(filename);
        string item;

        if (!inFile) {
            cerr << "Error: Cannot open input file." << endl;
            exit(1);
        }

        // Read each word (item) and increment its count in the map
        while (inFile >> item) {
            ++itemFrequency[item];
        }
        inFile.close();
    }

    // Saves item frequency data to a backup file
    void SaveToFile(const string& filename) {
        ofstream outFile(filename);

        // Write each item and its frequency to the file
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

    // Returns the frequency of a specific item
    int GetItemFrequency(const string& itemName) {
        return itemFrequency[itemName]; // If item doesn't exist, returns 0
    }

    // Prints all items with their purchase frequency
    void PrintAllItems() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Prints a histogram (item name followed by asterisks representing frequency)
    void PrintHistogram() {
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << " "; // Align item names
            for (int i = 0; i < pair.second; ++i) {
                cout << "*"; // Print one asterisk per item frequency
            }
            cout << endl;
        }
    }
};

// Displays the menu to the user
void DisplayMenu() {
    cout << "\n======= Corner Grocer Menu =======" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display item frequency histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {
    GroceryTracker tracker; // Create an instance of the GroceryTracker class
    int choice;
    string item;

    // Menu loop: runs until the user chooses to exit
    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            // Option 1: Ask user for an item name and show its frequency
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " was purchased " << tracker.GetItemFrequency(item) << " time(s)." << endl;
            break;

        case 2:
            // Option 2: Print all item frequencies
            tracker.PrintAllItems();
            break;

        case 3:
            // Option 3: Print a histogram of item frequencies
            tracker.PrintHistogram();
            break;

        case 4:
            // Option 4: Exit the program
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            // Handle invalid menu input
            cout << "Invalid option. Please enter 1-4." << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
