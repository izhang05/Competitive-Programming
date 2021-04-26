#include <bits/stdc++.h>

using namespace std;

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
int n, a, b;

bool pos(int x, vector<int> c) {
#ifdef DEBUG
    cout << x << ":\n";
#endif
    queue<int> rem;
    rem.push(x);
    while (!rem.empty()) {
        int cur = rem.front();
        rem.pop();
#ifdef DEBUG
        cout << cur << "\n";
#endif
        if (cur - a > 0) {
            if (cur - a <= n && c[cur - a]) {
                --c[cur - a];
            } else {
                rem.push(cur - a);
            }
        }
        if (cur - b > 0) {
            if (cur - b <= n && c[cur - b]) {
                --c[cur - b];
            } else {
                rem.push(cur - b);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
#ifdef DEBUG
        cout << i << " " << c[i] << "\n";
#endif
        if (c[i] != 0) {
            return false;
        }
    }

    return true;
}

void solve() {
    cin >> n >> a >> b;
    vector<int> u(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> u[i];
    }
    for (int i = n + 1;; ++i) {
        cout << i << endl;
        if (pos(i, u)) {
            cout << i << "\n";
            return;
        }
    }
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
