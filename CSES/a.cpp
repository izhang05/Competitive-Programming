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
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (a[0] >= a[1] + a[2]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> sol(n);
    sol[0] = a[0];
    int l = 1, r = n - 1, side = true;
    for (int i = 1; i < n; ++i) {
        if (side) {
            sol[l++] = a[i];
        } else {
            sol[r--] = a[i];
        }
        side ^= 1;
    }
    print(sol);
    return 0;
}
