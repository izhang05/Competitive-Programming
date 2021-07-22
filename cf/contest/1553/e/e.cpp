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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), identity(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++identity[(a[i] - i + n) % n];
    }
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        if (identity[i] >= (n / 3)) {
            vector<int> visited(n, 0), ind_of(n);
            for (int j = 0; j < n; ++j) {
                ind_of[(j + i) % n] = j;
            }
            int cycles = 0;
            for (int j = 0; j < n; ++j) {
                int cur = j;
                if (!visited[cur]) {
                    ++cycles;
                }
                while (!visited[cur]) {
                    visited[cur] = true;
                    cur = ind_of[a[cur]];
                }
            }
            if (cycles >= n - m) {
                sol.push_back((n - i) % n);
            }
        }
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << " ";
    print(sol);
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
