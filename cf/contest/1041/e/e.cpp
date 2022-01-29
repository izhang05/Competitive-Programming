/* Author: izhang
 * Time: 01-28-2022 21:57:55
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
    map<int, int, greater<>> cnt;
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        if (max(b, c) != n - 1 || b == c) {
            cout << "NO"
                 << "\n";
            return;
        }
        ++cnt[min(b, c)];
    }
    vector<pair<int, int>> sol;
    set<int> unused;
    for (int i = 0; i < n - 1; ++i) {
        if (cnt.find(i) == cnt.end()) {
            unused.insert(i);
        }
    }
    for (auto &i : cnt) {
        int pre = n - 1;
        for (int j = 0; j < i.second - 1; ++j) {
            auto it = unused.lower_bound(i.first);
            if (it == unused.begin()) {
                cout << "NO"
                     << "\n";
                return;
            }
            it = prev(it);
            sol.emplace_back(pre, *it);
            pre = *it;
            unused.erase(it);
        }
        sol.emplace_back(pre, i.first);
    }

    cout << "YES"
         << "\n";
    for (auto &i : sol) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
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
