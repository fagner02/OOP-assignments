#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

class Account {
protected:
    float balance;
    std::string clientId;
    int id;
    std::string type;
public:
    Account(int id, std::string clientId) {
        this->id = id;
        this->clientId = clientId;
    }

    void depositValue(float value) {
        this->balance += value;
    }

    virtual void monthlyUpdate() {
        throw "Not implemented";
    }

    void withdrawValue(float value) {
        if (this->balance < value) {
            std::cout << "Insufficient funds";
            return;
        }
        this->balance -= value;
        std::cout << "Withdrawal successful";
    }

    void transfer(Account& account, float value) {
        this->withdrawValue(value);
        account.depositValue(value);
    }

    void print() {
        std::cout << "Account id: " << this->id << std::endl;
        std::cout << "Account client id: " << this->clientId << std::endl;
        std::cout << "Account balance: " << this->balance << std::endl;
        std::cout << "Account type: " << this->type << std::endl;
    }

    int getId() {
        return this->id;
    }
};

class CheckingAccount : public Account {
    CheckingAccount(int id, std::string clientId) : Account(id, clientId) {
        this->type = "Checking";
    }

    void monthlyUpdate() {
        this->balance -= 20;
        std::cout << "Checking account monthly update successful";
    }
};

class SavingsAccount : public Account {
    SavingsAccount(int id, std::string clientId) : Account(id, clientId) {
        this->type = "Savings";
    }

    void monthlyUpdate() {
        this->balance += 0.01 * this->balance;
        std::cout << "Saving account monthly update successful";
    }
};

class Client {
public:
    std::string id;
    std::vector<std::shared_ptr<Account>> accounts;
    Client(std::string id) {
        this->id = id;
    }

    void addAccount(std::shared_ptr<Account> account) {
        this->accounts.push_back(account);
    }

    void print() {
        std::cout << "Client id: " << this->id << std::endl;
        for (auto account : this->accounts) {
            account->print();
        }
    }
};

class Bank {
    std::map<std::string, std::shared_ptr<Client>> clients;
    std::map<int, std::shared_ptr<Account>> accounts;

public:
    void addClient(std::shared_ptr<Client> client) {
        this->clients[client->id] = client;
    }

    void depositValue(int accountId, float value) {
        auto account = std::find_if(this->accounts.begin(), this->accounts.end(),
            [&accountId](std::shared_ptr<Account> account) {
                return account->getId() == accountId;
            });
        if (account == this->accounts.end()) {
            std::cout << "Account not found";
        }
        account->second->depositValue(value);
        std::cout << "Value deposited successfully";
    }

    void monthlyUpdate() {
        for (auto account : this->accounts) {
            account.second->monthlyUpdate();
        }
        std::cout << "Monthly update successful";
    }

    void transfer(int sendingAccount, int receivingAccount, float value) {
        accounts[sendingAccount]->transfer(*accounts[receivingAccount], value);
        std::cout << "Transfer successful";
    }

    void withdrawValues(int accountId, float value) {
        auto account = std::find_if(this->accounts.begin(), this->accounts.end(),
            [&accountId](std::shared_ptr<Account> account) {
                return account->getId() == accountId;
            });
        if (account == this->accounts.end()) {
            std::cout << "Account not found";
        }
        account->second->withdrawValue(value);
        std::cout << "Value withdrawn successfully";
    }
};