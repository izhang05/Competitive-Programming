#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    //#ifdef LOCAL
    //    freopen((name + ".in").c_str(), "r", stdin);
    //    freopen((name + ".out").c_str(), "w", stdout);
    //    freopen((name + ".out").c_str(), "w", stderr);
    //#endif
}

int n;

int ask(int l, int r) {//[l,r)
    cout << "M " << l + 1 << " " << r << endl;
    int res;
    cin >> res;
    return res - 1;
}

void sw(int l, int r) {
    ++l, ++r;
    cout << "S " << l << " " << r << endl;
    int res;
    cin >> res;
}

void solve() {
    for (int i = 0; i < n - 1; ++i) {
        int cur = ask(i, n);
        if (cur != i) {
            sw(i, cur);
        }
    }
    cout << "D" << endl;
    int res;
    cin >> res;
}

int main() {
    setIO("1");
    int t;
    cin >> t >> n;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}
