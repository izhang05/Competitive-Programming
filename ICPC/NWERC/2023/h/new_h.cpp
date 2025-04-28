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
    int cnt_2 = 0, cnt_1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 2) {
            ++cnt_2;
        }
        if (a[i] == 1) {
            ++cnt_1;
        }
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 3) {
            sol.push_back(sym['*']);
            sol.push_back(a[i]);
        } else {
            if (a[i] == 2) {
                if (cnt_1) {
                    sol.push_back(sym['*']);
                    sol.push_back(sym['(']);
                    sol.push_back(2);
                    sol.push_back(sym['+']);
                    sol.push_back(1);
                    sol.push_back(sym[')']);
                    --cnt_1;
                } else {
                    sol.push_back(sym['*']);
                    sol.push_back(2);
                }
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < cnt_1 / 6; ++i) {
        for (int j = 0; j < 2; ++j) {
            sol.push_back(sym['*']);
            sol.push_back(sym['(']);
            sol.push_back(1);
            sol.push_back(sym['+']);
            sol.push_back(1);
            sol.push_back(sym['+']);
            sol.push_back(1);
            sol.push_back(sym[')']);
        }
    }
    cnt_1 %= 6;
    if (cnt_1 == 1) {
        if (sol.back() == sym[')']) {
            sol.pop_back();
            sol.push_back(sym['+']);
            sol.push_back(1);
            sol.push_back(sym[')']);
        } else {
            int cur = sol.back();
            sol.pop_back();
            sol.push_back(sym['(']);
            sol.push_back(cur);
            sol.push_back(sym['+']);
            sol.push_back(1);
            sol.push_back(sym[')']);
        }
    } else if (cnt_1 == 2) {
        sol.push_back(sym['*']);
        sol.push_back(sym['(']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym[')']);
    } else if (cnt_1 == 3) {
        sol.push_back(sym['*']);
        sol.push_back(sym['(']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym[')']);
    } else if (cnt_1 == 4) {
        sol.push_back(sym['*']);
        sol.push_back(sym['(']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym[')']);

        sol.push_back(sym['*']);
        sol.push_back(sym['(']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym[')']);
    } else if (cnt_1 == 5) {
        sol.push_back(sym['*']);
        sol.push_back(sym['(']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym[')']);

        sol.push_back(sym['*']);
        sol.push_back(sym['(']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym['+']);
        sol.push_back(1);
        sol.push_back(sym[')']);
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
