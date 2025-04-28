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
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> q(m);
    vector<int> val(n);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first.first >> q[i].first.second >> q[i].second;
        --q[i].first.first, --q[i].first.second;
        for (int j = q[i].first.first; j < q[i].first.second + 1; ++j) {
            val[j] |= q[i].second;
        }
    }
    for (auto &i : q) {
        int cur = val[i.first.first];
        for (int j = i.first.first; j < i.first.second + 1; ++j) {
            cur &= val[j];
        }
        if (cur != i.second) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << val[i] << " \n"[i == n - 1];
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
