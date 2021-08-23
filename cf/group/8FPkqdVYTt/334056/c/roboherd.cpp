/* Author: izhang05
 * Time: 08-11-2021 14:57:22
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
const int maxn = 1e5 + 5;
int n, k, cnt = 0;
long long cur_sol;
vector<int> diff;
vector<vector<int>> a;

void gen(int x, long long rem) {
    cout << x << " " << rem << endl;
    if (cnt >= k) {
        return;
    }
    if (x == -1) {
        cur_sol -= rem;
        ++cnt;
        return;
    }
    if (diff[x] > rem) {
        x = upper_bound(diff.begin(), diff.end(), rem) - diff.begin() - 1;
    }
    if (x == -1) {
        cur_sol -= rem;
        ++cnt;
        return;
    }
    gen(x - 1, rem);
    for (int i = 0; i < (int) a[x].size() && rem - a[x][i] >= 0 && cnt < k; ++i) {
        gen(x - 1, rem - a[x][i]);
    }
}

int main() {
    setIO("roboherd");
    cin >> n >> k;
    diff.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        if (m == 1) {
            a[i].push_back(a[i][0]);
            a[i].push_back(-1);
        }
        diff[i] = a[i][1] - a[i][0];
    }
    sort(diff.begin(), diff.end());
    sort(a.begin(), a.end(), [](vector<int> left, vector<int> right) {
        return left[1] - left[0] < right[1] - right[0];
    });
    for (auto &i : a) {
        if (i.size() == 3 && i[2] == -1) {
            i.pop_back();
            i.pop_back();
        }
    }
    long long lo = 0, hi = 1e14, mid, sol;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        cout << mid << endl;
        cnt = 0;
        cur_sol = mid * k;
        gen(n - 1, mid);
        if (cnt >= k) {
            hi = mid - 1;
            sol = cur_sol;
        } else {
            lo = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
