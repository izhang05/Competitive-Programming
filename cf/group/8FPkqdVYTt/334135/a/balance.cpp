/* Author: izhang05
 * Time: 10-23-2021 12:45:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

int main() {
    setIO("balance");
    // prob of element at index i getting to j (i < j) = (i + 1) / (j - i + i + 1) = (i + 1) / (j + 1)
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    vector<long double> expect(n);
    long double cur = f[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        cur *= (i + 1);
        cur /= (i + 2);
        expect[i] = cur;
        cur = max(cur, (long double) f[i]);
    }
    for (auto &i : expect) {
        cout << i << " ";
    }
    cout << "\n";

    reverse(f.begin(), f.end());
    cur = f[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        cur *= (i + 1);
        cur /= (i + 2);
        expect[n - i - 1] += cur;
        cur = max(cur, (long double) f[i]);
    }
    reverse(f.begin(), f.end());
    for (int i = 0; i < n; ++i) {
        expect[i] = max(expect[i], (long double) f[i]);
        cout << (long long) (1e5 * expect[i]) << "\n";
    }
    return 0;
}
