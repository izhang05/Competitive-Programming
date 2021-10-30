/* Author: izhang05
 * Time: 10-30-2021 10:35:02
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

int n;
vector<int> a;
bool sol;

void gen(vector<int> cur, set<int> unused) {
    if (!cur.empty()) {
        unused.erase(cur.back());
    }
    if (unused.empty()) {
        vector<bool> rem(n);
        int good = true;
        for (auto &i : cur) {
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                cnt += rem[j];
            }
            if (a[i] % (i + 2 - cnt) == 0) {
                good = false;
                break;
            }
            rem[i] = true;
        }
        if (good) {
            sol = true;
        }
        return;
    }

    for (auto &i : unused) {
        cur.push_back(i);
        gen(cur, unused);
        cur.pop_back();
        if (sol) {
            return;
        }
    }
}

void solve() {
    sol = false;
    cin >> n;
    a.resize(n);
    set<int> unused;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        unused.insert(i);
    }
    gen(vector<int>{}, unused);
    cout << (sol ? "YES" : "NO") << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
