#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <iostream>
#include <fstream>

class Account {
public:
    std::string ownername;
    int money;
};

inline
char question(const std::string& question) {
    std::cout << question;
    char temp;
    std::cin >> temp;

    return temp;
}

inline
int accountcreator(const Account& account) {
    auto filename = account.ownername;
    filename.append(" Records");
    auto file2 = std::ifstream(filename);
    std::string line;

    if (file2.is_open()) {
        while (std::getline(file2, line)) {
            if (line.find("Owner Name:")) {
                std::cout << "Account Exists" << std::endl;
                return 101;
            }
        }
        file2.close();
    }

    auto file = std::ofstream(filename);

    file << "Owner Name: " << account.ownername << std::endl;
    file << "Money: " << account.money << "$" << std::endl;

    return 69420;
}

inline
void readrecords(const std::string& filename) {
    auto rec = std::ifstream(filename);

    std::string line;

    while (std::getline(rec, line)) {
        if (line.find("Name")) {
            std::cout << line << std::endl;
        } else if (line.find("Money")) {
            std::cout << line << std::endl;
        }
    }
}

inline
void addbalance(const int &moneytoadd, const std::string &person) {
    std::string personrecords = person + " Records";
    std::ifstream file(personrecords);
    int currentMoney = 0;
    std::string line;


    while (std::getline(file, line)) {
        if (line.find("Money:") != std::string::npos) {
            currentMoney = std::stoi(line.substr(line.find(":") + 1));
            break;
        }
    }
    file.close();

    currentMoney += moneytoadd;

    std::ofstream outfile(personrecords);
    outfile << "Owner Name: " << person << std::endl;
    outfile << "Money: " << currentMoney << "$" << std::endl;
}

void classloader(Account &account) {
    std::string filename = account.ownername + " Records";
    std::ifstream file(filename);

    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Owner Name:") != std::string::npos) {
            account.ownername = line.substr(line.find(":") + 1);
        } else if (line.find("Money:") != std::string::npos) {
            account.money = std::stoi(line.substr(line.find(":") + 1));
        }
    }
}

void bankmenu(Account &account) {
    std::cout << "Welcome " << account.ownername << "!" << std::endl;
    std::cout << "Choose money to add: ";
    std::cin >> account.money;

}


#endif