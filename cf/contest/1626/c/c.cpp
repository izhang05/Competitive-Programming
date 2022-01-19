/* Author: izhang
 * Time: 01-16-2022 09:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long tri(long long x) {
    return (x * (x + 1)) / 2;
}

void test_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &i : a) {
        cin >> i.first;
    }
    for (auto &i : a) {
        cin >> i.second;
    }
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i].first - a[i].second + 1, a[i].first};
    }
    sort(b.begin(), b.end());
    vector<pair<int, int>> c;
    pair<int, int> pre = b[0];
    for (int i = 1; i < n; ++i) {
        if (b[i].first <= pre.second) {
            pre.second = max(pre.second, b[i].second);
        } else {
            c.push_back(pre);
            pre = b[i];
        }
    }
    c.push_back(pre);
    long long sol = 0;
    for (auto &i : c) {
        sol += tri(i.second - i.first + 1);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
