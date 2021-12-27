/* Author: izhang05
 * Time: 12-26-2021 21:02:02
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

vector<int> solve(int l, int r) {
    vector<int> res;
    for (int i = l; i < r; i += 2) {
        res.push_back(i);
    }
    for (int i = r - 4; i >= l; i -= 2) {
        res.push_back(i);
    }
    return res;
}
void test_case() {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt += a[i];
    }
    if (cnt % 2) {
        cout << "NO\n";
        return;
    }
    vector<int> sol;
    if (n % 2) {
        sol = solve(1, n);
    } else {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += a[i];
            if (cur % 2 == 0 && i % 2 == 0) {
                sol = solve(1, i + 1);
                for (auto &j : solve(i + 2, n)) {
                    sol.push_back(j);
                }
                break;
            }
        }
    }
    if (sol.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("2");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
