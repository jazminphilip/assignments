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