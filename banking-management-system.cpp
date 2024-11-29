#include <iostream>
using namespace std;
class BankAccount
{
protected:
    int accountNumber, balance;
    string accountHolderName;

public:
    void createAccount(int acnumber, string name, int balance)
    {
        this->accountNumber = acnumber;
        this->balance = balance;
        this->accountHolderName = name;
        cout << "\nAcount Created Successfully ! ";
    }

    void displayAccountInfo()
    {
        cout << "\n---------Account Details-----------";
        cout << "\nAccount Number : " << this->accountNumber;
        cout << "\nAccount Holder Name : " << this->accountHolderName;
        cout << "\nAccount Balance : " << this->balance;
        cout << "\n-----------------------------------";
    }

    int getAccNumber()
    {
        return this->accountNumber;
    }

    void deposit(int amount)
    {
        this->balance = amount;
        cout << "Amount Added Successfully ! ";
    }
    void withdraw(int amount)
    {
        this->balance = this->balance - amount;
        cout << "Amount withdrwal Successfully ! ";
    }
};

class SavingAccount : public BankAccount
{
protected:
    int interestRate;
    string password;

public:
    void setPassword(string password)
    {
        this->password = password;
    }
    string getPassword()
    {
        return this->password;
    }

    void calculateInterest(double interestRate)
    {
        this->balance = (this->balance / 100) * interestRate;
    }
};
int main()
{
    SavingAccount account[10];
    string name;
    int accountNumber, count = 0, password, balance = 0;
    int choice;

    do
    {
        cout << "\n-----------Laxmi Chit Fund---------";
        cout << "\n1 for create account...";
        cout << "\n2 for view Account Details...";
        cout << "\n3 for deposit...";
        cout << "\n4 for withdraw...";
        cout << "\n5 for calculate Interest...";
        cout << "\n6 for Exit...";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // create account
            cout << "Enter Account Number : ";
            cin >> accountNumber;
            cin.ignore();
            cout << "Enter Name : ";
            getline(cin, name);
            cout << "Set Password : ";
            cin >> password;

            account[count].createAccount(accountNumber, name, balance);
            count++;

            break;
        }
        case 2:
        {
            // view details
            for (int i = 0; i < count; i++)
            {
                account->displayAccountInfo();
            }
            break;
        }
        case 3:
        {
            // deposit
            int acnumber;
            string password;
            bool flag = false;
            int amount;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);
            cout << "Enter Amount : ";
            cin >> amount;
            for (int i = 0; i < count; i++)
            {

                if (account[i].getAccNumber() == acnumber && account[i].getPassword() == password)
                {
                    account[i].deposit(amount);
                    flag = true;
                    // break;
                }
            }
            if (flag)
            {
                cout << "Account not Found or password incorrect ! ";
            }
            break;
        }
        case 4:
        {
            // withdraw
            int acnumber;
            bool flag = false;
            string password;
            int amount;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);
            cout << "Enter Amount : ";
            cin >> amount;
            for (int i = 0; i < count; i++)
            {

                if (account[i].getAccNumber() == acnumber)
                {
                    account[i].withdraw(amount);

                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "No Account Found ! ";
            }
            break;
        }
        case 5:
        {
            // calculate interest
            int acnumber;
            bool flag = false;
            string password;
            int interestRate;
            cout << "Enter Account Number : ";
            cin >> acnumber;
            cin.ignore();
            cout << "Enter Password : ";
            getline(cin, password);
            cout << "Enter InterestRate : ";
            cin >> interestRate;
            for (int i = 0; i < count; i++)
            {

                if (account[i].getAccNumber() == acnumber)
                {
                    account[i].calculateInterest(interestRate);
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "No Account Found ! ";
            }
            break;
        }
        case 6:
        {
            // for Exit
            cout << "Thank you for banking ! ";
            break;
        }
        }

    } while (choice != 6);

    return 0;
}