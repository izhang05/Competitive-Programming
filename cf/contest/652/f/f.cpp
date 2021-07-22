/* Author: izhang05
 * Time: 07-21-2021 23:34:13
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

int main() {
    setIO("2");

    long long n, m, t;
    cin >> n >> m >> t;
    vector<pair<long long, long long>> start(n);
    vector<long long> fin(n);
    long long shift = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        char c;
        cin >> x >> c;
        long long slope = c == 'L' ? -1 : 1, inter;
        if (slope == 1) {
            inter = 1 - x;
        } else {
            inter = x;
        }
        start[i] = {x, i};
        shift += ((t / m) % n) * slope;
        inter %= m;
        if (inter <= 0) {
            inter += m;
        }
        if (inter <= t % m) {
            shift += slope;
        }
        fin[i] = x + (t % m) * slope;
        fin[i] %= m;
        if (fin[i] <= 0) {
            fin[i] += m;
        }
    }
    sort(start.begin(), start.end());
    sort(fin.begin(), fin.end());
    shift %= n;
    if (shift < 0) {
        shift += n;
    }
    vector<long long> sol(n);
    for (int i = 0; i < n; ++i) {
        sol[start[i].second] = fin[(i + shift) % n];
    }
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
