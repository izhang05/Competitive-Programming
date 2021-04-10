#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
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
    int n;
    cin >> n;
    vector<string> mid;
    string pre, suf;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool found = false;
        string cur;
        for (auto j : s) {
            if (j != '*') {
                cur += j;
            } else {
                if (found) {
                    mid.push_back(cur);
                } else {
                    found = true;
                    if (cur.size() > pre.size()) {
                        swap(cur, pre);
                    }
                    for (int k = 0; k < (int) cur.size(); ++k) {
                        if (cur[k] != pre[k]) {
                            cout << "*\n";
                            return;
                        }
                    }
                }
                cur = "";
            }
        }
        reverse(cur.begin(), cur.end());
        if (cur.size() > suf.size()) {
            swap(cur, suf);
        }
        for (int j = 0; j < (int) cur.size(); ++j) {
            if (cur[j] != suf[j]) {
                cout << "*\n";
                return;
            }
        }
    }
    cout << pre;
    print(mid, "", "");
    reverse(suf.begin(), suf.end());
    cout << suf << "\n";
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
