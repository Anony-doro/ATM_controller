#include <iostream>
#include "bankSys.hpp"
#include "ATM_control.hpp"

using namespace std;

int main() {

    //initializing
    bankSystem myBank;
    ATM_controller myATM(&myBank);

    cout << "=== ATM System Started ===" << endl;

    // normal scenario
    //1. insert card
    myATM.insertCard("card123");

    //2. enter pin
    bool success = myATM.enterPin("1234");

    if (success)
    {
        //3. select account
        myATM.selectAccount(1);
        //4. show balance
        myATM.showBalance();
        //5. deposit
        myATM.deposit(500);
        //6. withdraw
        myATM.withdraw(200);
    }
    cout << "=== Transaction Finished ===" << endl;

    return 0;
}