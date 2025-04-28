/* Author: izhang
 * Time: 12-28-2024 09:34:03
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else

struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
    vector<int> pre(2 * n + 2);
    vector<pair<int, int>> a(n);
    map<int, int> seen;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first == a[i].second && seen[a[i].first] == 0) {
            pre[a[i].first] = 1;
        }
        if (a[i].first == a[i].second) {
            ++seen[a[i].first];
        }
    }
    dbg() << pre;
    for (int i = 1; i <= 2 * n; ++i) {
        pre[i] += pre[i - 1];
    }
    dbg() << pre;
    for (auto &i: a) {
        if (i.first == i.second) {
            cout << (seen[i.first] <= 1);
        } else {
            if (pre[i.second] - pre[i.first - 1] == i.second + 1 - i.first) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }
    cout << "\n";
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
