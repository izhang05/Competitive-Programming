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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long cost(int x) {
    if (x == 0) {
        return 1;
    }
    if (x == 1) {
        return 0;
    }
    return (1 << (__lg(x - 1) + 1)) - x;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    vector<int> b;
    for (auto &i : cnt) {
        b.push_back(i.second);
    }
    int m = int(b.size());
    vector<int> pre(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + b[i - 1];
    }
    long long sol = INFL;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < maxs; ++j) {
            long long cur = cost(pre[i]);
            auto it = prev(upper_bound(pre.begin(), pre.end(), pre[i] + (1 << j)));
            cur += cost(*it - pre[i]) + cost(pre[m] - *it);
            sol = min(sol, cur);
        }
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
