#include <iostream>
#include "bankSys.hpp"
#include "ATM_control.hpp"

using namespace std;

int main() {

    bankSystem myBank;
    ATM_controller myATM(&myBank);

    cout << "=== ATM Test Start ===" << endl;

    // normal scenario
    myATM.insertCard("card123");
    if (myATM.enterPin("1234")) {
        myATM.selectAccount("acc_checking");
        myATM.showBalance();
        myATM.deposit(500);
        myATM.withdraw(200);
    }

    cout << "\n=== Test Wrong PIN ===" << endl;
    // [실패 시나리오]
    myATM.insertCard("card123");
    myATM.enterPin("9999");

    return 0;
}