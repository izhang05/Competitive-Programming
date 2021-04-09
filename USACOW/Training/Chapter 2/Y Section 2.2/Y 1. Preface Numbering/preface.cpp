/*
ID: izhang01
TASK: preface
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
}
int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};


string sol(int number) {
    int i = 12;
    string res;
    while (number > 0) {
        int div = number / num[i];
        number = number % num[i];
        while (div--) {
            res += sym[i];
        }
        --i;
    }
    return res;
}

int main() {
    setIO();
    int n;
    cin >> n;
    map<char, int> s;
    for (int i = 1; i < n + 1; ++i) {
        string cur = sol(i);
        for (auto j : cur) {
            ++s[j];
        }
    }
    vector<char> letters{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (auto i : letters) {
        if (s[i] != 0) {
            cout << i << " " << s[i] << "\n";
        }
    }

    return 0;
}
