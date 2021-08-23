#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

void solve() {
    string s;
    cin >> s;
    int n = int(s.size());
    map<char, int> occ;
    int mx_occ = 0;
    for (auto &i : s) {
        ++occ[i];
        mx_occ = max(mx_occ, occ[i]);
    }
    if (mx_occ > n / 2) {
        cout << "IMPOSSIBLE"
             << "\n";
        return;
    }
    vector<pair<int, char>> let;
    for (auto &i : occ) {
        let.emplace_back(i.second, i.first);
    }
    sort(let.begin(), let.end());
    reverse(let.begin(), let.end());
    vector<int> order;
    for (auto &i : let) {
        for (int j = 0; j < n; ++j) {
            if (s[j] == i.second) {
                order.push_back(j);
            }
        }
    }
    string sol;
    for (int i = 0; i < n; ++i) {
        sol.push_back(' ');
    }
    int j = 0;
    for (int i = 1; i < int(let.size()); ++i) {
        for (int k = 0; k < let[i].first; ++k) {
            sol[order[j++]] = let[i].second;
        }
    }
    for (; j < n; j++) {
        sol[order[j]] = let[0].second;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
