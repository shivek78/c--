#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

/* ADMIN PASSWORD: pak123 */

class Voting;

class SystemDisplay {
public:
    char choose;
    void select();

    void text_animation(const char a[200]) {  // Text sliding 
        int i;
        long double k;
        for (i = 0; a[i] != '\0'; i++) {
            for (k = 0; k < 7000000; k++);
            cout << a[i];
        }
    }

    friend class Voting;  // Using concept of Friend Classes
    friend class Admin;
};

class Voting {
private:
    string cnicnum;
    string result;
    static int PTI, PMLN, PPP, MQM;  // Vote count for different parties
    static int total;
    static float ptiprcnt, pmlnprcnt, pppprcnt, mqmprcnt;
    int districtcode, sampleN, sampleS, sampleE, sampleW;  // For different districts
    char district;
    string name;
    int age;

public:
    int i;
    char opt;
    Voting(int p, char q) : i(p), opt(q) {}
    Voting() {}

    void delay(int a) {
        int i, j;
        for (i = 0; i < a; i++)
            j = i;
    }

    friend class SystemDisplay;
    SystemDisplay s1;

    void cniccheck() {  // Checks if CNIC entered is present in registered voter CNIC
        ofstream cnicinput;
        cnicinput.open("cnic_input.txt", ios::app);
        cnicinput << " " << cnicnum;
        cnicinput.close();

        ifstream cnic;
        cnic.open("cnicoop.txt");
        if (cnic.is_open()) {
            while (getline(cnic, result)) {
                if (result.find(cnicnum) != string::npos) {
                    cout << "\n\n\t\tCNIC NUMBER MATCHED FROM RECORDS.\n\t\tREDIRECTING TO VOTING PAGE";
                    for (i = 0; i <= 2; i++) {
                        delay(1000000000);
                        cout << ".";
                    }
                    votingpage();
                } else {
                    cout << "\n\n\t\tYOUR CNIC NUMBER DOES NOT MATCH THE RECORDS\a\a";
                    cout << "\n\t\tREDIRECTING TO MAIN PAGE";
                    for (i = 0; i <= 2; i++) {
                        delay(1000000000);
                        cout << ".";
                    }
                    s1.select();
                }
            }
        }
    }

    void cnic() {  // Input of CNIC and checking if vote has already been cast or not
        cout << "\n\t\tEnter your CNIC Number: \t";
        cin >> cnicnum;

        ifstream cnicinput;
        cnicinput.open("cnic_input.txt");

        if (cnicinput.is_open()) {
            while (getline(cnicinput, result)) {
                if (result.find(cnicnum) == string::npos) {
                    cout << "\n\n\t\tNO VOTE CAST FOUND ON THIS CNIC";
                    cout << endl << "\n\t\tCHECKING IF YOUR CNIC IS PRESENT IN REGISTERED VOTERS";
                    for (i = 0; i <= 2; i++) {
                        delay(1000000000);
                        cout << ".";
                    }
                    cniccheck();
                } else {
                    cout << "\n\n\t\tVOTE HAS ALREADY BEEN CAST ON THIS CNIC NUMBER.\a\a";
                    cout << "\n\t\tREDIRECTING TO MAIN PAGE";

                    for (i = 0; i <= 2; i++) {
                        delay(1000000000);
                        cout << ".";
                    }
                    s1.select();
                }
            }
        }
    }

    void District() {  // Checking the input district and code is valid or not
        cout << "\n\n\t\tYour District: ";
        cin >> district;

        switch (district) {
        case 'N':
            cout << "\n\n\t\tEnter your District code: \t";
            cin >> districtcode;
            sampleN = 42101;

            if (sampleN == districtcode) {
                cnic();
            } else {
                cout << "\n\n\t\tYou do not belong to this district";
                District();
            }
            break;

        case 'S':
            cout << "\n\n\t\tEnter your District code: \t";
            cin >> districtcode;
            sampleS = 42102;

            if (sampleS == districtcode) {
                cnic();
            } else {
                cout << "\n\n\t\tYou do not belong to this district";
                District();
            }
            break;

        case 'W':
            cout << "\n\t\tEnter your District code: \t";
            cin >> districtcode;
            sampleW = 42103;

            if (sampleW == districtcode) {
                cnic();
            } else {
                cout << "\n\n\t\tYou do not belong to this district";
                District();
            }
            break;

        case 'E':
            cout << "\n\n\t\tEnter your District code: \t";
            cin >> districtcode;
            sampleE = 42104;

            if (sampleE == districtcode) {
                cnic();
            } else {
                cout << "\n\n\t\tYou do not belong to this district";
                District();
            }
            break;

        case '0':
            system("cls");
            s1.select();
            break;

        default:
            cout << "\n\n\t\tWrong Input Detected. Redirecting to Display page";
            for (i = 0; i <= 2; i++) {
                delay(1000000000);
                cout << "";
            }
            system("cls");
            s1.select();
            break;
        }
    }

