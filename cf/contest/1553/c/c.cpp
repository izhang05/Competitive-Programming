/* Author: izhang05
 * Time: 07-22-2021 10:35:05
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string a, b;
        for (int i = 0; i < 10; i += 2) {
            a.push_back(s[i]);
        }
        for (int i = 1; i < 10; i += 2) {
            b.push_back(s[i]);
        }
        int goal_a = 0, goal_b = 0, kicks = 0, sol = 10;
        for (int i = 0; i < 5; ++i) {
            int rem = 5 - i;
            if (a[i] != '0') {
                ++goal_a;
            }
            ++kicks;
            if (goal_a - goal_b > rem) {
                sol = kicks;
                break;
            }
            if (goal_b - goal_a > rem - 1) {
                sol = kicks;
                break;
            }

            if (b[i] == '1') {
                ++goal_b;
            }
            ++kicks;
            --rem;
            if (abs(goal_a - goal_b) > rem) {
                sol = kicks;
                break;
            }
        }
        goal_a = 0, goal_b = 0, kicks = 0;
        for (int i = 0; i < 5; ++i) {
            int rem = 5 - i;
            if (a[i] == '1') {
                ++goal_a;
            }
            ++kicks;
            if (goal_a - goal_b > rem) {
                sol = min(sol, kicks);
                break;
            }
            if (goal_b - goal_a > rem - 1) {
                sol = min(sol, kicks);
                break;
            }

            if (b[i] != '0') {
                ++goal_b;
            }
            ++kicks;
            --rem;
            if (abs(goal_a - goal_b) > rem) {
                sol = min(sol, kicks);
                break;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
