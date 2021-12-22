/* Author: izhang05
 * Time: 12-22-2021 15:57:58
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
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = *min_element(a.begin(), a.end()); i >= 1; --i) {
        vector<int> cur(n);
        int mx = 0, sum = 0;
        for (int j = 0; j < n; ++j) {
            cur[j] = a[j] - i;
            mx = max(mx, cur[j]);
            sum += cur[j];
        }
        if (sum - mx < mx) {
            continue;
        }
        int turns = sum / 2;
        cout << i << "\n";
        cout << turns << "\n";
        vector<vector<int>> sol(turns, vector<int>(n));
        int cur_ind = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < cur[j]; ++k) {
                sol[cur_ind][j] = true;
                cur_ind = (cur_ind + 1) % turns;
            }
        }
        for (auto &j : sol) {
            for (auto &k : j) {
                cout << k;
            }
            cout << "\n";
        }
        return;
    }
    cout << 0 << "\n";
    cout << 10000 << "\n";
    for (int i = 0; i < 10000; ++i) {
        vector<int> take(n, 0);
        int start = ((i / 5) * 5) % n;
        int cnt = 0;
        for (int j = start; cnt < 5; j = (j + 1) % n, ++cnt) {
            take[j] = true;
        }
        for (int j = 0; j < n; ++j) {
            cout << take[j];
        }
        cout << "\n";
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
