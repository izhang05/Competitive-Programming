#include <bits/stdc++.h>

using namespace std;

map<char, int> r{{'I', 1},
                 {'V', 5},
                 {'X', 10},
                 {'L', 50},
                 {'C', 100},
                 {'D', 500},
                 {'M', 1000}};


int r_to_n(const string &s) {
    int res = 0;
    int n = int(s.size());
    for (int i = 0; i < n; ++i) {
        if (i != n - 1 && r[s[i + 1]] > r[s[i]]) {
            res += r[s[i + 1]] - r[s[i]];
            ++i;
        } else {
            res += r[s[i]];
        }
    }
    return res;
}

int r_cnt(int x) {
    int res = x / 1000;
    x %= 1000;
    if (x >= 900) {
        res += 2;
    } else if (x >= 500) {
        res += x / 100 - 4;
    } else if (x >= 400) {
        res += 2;
    } else {
        res += x / 100;
    }
    x %= 100;

    if (x >= 90) {
        res += 2;
    } else if (x >= 50) {
        res += x / 10 - 4;
    } else if (x >= 40) {
        res += 2;
    } else {
        res += x / 10;
    }
    x %= 10;

    if (x == 9) {
        res += 2;
    } else if (x >= 5) {
        res += x - 4;
    } else if (x == 4) {
        res += 2;
    } else {
        res += x;
    }
    return res;
}

int main() {
    freopen("Y 89.in", "r", stdin);
    string s;
    int sol = 0;
    while (cin >> s) {
        sol += int(s.size()) - r_cnt(r_to_n(s));
    }
    cout << sol << "\n";
    return 0;
}
