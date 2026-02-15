#include "ATM_control.hpp"

#include <iostream>
#include <vector>

using namespace std;

ATM_controller::ATM_controller(bankSystem* bank) {
  this->bank = bank;
  this->isAuthenticated = false;
  this->currentCardId = "";
  this->currentAccountId = "";
}

void ATM_controller::insertCard(std::string cardID){
  cout << "Card Inserted" << endl;
  cout << "Card ID: " << cardID << endl;
  this->currentCardId = cardID;
}

bool ATM_controller::enterPin(std::string pin){
  if (currentCardId == ""){
    cout << "Error: Insert the card" << endl;
    return false;
  }

  bool result = bank->verifyPin(currentCardId, pin);
  if (result){
    cout << "Pin verified." << endl;
    this->isAuthenticated = true;
  } else {
    cout << "Wrong pin." << endl;
  }
  return result;
}

void ATM_controller::selectAccount() {
  if(!isAuthenticated){
    cout << "authentication required" << endl;
    return;
  }

  vector<string> accounts = bank->getAccounts(currentCardId);

  if (accounts.empty()) {
    cout << "[Error] No accounts found for this card." << endl;
    return;
  }

  //show accounts
  cout << "\n--- Select Account ---" << endl;
  for (int i = 0; i < accounts.size(); ++i) {
    cout << i + 1 << ". " << accounts[i] << endl;
  }
  cout << "Select (1-" << accounts.size() << "): ";

  int choice;
  cin >> choice;

  if (choice > 0 && choice <= (int)accounts.size())
    {
    this->currentAccountId = accounts[choice-1];
    cout << "Selected Account ID: " << this->currentAccountId << endl;
    }
    else {
      cout << "Wrong choice." << endl;
      }
}

void ATM_controller::showBalance(){
  int balance = bank->getBalance(currentAccountId);
  cout << "Balance: " << balance << endl;
}

void ATM_controller::deposit(int amount){
  if (bank->deposit(currentAccountId, amount)){
    cout << "Deposited : " << amount << endl;
    showBalance();
  }
  else {
     cout << "deposit failed" << endl;
  }
}

void ATM_controller::withdraw(int amount){
  if (bank->withdraw(currentAccountId, amount)){
    cout << "Withdrawn : " << amount << endl;
    showBalance();
  }
  else {
    cout << "withdraw failed" << endl;
  }
}
