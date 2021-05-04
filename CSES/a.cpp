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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 20;


int main() {
    setIO("1");

    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < maxn; ++j) {
            if (a & (1 << j)) {
                ++cnt[j];
            }
        }
    }
#ifdef DEBUG
    for (auto &i : cnt) {
        cout << i.first << " " << i.second << "\n";
    }
#endif
    long long sol = 0;
    while (!cnt.empty()) {
        long long cur = 0;
        vector<int> er;
        for (auto &i : cnt) {
            cur += (1 << i.first);
            --i.second;
            if (!i.second) {
                er.push_back(i.first);
            }
        }
        for (auto &i : er) {
            cnt.erase(i);
        }

        sol += cur * cur;
#ifdef DEBUG
        cout << cur << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}
