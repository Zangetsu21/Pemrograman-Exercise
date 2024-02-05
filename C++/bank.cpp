#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Bank {
private:
    int angka_accounts;
    map<string, int> transaction_counts;

public:
    Bank(int angka) {
        angka_accounts = angka;
    }

    void processTransactions() {
        for (int i = 0; i < angka_accounts; i++) {
            string account, transaction;
            cin >> account >> transaction;

            string key = account + " " + transaction;
            transaction_counts[key]++;
        }
    }

    void printAccountTransactionCounts() {
        vector<string> accounts;
        for (auto& [key, value] : transaction_counts) {
            accounts.push_back(key);
        }

        sort(accounts.begin(), accounts.end());

        for (auto& account : accounts) {
            cout << account << " " << transaction_counts[account] << endl;
        }
    }
};

int main() {
    int angka_testcases;
    cin >> angka_testcases;

    for (int i = 0; i < angka_testcases; i++) {
        int angka_accounts;
        cin >> angka_accounts;

        Bank transaction(angka_accounts);
        transaction.processTransactions();
        transaction.printAccountTransactionCounts();

        if (i < angka_testcases - 1) {
            cout << endl;
        }
    }
    return 0;
}