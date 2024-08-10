#include <iostream>
#include <string>
#include <vector>
uing namespace std;

class Candidate {
public:
    std::string name;
    std::string party;
    int votes = 0; // Initialize votes to zero

    Candidate(const std::string& n, const std::string& p) : name(n), party(p) {}
};

class ElectionSystem {
private:
    std::vector<Candidate> candidates;
    std::string adminPassword = "shivek";
    bool loggedIn = false;

public:
    void addCandidate(const std::string& name, const std::string& party) {
        candidates.emplace_back(name, party);
    }

    void displayCandidates() {
        std::cout << "Candidates:\n";
        for (size_t i = 0; i < candidates.size(); ++i) {
            std::cout << i + 1 << ". " << candidates[i].name << " (" << candidates[i].party << ")\n";
        }
    }

    void vote() {
        if (!loggedIn) {
            std::string enteredPassword;
            std::cout << "Enter admin password: ";
            std::cin >> enteredPassword;

            if (enteredPassword != adminPassword) {
                std::cout << "Incorrect password. Access denied.\n";
                return;
            }
            loggedIn = true;
        }

        std::cout << "Welcome! Please cast your vote:\n";
        displayCandidates();

        int choice;
        std::cout << "Enter the candidate number (1-" << candidates.size() << "), or 0 to exit: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting the program. Thank you!\n";
            displayResults(); // Show results before exiting
            exit(0);
        } else if (choice >= 1 && choice <= candidates.size()) {
            candidates[choice - 1].votes++; // Increment votes for the chosen candidate
            std::cout << "You voted for " << candidates[choice - 1].name << ". Thank you!\n";
        } else {
            std::cout << "Invalid choice. Please select a valid candidate or 0 to exit.\n";
        }
    }

    void displayResults() {
        std::cout << "\nElection Results:\n";
        for (const auto& candidate : candidates) {
            std::cout << candidate.name << " (" << candidate.party << "): " << candidate.votes << " votes\n";
        }

        // Find the winner
        int maxVotes = 0;
        std::string winner;
        for (const auto& candidate : candidates) {
            if (candidate.votes > maxVotes) {
                maxVotes = candidate.votes;
                winner = candidate.name;
            }
        }
        std::cout << "Winner: " << winner << " (" << maxVotes << " votes)\n";
    }
};

int main() {
    ElectionSystem election;
    election.addCandidate("John Doe", "Party A");
    election.addCandidate("Jane Smith", "Party B");

    while (true) {
        election.vote();
    }

    return 0;
}