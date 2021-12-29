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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("14");
    int n;
    cin >> n;
    vector<stack<int>> s(3);
    for (int i = n; i >= 1; --i) {
        s[0].push(i);
    }
    vector<pair<int, int>> sol;
    for (int i = 1;; ++i) {
        int disk = __builtin_ctz(i) + 1;
        if (disk > n) {
            break;
        }
        for (int j = 0; j < 3; ++j) {
            if (!s[j].empty() && s[j].top() == disk) {
                int nxt;
                if ((disk ^ n) & 1) {
                    nxt = (j + 1) % 3;
                } else {
                    nxt = (j - 1 + 3) % 3;
                }
                s[j].pop();
                s[nxt].push(disk);
                sol.emplace_back(j + 1, nxt + 1);
                break;
            }
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}
