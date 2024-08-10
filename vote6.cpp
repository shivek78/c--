#include <iostream>
#include <string>
#include <vector> // For candidate storage

// Define a struct to store candidate information
struct Candidate {
    std::string name;
    int votes;
};

// Function to display the admin menu
void displayAdminMenu() {
    std::cout << "Admin Menu:\n";
    std::cout << "1. Show Results\n";
    std::cout << "2. Add Candidate\n";
    std::cout << "3. Exit Admin\n";
}

// Function to handle adding a candidate
void addCandidate(std::vector<Candidate>& candidates) {
    std::string name;
    std::cout << "Enter candidate name: ";
    std::cin >> name;

    // Add the candidate (assuming no duplicate names)
    candidates.push_back({name, 0});
    std::cout << name << " added as a candidate.\n";
}

int main() {
    const std::string adminPassword = "admin123"; // Set your admin password
    std::vector<Candidate> candidates; // Store candidates

    int choice;
    std::string password;
    do {
        std::cout << "Enter password (admin): ";
        std::cin >> password;

        if (password == adminPassword) {
            displayAdminMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    // Show voting results
                    // ...
                    break;
                case 2:
                    addCandidate(candidates);
                    break;
                case 3:
                    std::cout << "Exiting admin menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } else {
            std::cout << "Incorrect password. Access denied.\n";
        }
    } while (choice != 3);

    // Rest of your voting system logic (voting, displaying menu, etc.)

    return 0;
}

