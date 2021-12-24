/* Author: izhang05
 * Time: 12-23-2021 20:40:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, long long>> adj[maxn];
long long diff[maxn];

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a, --b;
        diff[b] += c;
        diff[a] -= c;
    }
    vector<int> debt;
    vector<int> owe;
    for (int i = 0; i < n; ++i) {
        if (diff[i] == 0) {
            continue;
        }
        if (diff[i] < 0) {
            debt.push_back(i);
        } else {
            owe.push_back(i);
        }
    }
    int cnt = 0;
    for (auto &i : debt) {
        while (diff[i] != 0) {
            long long sub = min(-diff[i], diff[owe.back()]);
            adj[i].emplace_back(owe.back(), sub);
            ++cnt;
            diff[i] += sub;
            diff[owe.back()] -= sub;
            if (diff[owe.back()] == 0) {
                owe.pop_back();
            }
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            cout << i + 1 << " " << j.first + 1 << " " << j.second << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
