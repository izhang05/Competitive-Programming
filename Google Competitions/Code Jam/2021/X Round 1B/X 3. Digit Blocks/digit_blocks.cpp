#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
long long n, b, p;

void solve() {
    multiset<pair<int, int>> s;
    for (int i = 1; i < n + 1; ++i) {
        s.insert({0, i});
    }
    set<pair<int, int>> two;
    set<pair<int, int>> almost;
    for (int i = 0; i < n * b; ++i) {
        int a;
        cin >> a;
        if (a == -1) {
            return;
        }
        if ((almost.empty() && two.empty()) || (a < 8 && !s.empty())) {
            auto it = --s.end();
            if (it != s.begin() && a <= 1) {
                --it;
            }
            //            for (int j = 0; j < 2 * a && next(it) != s.end(); ++j) {
//                ++it;
//            }
            pair<int, int> cur = *it;
            s.erase(it);
            cout << cur.second << endl;
            if (cur.first + 1 < b - 2) {
                s.insert({cur.first + 1, cur.second});
            } else {
                if (cur.first + 1 == b - 2) {
                    two.insert({cur.first + 1, cur.second});
                } else {
                    almost.insert({cur.first + 1, cur.second});
                }
            }
        } else {
            if (almost.empty() || (a < 9 && !two.empty())) {
                auto it = two.begin();
                pair<int, int> cur = *it;
                two.erase(it);
                cout << cur.second << endl;
                almost.insert({cur.first + 1, cur.second});
            } else {
                auto it = almost.begin();
                pair<int, int> cur = *it;
                almost.erase(it);
                cout << cur.second << endl;
                //                if (cur.first + 1 < b) {
                //                    almost.insert({cur.first + 1, cur.second});
                //                }
            }
        }
    }
}

int main() {
    setIO("1");
    int t;
    cin >> t >> n >> b >> p;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}
