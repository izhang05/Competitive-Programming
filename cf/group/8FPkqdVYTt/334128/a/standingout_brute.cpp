/* Author: izhang05
 * Time: 08-21-2021 15:22:56
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

int main() {
    setIO("standingout");
    int n;
    cin >> n;
    map<string, int> cnt;
    vector<string> a(n);
    vector<map<string, int>> cur_cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < (int) a[i].size(); ++j) {
            for (int k = 1; k + j <= int(a[i].size()); ++k) {
                ++cnt[a[i].substr(j, k)];
                ++cur_cnt[i][a[i].substr(j, k)];
            }
        }
    }
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) a[i].size(); ++j) {
            for (int k = 1; k + j <= int(a[i].size()); ++k) {
                string sub = a[i].substr(j, k);
                if (cur_cnt[i][sub] - cnt[sub] == 0) {
                    ++sol[i];
                    ++cur_cnt[i][sub];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
