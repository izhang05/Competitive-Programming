#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    string s;
    cin >> s;
    map<char, int> c;
    for (char i : s) {
        if (c.find(i) != c.end()) {
            ++c[i];
        } else {
            c[i] = 1;
        }
    }
    bool odd = false;
    for (auto i : c) {
        if (i.second % 2 == 1) {
            if (odd) {
                cout << "NO SOLUTION" << "\n";
                return 0;
            } else {
                odd = true;
            }
        }
    }
    string sol;
    for (auto i : c) {
        if (i.second % 2 == 0) {
            for (int j = 0; j < i.second / 2; ++j) {
                sol += i.first;
            }
        }
    }
    cout << sol;
    for (auto i : c) {
        if (i.second % 2 == 1) {
            for (int j = 0; j < i.second; ++j) {
                cout << i.first;
            }
        }
    }
    reverse(sol.begin(), sol.end());
    cout << sol << "\n";
    return 0;
}
