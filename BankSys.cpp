
#include "BankSys.hpp"
using namespace std;

//contructor
bankSystem::bankSystem() {
    cardPin["card123"] = "1234";
    cardAccounts["card123"] = {"acc_checking", "acc_savings"};
    accountBalance["acc_checking"] = 1000;
    accountBalance["acc_savings"] = 5000;
}

bool bankSystem::verifyPin(string cardId, string pin) {
    if (cardPin.find(cardId) != cardPin.end()) { // goes through map to find pin.
        return cardPin[cardId] == pin;
    }
    return false;
}

vector<string> bankSystem::getAccounts(string cardId) {

    if (cardAccounts.find(cardId) != cardAccounts.end()) {
        return cardAccounts[cardId];
    }
    return {};
}

int bankSystem::getBalance(string accountId) {
    if (accountBalance.find(accountId) != accountBalance.end()) {
        return accountBalance[accountId];
    }
    return 0;
}

bool bankSystem::deposit(string accountId, int amount) {
    if (amount <= 0) return false;
    accountBalance[accountId] += amount;
    return true;
}

bool bankSystem::withdraw(string accountId, int amount) {
    if (amount <= 0) return false;
    if (accountBalance[accountId] >= amount) {
        accountBalance[accountId] -= amount;
        return true;
    }
    return false;
}