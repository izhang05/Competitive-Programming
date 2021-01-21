/*
ID: izhang01
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int num_friends;
    fin >> num_friends;
    unordered_map<string, int> friends;
    string people[num_friends];
    int accounts[num_friends];

    for (int i = 0; i < num_friends; ++i) {
        string name;
        fin >> name;
        friends[name] = i;
        accounts[i] = 0;
        people[i] = name;
    }
    for (int i = 0; i < num_friends; ++i) {
        string giver;
        int amount_gifted, num_people_gifted, amount_per_person, giver_spent;
        fin >> giver;
        fin >> amount_gifted >> num_people_gifted;
        if (num_people_gifted == 0) {
            giver_spent = 0;
            amount_per_person = 0;
        } else {
            amount_per_person = amount_gifted / num_people_gifted;
            giver_spent = amount_gifted - amount_gifted % num_people_gifted;
        }
        string recipients[num_people_gifted];
        for (int j = 0; j < num_people_gifted; ++j) {
            fin >> recipients[j];
        }
        accounts[friends[giver]] -= giver_spent;
        for (const string &recipient : recipients) {
            accounts[friends[recipient]] += amount_per_person;
        }
    }
    for (string j : people) {
        fout << j + " " << accounts[friends[j]] << "\n";
    }
    return 0;
}