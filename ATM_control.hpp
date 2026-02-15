#ifndef ATM_CONTROL_HPP
#define ATM_CONTROL_HPP

#include "BankSys.hpp"
#include <string>

class ATM_controller {
private:
    bankSystem* bank;
    std::string currentCardId;
    std::string currentAccountId;
    bool isAuthenticated;
public:
    explicit ATM_controller(bankSystem* bank); //constructor
    void insertCard(std::string cardID);
    bool enterPin(std::string pin);
    void selectAccount(int choice);
    void showBalance();
    void deposit(int amount);
    void withdraw(int amount);
};


#endif //ATM_CONTROL_HPP
