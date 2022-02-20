/* Author: izhang
 * Time: 02-20-2022 09:35:36
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, pair<int, int>>> mn_v(n);
    pair<int, int> cur_mx{a[n - 1], n - 1};
    set<pair<int, pair<int, int>>> mn;
    for (int i = n - 2; i >= 0; --i) {
        mn_v[i] = {a[i] - cur_mx.first, {i, cur_mx.second}};
        mn.insert(mn_v[i]);
        cur_mx = max(cur_mx, {a[i], i});
    }
    vector<array<int, 3>> sol;
    for (int i = 0; i < n - 2; ++i) {
        mn.erase(mn_v[i]);
        int nxt = mn.begin()->first;
        if (nxt < a[i]) {
            a[i] = nxt;
            sol.push_back({i, mn.begin()->second.first, mn.begin()->second.second});
        }
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        for (auto &j : i) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
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
