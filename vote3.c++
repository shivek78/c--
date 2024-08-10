#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Voting; // Forward declaration

class SystemDisplay {
public:
    void select();
    void text_animation(const string& a);
};

class Candidate {
public:
    string name;
    string party;
    int votes;

    Candidate(const string& n, const string& p) : name(n), party(p), votes(0) {}
};

class Voting {
private:
    vector<Candidate> candidates;
    map<string, string> voters;  // voter ID to name mapping

public:
    void voter();
    void votingPage();
    void displayResult();
    void addCandidate(const string& name, const string& party);

    vector<Candidate>& getCandidates() {  // Return by reference to allow modification
        return candidates;
    }

    bool isVoterRegistered(const string& voterID) const {
        return voters.find(voterID) != voters.end();
    }
};

class Admin { // Moved Admin class definition before its use
private:
    string password = "pak123";
    string inputPassword;

public:
    void admin();
    void adminSection(Voting& voting);

private:
    void addCandidate(Voting& voting);
    void displayResult(const Voting& voting);
};

void SystemDisplay::select() {
    Voting v1;
    Admin a1;
    char choose;

    system("cls");
    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|             ONLINE VOTING SYSTEM            |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\n\t\t\t1.\tVote\n";
    cout << "\t\t\t2.\tAdmin\n";
    cout << "\t\t\t3.\tExit\n";

    cout << "\n\n\t\tEnter Your Choice: \t";
    cin >> choose;

    switch (choose) {
    case '1':
        v1.voter();
        break;
    case '2':
        a1.admin();
        break;
    case '3':
        system("cls");
        text_animation("\n\n\n\n\n\n\n\n\t\t\t\t   Exiting Program. \n\t\t\t\t ");
        exit(0);
        break;
    default:
        cout << "\n\n\t\tWrong Input Detected. Enter Again.";
        select();
        break;
    }
}

void SystemDisplay::text_animation(const string& a) {
    for (char c : a) {
        cout << c;
        Sleep(50);
    }
}

void Voting::voter() {
    system("cls");
    string name, dob, voterID;

    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|                VOTING PAGE                  |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\n\t\tEnter your Name: \t";
    cin.ignore();
    getline(cin, name);

    cout << "\n\t\tEnter your Date of Birth (DD/MM/YYYY): \t";
    getline(cin, dob);

    cout << "\n\t\tEnter your Voter ID: \t";
    getline(cin, voterID);

    if (voters.find(voterID) == voters.end()) {
        voters[voterID] = name;
        votingPage();
    } else {
        cout << "\n\n\t\tVote has already been cast with this Voter ID.\n";
        cout << "\t\tReturning to Main Menu...";
        Sleep(2000);
        select();
    }
}

void Voting::votingPage() {
    system("cls");

    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|                VOTING PAGE                  |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\tAvailable Candidates:\n";
    auto& candidates = getCandidates();
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << "\t" << i + 1 << ". " << candidates[i].name << " (" << candidates[i].party << ")\n";
    }

    int choice;
    cout << "\n\tEnter the number corresponding to your choice: \t";
    cin >> choice;

    if (choice > 0 && choice <= candidates.size()) {
        candidates[choice - 1].votes += 1;
        cout << "\n\tVote cast successfully!";
    } else {
        cout << "\n\tInvalid choice. Try again.";
        votingPage();
        return;
    }

    cout << "\n\tReturning to Main Menu...";
    Sleep(2000);
    select();
}

void Voting::displayResult() {
    system("cls");

    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|                VOTING RESULT                |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\tResults:\n";
    auto& candidates = getCandidates();
    for (const auto& candidate : candidates) {
        cout << "\t" << candidate.name << " (" << candidate.party << "): " << candidate.votes << " votes\n";
    }

    cout << "\n\n\tReturning to Main Menu...";
    Sleep(5000);
    select();
}

void Voting::addCandidate(const string& name, const string& party) {
    candidates.emplace_back(name, party);
}

void Admin::admin() {
    system("cls");
    inputPassword.clear();

    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|                ADMIN PAGE                   |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\t\tEnter Password: \t";
    char ch;
    ch = _getch();
    while (ch != 13) {  // Character 13 is enter
        inputPassword.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    if (inputPassword == password) {
        Voting v1; // Create an instance of Voting
        adminSection(v1); // Pass the instance to adminSection
    } else {
        cout << "\n\n\t\tWrong Password. Enter Again\n\n";
        system("pause");
        admin();
    }
}

void Admin::adminSection(Voting& voting) {
    system("cls");
    int adminChoice;

    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|                ADMIN PAGE                   |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\t\t1.\tDisplay Result\n";
    cout << "\t\t2.\tAdd Candidate\n";
    cout << "\t\t3.\tExit\n";
    cout << "\n\t\tEnter your Choice: \t";
    cin >> adminChoice;

    switch (adminChoice) {
    case 1:
        displayResult(voting);
        break;
    case 2:
        addCandidate(voting);
        break;
    case 3:
        select();
        break;
    default:
        cout << "\n\n\t\tWrong Input Detected. Enter Again.";
        adminSection(voting);
        break;
    }
}

void Admin::addCandidate(Voting& voting) {
    system("cls");
    string name, party;

    cout << "\t\t************************************************";
    cout << "\n\t\t|                                             |\n";
    cout << "\n\t\t|               ADD CANDIDATE                 |\n";
    cout << "\n\t\t|                                             |\n";
    cout << "\t\t************************************************";

    cout << "\n\n\tEnter Candidate Name: \t";
    cin.ignore();
    getline(cin, name);

    cout << "\n\tEnter Party Name: \t";
    getline(cin, party);

    voting.addCandidate(name, party);

    cout << "\n\tCandidate added successfully!";
    cout << "\n\tReturning to Admin Menu...";
    Sleep(2000);
    adminSection(voting);
}

void Admin::displayResult(const Voting& voting) {
    voting.displayResult();
}

int main() {
    SystemDisplay s1;
    s1.select();
    return 0;
}