    void voter() {  // Input information and checking of age
        system("cls");
        cout << "\t\t************************************************";
        cout << "\n\t\t|                                             |\n";
        cout << "\n\t\t|                VOTING PAGE                  |\n";
        cout << "\n\t\t|                                             |\n";
        cout << "\t\t************************************************";

        cout << "\n\n\n\t\tEnter your Name: \t";
        cin.ignore();
        getline(cin, name);

        cout << "\n\t\tEnter your Age: \t";
        cin >> age;

        if (age >= 18) {
            cout << "\n\t\tSelect your District";
            cout << "\n\n\t\tNorth : N\n\t\tSouth : S\n\t\tWest :  W\n\t\tEast :  E\n\n\t\tPress 0 to go back to Main Page";
            District();
        } else {
            cout << "\n\n\t\tYou are not Eligible to vote\n\n";
            cout << "--------------------------------------------------------------------------------";
            cout << "\n\n\t\tRedirecting to Main Page";
            for (i = 0; i <= 2; i++) {
                delay(1000000000);
                cout << ".";
            }
            system("cls");
            s1.select();
        }
    }

    void votingpage() {  // Casting vote and Calculation of Votes through Filing
        char vote[10];
        ofstream individualvotes;
        individualvotes.open("Vote_Count.txt", ios::out);
        system("cls");
        cout << "\n\n\tWelcome to the Online Voting Page of Pakistan\n\n\n";
        cout << "\t\tAvailable Parties to vote\n\n";
        cout << "\t\tPakistan Tehreek e Insaaf\n\t\t\t(PTI)\n\t\tPakistan Muslim League Noon\n\t\t\t(PMLN)\n\t\tPakistan Peoples Party\n\t\t\t(PPP)\n\t\tMuttaihada Qaumi Movement\n\t\t\t(MQM)\n\n\n";

        cout << "\tEnter your Choice from the following mentioned above: \t";
        cin >> vote;

        if (strcmp(vote, "PTI") == 0) {
            PTI = PTI + 1;
        } else if (strcmp(vote, "PMLN") == 0) {
            PMLN = PMLN + 1;
        } else if (strcmp(vote, "PPP") == 0) {
            PPP = PPP + 1;
        } else if (strcmp(vote, "MQM") == 0) {
            MQM = MQM + 1;
        } else {
            cout << "\n\t\tWrong Input Detected.\n\t\t\tReloading the Page.";
            votingpage();
        }

        total = PTI + PMLN + PPP + MQM;  // Calculating total votes

        ptiprcnt = (100 * PTI) / total;  // Calculating percentage of votes
        pmlnprcnt = (100 * PMLN) / total;
        pppprcnt = (100 * PPP) / total;
        mqmprcnt = (100 * MQM) / total;

        individualvotes << endl << "Total votes which has been cast till now is: " << total;
        individualvotes << endl << "Total votes of PTI are: " << PTI;
        individualvotes << endl << "Total votes of PMLN are: " << PMLN;
        individualvotes << endl << "Total votes of PPP are: " << PPP;
        individualvotes << endl << "Total votes of MQM are: " << MQM;

        individualvotes << endl << "Total Percentage of PTI votes: " << ptiprcnt << "%";
        individualvotes << endl << "Total Percentage of PMLN votes: " << pmlnprcnt << "%";
        individualvotes << endl << "Total Percentage of PPP votes: " << pppprcnt << "%";
        individualvotes << endl << "Total Percentage of MQM votes: " << mqmprcnt << "%";

        individualvotes.close();

        cout << "\n\n\n\n\t\t\t\tVote Casted Successfully\n";
        cout << "\t\t\t\tRedirecting to Main Page.";
        for (i = 0; i <= 2; i++) {
            delay(1000000000);
            cout << ".";
        }

        system("cls");
        s1.select();
    }

