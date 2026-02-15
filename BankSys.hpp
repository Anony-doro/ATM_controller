#ifndef BANKSYS_HPP
#define BANKSYS_HPP

#include <string>
#include <vector>
#include <map>

class bankSystem {
private:
    std::map<std::string, std::string> cardPin;
    std::map<std::string, int> accountBalance;
    std::map<std::string, std::vector<std::string>> cardAccounts;
public:
    bankSystem();
    bool verifyPin(std::string cardId, std::string pin);
    std::vector<std::string> getAccounts(std::string cardId); //get multiple account from one card
    int getBalance(std::string accountId);
    bool deposit(std::string accountId, int amount);
    bool withdraw(std::string accountId, int amount);
    ~bankSystem() = default ; // 소멸자
};

#endif //BANKSYS_HPP
