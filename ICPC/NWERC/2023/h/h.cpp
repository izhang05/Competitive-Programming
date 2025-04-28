#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<char> rev_sym{'(', '+', '*', ')'};
    map<char, int> sym = {{'(', 0},
                          {'+', -1},
                          {'*', -2},
                          {')', -3}};
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> sol;
    bool cur = false, last = false;
    int pre_val = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 1) {
            if (!cur) {
                sol.push_back(sym['*']);
                sol.push_back(a[i]);
            } else {
                if (a[i] >= pre_val) {
                    sol.push_back(sym['*']);
                    sol.push_back(sym['(']);
                    sol.push_back(1);
                    sol.push_back(sym['+']);
                    sol.push_back(a[i]);
                    sol.push_back(sym[')']);
                } else {
                    sol.pop_back();
                    sol.push_back(sym['+']);
                    sol.push_back(1);
                    sol.push_back(sym[')']);
                    sol.push_back(sym['*']);
                    sol.push_back(a[i]);
                }
            }
            last = false;
        } else {
            if (cur) {
                sol.push_back(sym['*']);
                sol.push_back(sym['(']);
                sol.push_back(1);
                sol.push_back(sym['+']);
                sol.push_back(1);
                sol.push_back(sym[')']);
                cur = false;
                last = true;
            } else {
                cur = true;
            }
        }
    }
    if (cur) {
        if (last) {
            sol.pop_back();
            sol.push_back(sym['+']);
            sol.push_back(1);
            sol.push_back(sym[')']);
        } else {
            sol.pop_back();
            sol.push_back(sym['(']);
            sol.push_back(a[n - 2]);
            sol.push_back(sym['+']);
            sol.push_back(1);
            sol.push_back(sym[')']);
        }
    }
    bool first = true;
    for (auto &i: sol) {
        if (i >= 1) {
            cout << i;
        } else {
            if (!first) {
                cout << rev_sym[-i];
            }
        }
        first = false;
    }
    cout << "\n";
    return 0;
}
