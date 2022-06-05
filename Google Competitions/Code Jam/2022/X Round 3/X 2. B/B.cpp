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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i].first >> c[i].second;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> cnt;
        int bad = 0;
        for (int j = 0, pos = i; j < n - 1; ++j, ++pos) {
            if (pos >= n) {
                pos %= n;
            }
            ++cnt[a[pos]];
            if (cnt[a[pos]] < c[a[pos]].first && cnt[a[pos]] == 1) {
                ++bad;
            } else if (cnt[a[pos]] == c[a[pos]].first && c[a[pos]].first != 1) {
                --bad;
            }
            if (cnt[a[pos]] > c[a[pos]].second) {
                break;
            }
            if (j >= 1 && !bad) {
                dbg() << i << " " << j;
                ++sol;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        dbg() << imie(i);
        cout << "Case #" << i << ": ";
        test_case();
    }
}
