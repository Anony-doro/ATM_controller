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
    virtual bool verifyPin(std::string cardId, std::string pin) = 0;
    virtual std::vector<std::string> getAccounts(std::string cardId) = 0; //get multiple account from one card
    virtual int getBalance(std::string accountId) = 0;
    virtual bool deposit(std::string accountId, int amount) = 0;
    virtual bool withdraw(std::string accountId, int amount) = 0;
    virtual ~bankSystem() {}; // 소멸자
};

#endif //BANKSYS_HPP
