# Inheritance Activity
Name: Philip Jazmin

Course: CISC192 - C/C++ Programming

Date: 11/30/2025

### Program file for part D is named program.exe, could not include into markdown
## Main file (altered by me)
```cpp
#include <iostream>
#include "checkingAccount.h"
#include "savingsAccount.h" //new account type

//Note 1: Because there was no rubric, i tried to write code that is similar
//        or more 'in the style of' the code given from the assignment.
//        I did not include input validation since it was not in the video example.

//Note 2: Because I had to reconfigure code runner on vscode, I used
//        g++ main.cpp bankAccount.cpp checkingAccount.cpp savingsAccount.cpp -o program.exe to save my work in the executable
//        and .\program.exe to run program instead
//        I do not know how it will be on CLion or other IDEs

int main() {
    int accountNumber, input;
    double amount, interestRate, minBalance, serviceCharges;

    int ACCOUNTTYPE = 0; //This is to choose between creating a checking or saving account
    do{
    std::cout << "Enter account type: Checking (1) or Savings (2)" << std::endl;
    std::cin >> ACCOUNTTYPE; //no input validation like in video
    } while ((ACCOUNTTYPE != 1) && (ACCOUNTTYPE != 2));

    if(ACCOUNTTYPE == 1){//FOR CHECKING ACCOUNTS
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter balance (in USD): ";
    std::cin >> amount;
    std::cout << "Enter interest rate (%): ";
    std::cin >> interestRate;
    std::cout << "Enter min balance (in USD): ";
    std::cin >> minBalance;
    std::cout << "Enter service charges (%): ";
    std::cin >> serviceCharges;
    checkingAccount account(accountNumber, amount, interestRate, minBalance, serviceCharges);
    do {
        std::cout << std::endl;
        std::cout << "Which service do you want to use?" << std::endl;
        std::cout << "1<--Deposit: " << std::endl;
        std::cout << "2<--Withdraw: " << std::endl;
        std::cout << "3<--Print balance: " << std::endl;
        std::cout << "4<--Print account details: " << std::endl;
        std::cout << "5<--Print daily interest" << std::endl;
        std::cout << "0<--Exit" << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        switch (input) {
            case 0:
                std::cout << "Thank you. Good bye" << std::endl;
                break;
            case 1:
                std::cout << "Deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Service charge of " << account.getServiceCharges() <<
                "% applies if the withdrawal amount is more than $500 from the checking account" << std::endl;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                if (account.verifyBalance()) {
                    std::cout << "Your account balance is positive" << std::endl;
                } else {
                    std::cout << "Your account balance is lower than the min balance" << std::endl;
                }
                break;
            case 4:
                account.print();
                break;
            case 5:
                account.postInterest();
                break;
            default:
                std::cout << "Invalid input." << std::endl;
        }
    } while (input != 0);
    return 0;
}
    else{ // FOR SAVINGS ACCOUNT
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter balance (in USD): ";
    std::cin >> amount;
    std::cout << "Enter interest rate (%): ";
    std::cin >> interestRate;
    savingsAccount account(accountNumber, amount, interestRate); //only need 3 inputs
    do {
        std::cout << std::endl;
        std::cout << "Which service do you want to use?" << std::endl;
        std::cout << "1<--Deposit: " << std::endl;
        std::cout << "2<--Withdraw: " << std::endl;
        std::cout << "3<--Print account details: " << std::endl;
        std::cout << "4<--Print daily interest" << std::endl;
        std::cout << "5<--Add Daily Interest" << std::endl;
        std::cout << "0<--Exit" << std::endl;
        std::cin >> input;
        std::cout << std::endl;
        
        switch (input) {
            case 0:
                std::cout << "Thank you. Good bye" << std::endl;
                break;
            case 1:
                std::cout << "Deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                std::cout << std::endl;
                account.withdraw(amount);
                break;
            case 3:
                account.print();
                break;
            case 4:
                account.postInterest();
                break;
            case 5:
                account.retrieveInterest(); //function that adds a days worth of interest to balance.
            break;                          
            default:
                std::cout << "Invalid input." << std::endl;
        }
    } while (input != 0);
    return 0;
}
}
```
## savingsAccount.cpp (written from me)
```cpp
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
```
## savingsAccount.h (written from me)
```cpp
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
```
## CMakeLists.txt (altered by me) 
I switched from CMake for C++ 20 to C++ 11 to fit my own compiler
```cpp
cmake_minimum_required(VERSION 3.31)
project(inheritance_example)

set(CMAKE_CXX_STANDARD 11)

add_executable(inheritance_example main.cpp
        bankAccount.cpp
        bankAccount.h
        checkingAccount.cpp
        checkingAccount.h
        savingsAccount.h
        savingsAccount.cpp)
```

