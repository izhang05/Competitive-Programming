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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    map<char, int> occ;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            sol += a[i] + a[n - i - 1];
        } else {
            sol += max(a[i], a[n - i - 1]);
            ++occ[s[i]];
        }
    }
    int total = 0;
    pair<int, char> mx;
    for (auto &i : occ) {
        total += i.second;
        mx = max(mx, {i.second, i.first});
    }
    mx.first *= 2;
    mx.first -= total;
    priority_queue<int, vector<int>, greater<>> unused;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1] && s[i] != mx.second && s[n - i - 1] != mx.second) {
#ifdef DEBUG
            cout << s[i] << " " << min(a[i], a[n - i - 1]) << "\n";
#endif
            unused.push(min(a[i], a[n - i - 1]));
        }
    }
    for (int i = 0; i < mx.first; ++i) {
        sol -= unused.top();
        unused.pop();
    }
    cout << sol << "\n";
    return 0;
}
