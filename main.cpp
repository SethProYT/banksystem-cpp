#include <iostream>
#include "functions.h"

// btw function names in functions.h
// char question(const std::string& question)
// void accountcreator(const Account& account)

// class Account {
// public:
//     std::string ownername;
//     int money;
// };

// void readrecords(const std::string& filename)
// void addbalance(const int &moneytoadd, const std::string &person)

int main() {
    std::cout << "Do you have an account: " << std::endl;
    std::string response;
    std::cin >> response;

    if (response == "yes") {
        Account account;
        std::cout << "Enter your First Name: ";
        std::string response1;
        std::cin >> response1;
        account.ownername = response1;
        account.money = NULL;
        classloader(account);
        bankmenu(account);
    } else if (response == "no") {
        Account newaccount;

        std::string var;

        std::cout << "First Name: ";
        std::cin >> newaccount.ownername;
        std::cout << "Money: ";
        std::cin >> newaccount.money;
        accountcreator(newaccount);
        var = newaccount.ownername + " Records";
        readrecords(var);
        std::cout << "As a bonus we will give you 1000$ because we are bankrupt" << std::endl;
        addbalance(1000, newaccount.ownername);


        return 287394563;
    }
}
