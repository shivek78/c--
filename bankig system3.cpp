#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define MIN_BALANCE 500
const string PASSWORD = "bsdk"; //  passwords

class InsufficientFunds{};

class Account
{
private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long NextAccountNumber;

public:
    Account(){}
    Account(string fname, string lname, float balance);
    long getAccNo() const { return accountNumber; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    float getBalance() const { return balance; }
    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    friend ofstream & operator<<(ofstream &ofs, const Account &acc);
    friend ifstream & operator>>(ifstream &ifs, Account &acc);
    friend ostream & operator<<(ostream &os, const Account &acc);
};

long Account::NextAccountNumber = 0;

class Bank
{
private:
    map<long, Account> accounts;

public:
    Bank();
    Account OpenAccount(string fname, string lname, float balance, string password);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount, string password);
    Account Withdraw(long accountNumber, float amount, string password);
    void CloseAccount(long accountNumber, string password);
    void ShowAllAccounts() const;
    ~Bank();
};

int main()
{
    Bank b;
    Account acc;
    int choice;
    string fname, lname;
    long accountNumber;
    float balance;
    float amount;
    string password;

    cout << "**************|| Banking System ||**********************" << endl;
    cout << "*********************************************************" << endl;
    cout << "************|| Welcome to Bablu Bank of India|| *************" << endl;
    cout << "*********************************************************" << endl;

    do
    {
    	
        cout << "\n\tSelect one option below: " << endl;
        cout << "\t1. Open an Account" << endl;
        cout << "\t2. Balance Enquiry" << endl;
        cout << "\t3. Deposit" << endl;
        cout << "\t4. Withdrawal" << endl;
        cout << "\t5. Close an Account" << endl;
        cout << "\t6. Show All Accounts" << endl;
        cout << "\t7. Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter First Name: ";
                cin >> fname;
                cout << "Enter Last Name: ";
                cin >> lname;
                cout << "Enter initial Balance: ";
                cin >> balance;
                cout << "Set a password for the account: ";
                cin >> password;
                acc = b.OpenAccount(fname, lname, balance, password);
                cout << endl << "*********************************************************" << endl;
                cout << "****************** Account Created **********************" << endl;
                cout << "*********************************************************" << endl;
                cout << acc;
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Password: ";
                cin >> password;
                acc = b.BalanceEnquiry(accountNumber);
                cout << endl << "*********************************************************" << endl;
                cout << "***************** Your Account Details ******************" << endl;
                cout << "*********************************************************" << endl;
                cout << acc;
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount: ";
                cin >> amount;
                cout << "Enter Password: ";
                cin >> password;
                acc = b.Deposit(accountNumber, amount, password);
                cout << endl << "*********************************************************" << endl;
                cout << "******************* Amount Deposited ********************" << endl;
                cout << "*********************************************************" << endl;
                cout << acc;
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount: ";
                cin >> amount;
                cout << "Enter Password: ";
                cin >> password;
                acc = b.Withdraw(accountNumber, amount, password);
                cout << endl << "*********************************************************" << endl;
                cout << "******************* Amount Withdrawn ********************" << endl;
                cout << "*********************************************************" << endl;
                cout << acc;
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Password: ";
                cin >> password;
                b.CloseAccount(accountNumber, password);
                cout << endl << "*********************************************************" << endl;
                cout << "****************** Account Closed ***********************" << endl;
                cout << "*********************************************************" << endl;
                break;
            case 6:
                cout << endl << "*********************************************************" << endl;
                cout << "****************** All Accounts *************************" << endl;
                cout << "*********************************************************" << endl;
                b.ShowAllAccounts();
                break;
            case 7:
                break;
            default:
                cout << "\nEnter correct choice" << endl;
                exit(0);
        }
    } while(choice != 7);
cout<<" THANK YOU THIS PROJECT FROM BABLU KAUMAR";
    return 0;
}

Account::Account(string fname, string lname, float balance)
{
    NextAccountNumber++;
    accountNumber = NextAccountNumber;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::Withdraw(float amount)
{
    if(balance - amount < MIN_BALANCE)
        throw InsufficientFunds();
    balance -= amount;
}

void Account::setLastAccountNumber(long accountNumber)
{
    NextAccountNumber = accountNumber;
}

long Account::getLastAccountNumber()
{
    return NextAccountNumber;
}

ofstream & operator<<(ofstream &ofs, const Account &acc)
{
    ofs << acc.accountNumber << endl;
    ofs << acc.firstName << endl;
    ofs << acc.lastName << endl;
    ofs << acc.balance << endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Account &acc)
{
    ifs >> acc.accountNumber;
    ifs >> acc.firstName;
    ifs >> acc.lastName;
    ifs >> acc.balance;
    return ifs;
}

ostream & operator<<(ostream &os, const Account &acc)
{
    os << "First Name: " << acc.getFirstName() << endl;
    os << "Last Name: " << acc.getLastName() << endl;
    os << "Account Number: " << acc.getAccNo() << endl;
    os << "Balance: " << acc.getBalance() << endl;
    return os;
}

Bank::Bank()
{
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile)
    {
        //cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    while(!infile.eof())
    {
        infile >> account;
        accounts.insert(pair<long, Account>(account.getAccNo(), account));
    }
    Account::setLastAccountNumber(account.getAccNo());
    infile.close();
}

Account Bank::OpenAccount(string fname, string lname, float balance, string password)
{
    if(password != PASSWORD)
    {
        cout << "Incorrect password. Account cannot be opened." << endl;
        return Account();
    }

    ofstream outfile;
    Account account(fname, lname, balance);
    accounts.insert(pair<long, Account>(account.getAccNo(), account));
    outfile.open("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for(itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(long accountNumber)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}

Account Bank::Deposit(long accountNumber, float amount, string password)
{
    if(password != PASSWORD)
    {
        cout << "Incorrect password. Deposit cannot be processed." << endl;
        return Account();
    }

    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}

Account Bank::Withdraw(long accountNumber, float amount, string password)
{
    if(password != PASSWORD)
    {
        cout << "Incorrect password. Withdrawal cannot be processed." << endl;
        return Account();
    }

    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}

void Bank::CloseAccount(long accountNumber, string password)
{
    if(password != PASSWORD)
    {
        cout << "Incorrect password. Account closure cannot be processed." << endl;
        return;
    }

    map<long, Account>::iterator itr = accounts.find(accountNumber);
    cout << "Account Deleted" << endl << itr->second;
    accounts.erase(accountNumber);
}

void Bank::ShowAllAccounts() const
{
    cout << "---------------------------------------------------------" << endl;
    for(auto const &entry : accounts)
    {
        cout << entry.second << endl;
        cout << "---------------------------------------------------------" << endl;
    }
}

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);
    map<long, Account>::iterator itr;
    for(itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
}


