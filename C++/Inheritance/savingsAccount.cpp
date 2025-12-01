#include "savingsAccount.h"
#include <iomanip>
#include <iostream>

void savingsAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}
double savingsAccount::getInterestRate() const {
    return interestRate;
}
void savingsAccount::postInterest() const { //like print how much you will make next time interest will enter your account?
    std::cout << "Your daily interest is: " << std::fixed << std::setprecision(2)
                << "USD " << getAccountBalance() * (interestRate / 100.0 / 365.0) << std::endl;
}

void savingsAccount::withdraw(double amount) {
    if (amount > bankAccount::getAccountBalance()) {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << bankAccount::getAccountBalance() << std::endl;

    } else if (amount <= bankAccount::getAccountBalance()) {
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance() << std::endl;
    }
}

void savingsAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl; // no service charges, changed from checking
}

void savingsAccount::retrieveInterest(){
    deposit(getAccountBalance() * (interestRate / 100.0 / 365.0)); // used deposit instead of making a new function
    std::cout << std::fixed << std::setprecision(2)
                << getAccountBalance() * (interestRate / 100.0 / 365.0) << "$ added" << std::endl;
}

savingsAccount::savingsAccount() = default; 

savingsAccount::savingsAccount(int accNumber, double bal, double rate): bankAccount(accNumber, bal), interestRate(rate) {
}