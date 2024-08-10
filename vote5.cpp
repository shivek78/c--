#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Candidate structure
struct Candidate {
    string name;
    int votes;

    Candidate(string n) : name(n), votes(0) {}
};

// Function prototypes
void decorate();
void showMenu();
void vote(vector<Candidate>& candidates);
void admin(vector<Candidate>& candidates);
void showResults(const vector<Candidate>& candidates);
void addCandidate(vector<Candidate>& candidates);

int main() {
    vector<Candidate> candidates;
    candidates.push_back(Candidate("Candidate A"));
    candidates.push_back(Candidate("Candidate B"));
    candidates.push_back(Candidate("Candidate C"));

    int choice;

    do {
        decorate();
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vote(candidates);
                break;
            case 2:
                admin(candidates);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 3);

    return 0;
}

void decorate() {
    cout << "***********************\n";
    cout << "*** Voting System  ***\n";
    cout << "***********************\n";
}

void showMenu() {
    cout << "Main Menu:\n";
    cout << "1. Vote\n";
    cout << "2. Admin\n";
    cout << "3. Exit\n";
}

void vote(vector<Candidate>& candidates) {
    cout << "Candidates for voting:\n";
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }
    int choice;
    cout << "Enter the number of the candidate you want to vote for: ";
    cin >> choice;

    if (choice >= 1 && choice <= candidates.size()) {
        candidates[choice - 1].votes++;
        cout << "Thank you for voting!\n";
    } else {
        cout << "Invalid candidate choice.\n";
    }
}

void admin(vector<Candidate>& candidates) {
    string password = "admin123";
    string input_password;
    cout << "Enter the admin password: ";
    cin >> input_password;

    if (input_password == password) {
        int admin_choice;
        do {
            cout << "\nAdmin Menu:\n";
            cout << "1. Show Results\n";
            cout << "2. Add Candidate\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> admin_choice;

            switch (admin_choice) {
                case 1:
                    showResults(candidates);
                    break;
                case 2:
                    addCandidate(candidates);
                    break;
                case 3:
                    cout << "Exiting admin panel...\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter again.\n";
            }
        } while (admin_choice != 3);
    } else {
        cout << "Incorrect password. Access denied.\n";
    }
}

void showResults(const vector<Candidate>& candidates) {
    cout << "Voting Results:\n";
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << candidates[i].name << ": " << candidates[i].votes << " votes\n";
    }
}

void addCandidate(vector<Candidate>& candidates) {
    string name;
    cout << "Enter the name of the new candidate: ";
    cin.ignore();  // Ignore any remaining newline characters in the input buffer
    getline(cin, name);

    candidates.push_back(Candidate(name));
    cout << "Candidate added successfully!\n";
}

