#pragma once
#include "bankAccount.h"

class savingsAccount : public bankAccount {
private:
    double interestRate = 0.0;
public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void postInterest() const;
    void withdraw(double amount); //OVERRIDDEN
    void print() const; //OVERRIDDEN

    void retrieveInterest(); // NEW FUNCTION

    savingsAccount();
    savingsAccount(int accountNumber, double balance, double interestRate);
};
