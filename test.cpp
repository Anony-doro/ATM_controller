#include <iostream>
#include <cassert> // 검증용 헤더
#include "bankSys.hpp"
#include "ATM_control.hpp"

using namespace std;

void runTests() {
    cout << "====== [UNIT TEST START] ======" << endl;

    // initialization
    bankSystem bank;
    ATM_controller atm(&bank);

    // test for pin
    atm.insertCard("card123");
    assert(atm.enterPin("1234") == true);  // 맞는 비번이면 true여야 함
    assert(atm.enterPin("9999") == false); // 틀린 비번이면 false여야 함
    cout << "PIN Verification Test Passed" << endl;

    // test for login and check balance
    atm.enterPin("1234"); // 로그인
    atm.selectAccount();

    // assume initial balance 0
    atm.deposit(500);
    assert(bank.getBalance("acc_checking") == 1500);
    cout << "Deposit Test Passed" << endl;

    atm.withdraw(200);
    assert(bank.getBalance("acc_checking") == 1300);
    cout << "Withdraw Test Passed" << endl;

    // test for no money
    bool result = bank.withdraw("acc_checking", 999999);
    assert(result == false); // 출금 실패해야 함
    cout << "Overdraft Protection Test Passed" << endl;

    cout << "====== [ALL TESTS PASSED] ======" << endl;
}

int main() {
    runTests();
    return 0;
}