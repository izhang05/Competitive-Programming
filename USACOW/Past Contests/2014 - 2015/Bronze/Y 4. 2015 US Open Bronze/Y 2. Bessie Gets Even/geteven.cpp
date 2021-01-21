/*
ID: izhang01
TASK: geteven
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("geteven.in", "r", stdin);
    freopen("geteven.out", "w", stdout);
}


int main() {
#define int long long
    setIO();
    int n;
    cin >> n;
    map<char, vector<int> > values;
    for (char i : vector<char>{'B', 'E', 'S', 'I', 'G', 'O', 'M'}) {
        values[i] = vector<int>{};
    }
    char x;
    int y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        values[x].push_back(y);
    }

    int total = 1;
    for (auto i : values) {
        total *= (int) i.second.size();
    }
    int first = 0, second = 0, third = 0;
    for (int b : values['B']) {
        for (int i : values['I']) {
            first += (b + i) % 2 == 1;
        }
    }
    for (int g : values['G']) {
        for (int o : values['O']) {
            for (int e : values['E']) {
                for (int s : values['S']) {
                    second += (g + o + e + s) % 2 == 1;
                }
            }
        }
    }
    for (int m : values['M']) {
        third += m % 2 == 1;
    }
//    cout << total << " " << first << " " << second << " " << third << "\n";
    cout << total - (first * second * third) << "\n";
    return 0;
}
