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
    setIO("1");

    int n;
    cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        a.insert(num);
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        auto it = a.lower_bound(b[i]);
        if (it != a.end()) {
            a.erase(it);
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
