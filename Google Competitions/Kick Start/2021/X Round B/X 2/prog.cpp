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
    vector<int> a(n), b(n - 1);
    pair<int, int> last{-1, -1};
    vector<pair<int, int>> seg;
    map<int, int> ne, la;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i != 0) {
            b[i - 1] = a[i] - a[i - 1];
            if (last == make_pair(-1, -1)) {
                last = {b[i - 1], i - 1};
            } else {
                if (last.first != b[i - 1]) {
                    ne[last.second] = i - 2;
                    la[i - 2] = last.second;
                    seg.emplace_back(last.second, i - 2);
                    last = {b[i - 1], i - 1};
                }
            }
        }
    }
    seg.emplace_back(last.second, n - 2);
    ne[last.second] = n - 2;
    la[n - 2] = last.second;
    int sol = 0;
#ifdef DEBUG
    print(b);
    for (auto i : seg) {
        cout << i.first << " " << i.second << "\n";
    }

#endif
    for (auto i : seg) {
        sol = max(sol, i.second - i.first + 2);
        if (i.first >= 2) {
            int diff = b[i.first] - b[i.first - 1];
            if (b[i.first - 2] - diff == b[i.first]) {
                sol = max(sol, i.second - i.first + 3);
            }
        }
        if (i.second + 2 < n - 1) {
            int diff = b[i.second] - b[i.second + 1];
            if (b[i.second + 2] - diff == b[i.second]) {
                sol = max(sol, i.second - i.first + 3);
                if (i.second + 3 < n - 1 && b[i.second + 3] == b[i.second]) {
                    sol = max(sol, ne[i.second + 3] - i.first + 1);
                }
            }
        }
    }
    cout << min(n, sol + 1) << "\n";
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
