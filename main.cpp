#include <iostream>
#include "bankSys.hpp"
#include "ATM_control.hpp"

using namespace std;

int main() {

    //initializing
    bankSystem myBank;
    ATM_controller myATM(&myBank);

    string card;
    string pin;
    int choice;
    int amount;
    cout << "=== ATM System Started ===" << endl;

    // normal scenario
    //1. insert card
    cout << "Insert the card : ";
    cin >> card;
    myATM.insertCard(card);

    //2. enter pin
    cout << "ENTER PIN : ";
    cin >> pin;
    bool success = myATM.enterPin(pin);

    if (success)
    {
        //3. select account
        myATM.selectAccount();
        //4. show balance
        myATM.showBalance();
        cout << "Withdraw : 1\nDeposit : 2\nShow Balace : 3\n";

        while (true)
        {
            cout << "Select : ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Withdraw Amount : ";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            }
            else if (choice == 2)
            {
                cout << "Deposit Amount : ";
                cin >> amount;
                myATM.deposit(amount);
                break;
            }
            else if (choice == 3)
            {
                myATM.showBalance();
                break;
            }
            else
                cout << "Invalid Choice" << endl;
        }
    }
    cout << "=== Transaction Finished ===" << endl;

    return 0;
}