## bankAccount.cpp (from video)
```cpp
#include "bankAccount.h"
#include <iostream>

void bankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}
int bankAccount::getAccountNumber() const {
    return this->accountNumber;
}
double bankAccount::getAccountBalance() const {
    return this->balance;
}
void bankAccount::deposit(double amount) {
    balance += amount; // balance = balance + amount
}
void bankAccount::withdraw(double amount) {
    balance -= amount;
}
void bankAccount::print() const {
    std::cout << "Account Number: " << this->accountNumber << std::endl;
    std::cout << "Balance (USD): " << this->balance << std::endl;
}
bankAccount::bankAccount() = default;

bankAccount::bankAccount(int accountNumber, double balance) :
                         accountNumber(accountNumber), balance(balance) {}
```
## bankAccount.h (from video)
```cpp
#pragma once

class bankAccount {
private:
    int accountNumber = 0;
    double balance = 0;
public:
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;
    double getAccountBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void print() const;
    bankAccount();
    bankAccount(int accountNumber, double balance);
};
```
## checkingAccount.cpp (from video)
```cpp
#include "checkingAccount.h"

#include <iomanip>
#include <iostream>

void checkingAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}
double checkingAccount::getInterestRate() const {
    return interestRate;
}
void checkingAccount::setMinBalance(double minBalance) {
    this->minBalance = minBalance;
}
double checkingAccount::getMinBalance() const {
    return minBalance;
}
void checkingAccount::setServiceCharges(double serviceCharges) {
    this->serviceCharges = serviceCharges;
}
double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}
void checkingAccount::postInterest() const {
    std::cout << "Your daily interest is: " << std::fixed << std::setprecision(2)
                << "USD " << getAccountBalance() * (interestRate / 100.0 / 365.0) << std::endl;
}
bool checkingAccount::verifyBalance() const {
    if (getAccountBalance() >= minBalance) {
        std::cout << "Your balance is: " << getAccountBalance() << std::endl;
        return true;
    } else {
        std::cout << "Your balance is: " << getAccountBalance() << std::endl;
        return false;
    }
}
void checkingAccount::deposit(double amount) {
    bankAccount::deposit(amount);
}
void checkingAccount::withdraw(double amount) {
    double fee;
    if (amount > bankAccount::getAccountBalance()) {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << bankAccount::getAccountBalance() << std::endl;
    } else if (amount > 500) {
        fee = amount * (serviceCharges/100.0);
        amount = amount + fee;
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    } else if (amount <= 500) {
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    }

}
void checkingAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl;
    std::cout << "Min Balance $: " << getMinBalance() << std::endl;
    std::cout << "Service Charges %: " << getServiceCharges() << std::endl;
}
checkingAccount::checkingAccount() = default;
checkingAccount::checkingAccount(int accountNumber, double balance,
                                double interestRate, double minBalance, double serviceCharges) :
                                bankAccount(accountNumber, balance), interestRate(interestRate),
                                minBalance(minBalance), serviceCharges(serviceCharges) {}
```
## checkingAccount.h (from video)
```cpp
#pragma once
#include "bankAccount.h"

class checkingAccount : public bankAccount {
private:
    double interestRate = 0.0;
    double minBalance = 0.0;
    double serviceCharges = 0.0;
public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void setMinBalance(double minBalance);
    double getMinBalance() const;
    void setServiceCharges(double serviceCharges);
    double getServiceCharges() const;
    void postInterest() const;
    bool verifyBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void print() const;
    checkingAccount();
    checkingAccount(int accountNumber, double balance, double interestRate,
                    double minBalance, double serviceCharges);
};
```
