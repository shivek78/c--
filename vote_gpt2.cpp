#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setw()
#include <cstdlib> // For exit()

using namespace std;

// Candidate class definition
class Candidate {
public:
    string name;
    string party;
    string symbol;
    int votes = 0;

    // Constructor to initialize Candidate object
    Candidate(const string& n, const string& p, const string& s) : name(n), party(p), symbol(s) {}
};

// Function to center-align text
void centerText(const string& text, int width) {
    int spaces = (width - text.length()) / 2;
    cout << setw(spaces + text.length()) << right << text << setw(width - spaces - text.length()) << right << "" << endl;
}

// ElectionSystem class definition
class ElectionSystem {
private:
    vector<Candidate> candidates;
    string adminPassword = "shivek";
    bool loggedIn = false;

public:
    // Method to add a candidate
    void addCandidate(const string& name, const string& party, const string& symbol) {
        candidates.emplace_back(name, party, symbol);
    }

    // Method to remove a candidate (admin only)
    void removeCandidate() {
        if (!loggedIn) {
            cout << "Access denied. Please login as admin.\n";
            return;
        }

        displayCandidates();
        int choice;
        cout << "Enter the candidate number to remove (1-" << candidates.size() << "), or 0 to cancel: ";
        cin >> choice;

        if (choice >= 1 && choice <= candidates.size()) {
            cout << "Removing candidate: " << candidates[choice - 1].name << " (" << candidates[choice - 1].party << ")\n";
            candidates.erase(candidates.begin() + choice - 1);
        } else {
            cout << "Invalid choice or cancellation. Returning to main menu.\n";
        }
    }

    // Method to display all candidates in table format
    void displayCandidates() {
        cout << "\n";
        centerText("List of Candidates", 100);
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        cout << "| No. |     Candidate Name      |                  Party                 |     Symbol     |\n";
        cout << "|------------------------------------------------------------------------------------------------------------|\n";
        for (size_t i = 0; i < candidates.size(); ++i) {
            cout << "| " << setw(3) << i + 1 << " | " << setw(25) << candidates[i].name << " | " << setw(35) << candidates[i].party << " | " << setw(15) << candidates[i].symbol << " |\n";
        }
        cout << "|------------------------------------------------------------------------------------------------------------|\n";
    }

    // Method for voters to cast their vote
    void vote() {
        cout << "Welcome! Please cast your vote:\n";
        cout << "<------------------------------------------------------------------------------------------>\n";
        displayCandidates();

        int choice;
        cout << "Enter the candidate number (1-" << candidates.size() << "), or 0 to exit: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting the program. Thank you!\n";
            exit(0);
        } else if (choice >= 1 && choice <= candidates.size()) {
            candidates[choice - 1].votes++;
            cout << "You voted for " << candidates[choice - 1].name << " (" << candidates[choice - 1].party << ") - Symbol: " << candidates[choice - 1].symbol << "\n";
            cout << "Thank you for voting!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    // Method to display election results in table format
    void displayResults() {
        cout << "\n";
        centerText("Election Results", 100);
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        cout << "|           Candidate Name           |                   Party                    |     Symbol     |  Votes  |\n";
        cout << "|------------------------------------------------------------------------------------------------------------|\n";
        for (const auto& candidate : candidates) {
            cout << "| " << setw(35) << candidate.name << " | " << setw(40) << candidate.party << " | " << setw(15) << candidate.symbol << " | " << setw(7) << candidate.votes << " |\n";
        }
        cout << "|------------------------------------------------------------------------------------------------------------|\n";
    }

    // Method to check election status
    void checkElectionStatus() {
        if (candidates.empty()) {
            cout << "\n";
            centerText("The election is not started yet.", 100);
            cout << "\n";
        } else {
            cout << "\n";
            centerText("The election is ongoing.", 100);
            cout << "\n";
        }
    }

    // Method to logout admin
    void logout() {
        loggedIn = false;
        cout << "* Logged out successfully.\n";
    }

    // Method to authenticate admin login
    bool authenticate() {
        string enteredPassword;
        cout << "Enter admin password: ";
        cin >> enteredPassword;

        if (enteredPassword != adminPassword) {
            cout << "* Incorrect password. Access denied.\n";
            return false;
        }
        loggedIn = true;
        return true;
    }

    // Admin menu for managing candidates
    void adminMenu() {
        if (!loggedIn) {
            if (!authenticate()) return;
        }

        while (loggedIn) {
            int choice;
            cout << "\n";
            centerText("Admin Menu", 100);
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            cout << "| 1. Display Candidates       |  2. Remove Candidate         |  3. Display Results          |  4. Check Election Status    |\n";
            cout << "|------------------------------------------------------------------------------------------------------------|\n";
            cout << "| 5. Logout                   |  6. Exit                     |\n";
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    displayCandidates();
                    break;
                case 2:
                    removeCandidate();
                    break;
                case 3:
                    displayResults();
                    break;
                case 4:
                    checkElectionStatus();
                    break;
                case 5:
                    logout();
                    break;
                case 6:
                    cout << "* Exiting the program. Thank you!\n";
                    exit(0);
                default:
                    cout << "* Invalid choice. Please enter a number between 1 and 6.\n";
            }
        }
    }

    // Method to initialize with predefined candidates
    void initializePredefinedCandidates() {
        addCandidate("Narendra Modi", "Bharatiya Janata Party (BJP)", "Lotus");
        addCandidate("Sonia Gandhi (interim)", "Indian National Congress (INC)", "Hand");
        addCandidate("Arvind Kejriwal", "Aam Aadmi Party (AAP)", "Broom");
        addCandidate("Sitaram Yechury", "Communist Party of India ", "Hammer & Sickle");
        addCandidate("Mayawati", "Bahujan Samaj Party (BSP)", "Elephant");
        addCandidate("Sharad Pawar", "Nationalist Congress Party (NCP)", "Clock");
    }
};

// Main function
int main() {
    ElectionSystem election;

    // Initialize with predefined candidates
    election.initializePredefinedCandidates();

    while (true) {
        int choice;
        cout << "\n";
        centerText("Election System Main Menu", 100);
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        cout << "| 1. Vote                   |  2. Login as Admin         |  3. View Results           |  4. Exit                   |\n";
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                election.vote();
                break;
            case 2:
                election.adminMenu();
                break;
            case 3:
                election.displayResults();
                break;
            case 4:
                cout << "* Exiting the program. Thank you!\n";
                exit(0);
            default:
                cout << "* Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}

