/*
ID: izhang01
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    string comet, group;
    long long comet_value = 1, group_value = 1;
    fin >> comet;
    fin >> group;

    for (char letter : comet) {
        comet_value *= letter - 'A' + 1;
    }
    for (char letter : group) {
        group_value *= letter - 'A' + 1;
    }

    if (comet_value % 47 == group_value % 47) {
        fout << "GO" << "\n";
    } else {
        fout << "STAY" << "\n";
    }

    return 0;
}