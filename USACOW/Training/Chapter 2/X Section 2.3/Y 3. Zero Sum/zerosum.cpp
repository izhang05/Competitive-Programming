/*
ID: izhang01
TASK: zerosum
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    freopen("zerosum.out", "w", stderr);
}
//#define DEBUG

int main() {
    setIO();
    int n;
    cin >> n;
    vector<string> sol;
    for (int i = 0; i < (int) pow(3, n - 1) - 1; ++i) {
        int cur = 0, pre = 1, pre_op = 1;
        string cur_string = "1";
        int num = i;
        for (int j = 2; j <= n; ++j) {
            int op = num % 3;
            if (op == 0) {
                cur_string += '+';
                cur += pre * pre_op;
                pre = j, pre_op = 1;
            } else if (op == 1) {
                cur_string += '-';
                cur += pre * pre_op;
                pre = j, pre_op = -1;
            } else {
                cur_string += ' ';
                pre *= 10;
                pre += j;
            }
            num /= 3;
            cur_string += to_string(j);
        }
        cur += pre * pre_op;
        if (cur == 0) {
            sol.push_back(cur_string);
        }
    }
    sort(sol.begin(), sol.end());
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
