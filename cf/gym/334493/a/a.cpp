/* Author: izhang05
 * Time: 07-01-2021 15:36:33
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
}
const long double eps = 1e-12;
int main() {
    setIO("cowdate");
    int n;
    cin >> n;
    vector<long double> a(n);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] = (long double) b / (1e6);
    }
    long double sol = 0, mult = 1, sum = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (sum < 1 && j < n) {
            mult *= 1 - a[j];
            sum += a[j] / (1 - a[j]);
            ++j;
        }
        sol = max(sol, mult * sum);
        mult /= 1 - a[i];
        sum -= a[i] / (1 - a[i]);
    }
    cout << floor((sol - eps) * 1e6) << "\n";
    return 0;
}