    void displayresult() {  // Display result of election
        system("cls");
        cout << "\t\t************************************************";
        cout << "\n\t\t|                                             |\n";
        cout << "\n\t\t|                VOTING RESULT                |\n";
        cout << "\n\t\t|                                             |\n";
        cout << "\t\t************************************************";
        cout << "\n\n\n\t\tTotal votes cast: " << total << endl;
        cout << "\n\n\n\t\tTotal votes of PTI are: " << PTI << endl;
        cout << "\n\t\tTotal votes of PMLN are: " << PMLN << endl;
        cout << "\n\t\tTotal votes of PPP are: " << PPP << endl;
        cout << "\n\t\tTotal votes of MQM are: " << MQM << endl;

        cout << "\n\n\n\t\tTotal Percentage of PTI votes: " << ptiprcnt << "%" << endl;
        cout << "\n\t\tTotal Percentage of PMLN votes: " << pmlnprcnt << "%" << endl;
        cout << "\n\t\tTotal Percentage of PPP votes: " << pppprcnt << "%" << endl;
        cout << "\n\t\tTotal Percentage of MQM votes: " << mqmprcnt << "%" << endl;

        cout << "\n\n\n\t\t\tRedirecting to Main Page.";
        for (i = 0; i <= 2; i++) {
            delay(1000000000);
            cout << ".";
        }

        system("cls");
        s1.select();
    }
};

int Voting::PTI = 0;
int Voting::PMLN = 0;
int Voting::PPP = 0;
int Voting::MQM = 0;
int Voting::total = 0;
float Voting::ptiprcnt = 0.0;
float Voting::pmlnprcnt = 0.0;
float Voting::pppprcnt = 0.0;
float Voting::mqmprcnt = 0.0;

class Admin {
private:
    string password;
    int adminchoice;
    string inputpassword;

public:
    int i;

    void admin() {  // Admin section where admin inputs password to access the section
        password = "pak123";// password is here
        
        system("cls");
        cout << "\t\t************************************************";
        cout << "\n\t\t|                                             |\n";
        cout << "\n\t\t|                ADMIN PAGE                   |\n";
        cout << "\n\t\t|                                             |\n";
        cout << "\t\t************************************************";

        cout << "\n\n\t\tEnter Password: \t";
        char ch;
        ch = _getch();
        while (ch != 13) {  // Character 13 is enter
            inputpassword.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if (inputpassword == password) {
            adminsection();
        } else {
            cout << "\n\n\t\tWrong Password. Enter Again\n\n";
            system("pause");
            system("cls");
            admin();
        }
    }

    void adminsection() {
        system("cls");
        cout << "\t\t************************************************";
        cout << "\n\t\t|                                             |\n";
        cout << "\n\t\t|                ADMIN PAGE                   |\n";
        cout << "\n\t\t|                                             |\n";
        cout << "\t\t************************************************";

        cout << "\n\n\t\t1.\tDisplay Result\n";
        cout << "\t\t2.\tExit\n";
        cout << "\n\t\tEnter your Choice: \t";
        cin >> adminchoice;

        Voting v1;
        switch (adminchoice) {
        case 1:
            v1.displayresult();
            break;

        case 2:
            system("cls");
            s1.select();
            break;

        default:
            cout << "\n\n\t\tWrong Input Detected. Enter Again.";
            for (i = 0; i <= 2; i++) {
                v1.delay(1000000000);
                cout << "";
            }
            system("cls");
            adminsection();
            break;
        }
    }

    SystemDisplay s1;
};

void SystemDisplay::select() {
    Voting v1;
    Admin a1;

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
        for (v1.i = 0; v1.i <= 2; v1.i++) {
            v1.delay(1000000000);
            cout << "";
        }
        select();
        break;
    }
}

int main() {
    SystemDisplay s1;
    s1.select();
}
