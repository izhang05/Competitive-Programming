#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, int> vals;
    bool good = true;
    for (int i = 0; i < m; ++i) {
        string s;
        int v;
        cin >> s >> v;
        if (vals.find(s) != vals.end() && vals[s] != v) {
            good = false;
        }
        vals[s] = v;
    }
    if (!good) {
        cout << "LIE\n";
        return;
    }
    while (!vals.empty()) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            map<int, set<int>> occ;
            for (auto &j : vals) {
                occ[j.first[i] - '0'].insert(j.second);
            }
            set<string> er;
            for (int j = 0; j < 2; ++j) {
                if (occ[j].size() == 1) {
                    found = true;
                    for (auto &k : vals) {
                        if (k.first[i] - '0' == j) {
                            er.insert(k.first);
                        }
                    }
                }
            }
            for (auto &j : er) {
                vals.erase(j);
            }
        }
        if (!found) {
            cout << "LIE\n";
            return;
        }
    }
    cout << "OK"
         << "\n";
}


int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
