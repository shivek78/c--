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

    // Method to edit a candidate's details (admin only)
    void editCandidate() {
        if (!loggedIn) {
            cout << "Access denied. Please login as admin.\n";
            return;
        }

        displayCandidates();
        int choice;
        cout << "Enter the candidate number to edit (1-" << candidates.size() << "), or 0 to cancel: ";
        cin >> choice;

        if (choice >= 1 && choice <= candidates.size()) {
            cout << "Editing candidate: " << candidates[choice - 1].name << " (" << candidates[choice - 1].party << ")\n";
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, candidates[choice - 1].name);
            cout << "Enter new party: ";
            getline(cin, candidates[choice - 1].party);
            cout << "Enter new symbol: ";
            getline(cin, candidates[choice - 1].symbol);
            cout << "Candidate details updated successfully.\n";
        } else {
            cout << "Invalid choice or cancellation. Returning to main menu.\n";
        }
    }

    // Method to display all candidates in table format
    void displayCandidates() {
        cout << "\n==============================> List of Candidates <=====================================================\n";
        cout << "----------------------------------------------------------------------------------------------------------\n";
        cout << "| No. |     Candidate Name                          |             Party                        |  Symbol  |\n";
        cout << "----------------------------------------------------------------------------------------------------------\n";
        for (size_t i = 0; i < candidates.size(); ++i) {
            cout << "| " << setw(3) << i + 1 << " | " << setw(40) << left << candidates[i].name.substr(0, 40) << " | "
                 << setw(35) << left << candidates[i].party.substr(0, 35) << " | " << setw(8) << left << candidates[i].symbol.substr(0, 8) << " |\n";
        }
        cout << "----------------------------------------------------------------------------------------------------------\n";
    }

    // Method for voters to cast their vote
    void vote() {
        cout << "\nWelcome! Please cast your vote:\n";
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
        cout << "\n======================= Election Results ==================================\n";
        cout << "-------------------------------------------------------------------------------\n";
        cout << "|        Candidate Name          |          Party                  | Votes     |\n";
        cout << "-------------------------------------------------------------------------------|\n";
        for (const auto& candidate : candidates) {
            cout << "| " << setw(30) << left << candidate.name << " | " << setw(35) << left << candidate.party << " | " << setw(8) << candidate.votes << " |\n";
        }
        cout << "-------------------------------------------------------------------------------\n";
    }

    // Method to check election status
    void checkElectionStatus() {
        if (candidates.empty()) {
            cout << "\n======================= Election Status =======================\n";
            cout << "| The election has not started yet.                             |\n";
            cout << "===============================================================\n";
        } else {
            cout << "\n======================= Election Status =======================\n";
            cout << "| The election is ongoing.                                     |\n";
            cout << "===============================================================\n";
        }
    }

    // Method to logout admin
    void logout() {
        loggedIn = false;
        cout << "Logged out successfully.\n";
    }

    // Method to authenticate admin login
    bool authenticate() {
        string enteredPassword;
        cout << "Enter admin password: ";
        cin >> enteredPassword;

        if (enteredPassword != adminPassword) {
            cout << "Incorrect password. Access denied.\n";
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
            cout << "\n========================= Admin Menu ==========================\n";
            cout << "| 1. Display Candidates                                       |\n";
            cout << "| 2. Add Candidate                                            |\n";
            cout << "| 3. Remove Candidate                                         |\n";
            cout << "| 4. Edit Candidate                                           |\n";
            cout << "| 5. Display Results                                          |\n";
            cout << "| 6. Check Election Status                                    |\n";
            cout << "| 7. Logout                                                   |\n";
            cout << "| 8. Exit                                                     |\n";
            cout << "===============================================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    displayCandidates();
                    break;
                case 2:
                    addCandidateMenu();
                    break;
                case 3:
                    removeCandidate();
                    break;
                case 4:
                    editCandidate();
                    break;
                case 5:
                    displayResults();
                    break;
                case 6:
                    checkElectionStatus();
                    break;
                case 7:
                    logout();
                    break;
                case 8:
                    cout << "Exiting the program. Thank you!\n";
                    exit(0);
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 8.\n";
            }
        }
    }

    // Method to add a candidate through admin menu
    void addCandidateMenu() {
        if (!loggedIn) {
            cout << "Access denied. Please login as admin.\n";
            return;
        }

        string name, party, symbol;
        cout << "Enter candidate name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter party name: ";
        getline(cin, party);
        cout << "Enter symbol: ";
        getline(cin, symbol);

        addCandidate(name, party, symbol);
        cout << "Candidate added successfully.\n";
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
        cout << "\n===================== Election System Main Menu =====================\n";
        cout << "| 1. Vote                                                           |\n";
        cout << "| 2. Login as Admin                                                 |\n";
        cout << "| 3. Exit                                                           |\n";
        cout << "=====================================================================\n";
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
                cout << "Exiting the program. Thank you!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    }

    return 0;
}

