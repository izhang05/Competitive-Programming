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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        long long b;
        cin >> b;
        a[i] = __builtin_popcountll(b);
    }
    int sum = 0, even = 1, odd = 0;
    long long sol = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += a[i];
        if (sum % 2 == 0) {
            sol += even++;
        } else {
            sol += odd++;
        }
        int cur_sum = 0, mx = 0;
        for (int j = i; j - i < 65 && j < n; ++j) {
            cur_sum += a[j];
            mx = max(mx, a[j]);
            if (cur_sum - mx < mx && cur_sum % 2 == 0) {
                --sol;
            }
        }
    }
#ifdef DEBUG
    print(a);
#endif
    cout << sol << "\n";
    return 0;
}
