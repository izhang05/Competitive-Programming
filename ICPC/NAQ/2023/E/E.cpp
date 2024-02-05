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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
    }
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; ++i) {
        r[i].first = inf, r[i].second = -inf;
        for (int j = a[i].first; j <= a[i].second; ++j) {
            if (i >= a[j].first && i <= a[j].second) {
                r[i].first = min(r[i].first, j);
                r[i].second = max(r[i].first, j);
            }
        }
    }
//    dbg() << r;
    vector<int> avail(n, 1);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> cur;
        if (!avail[i]) {
            continue;
        }
        for (int j = i + 1; j <= r[i].second; ++j) {
            if (avail[j] && j != i) {
                cur.push_back(j);
            }
            if (int(cur.size()) >= 2) {
                break;
            }
        }
        if ((int) cur.size() == 2) {
//            dbg() << i << " " << cur;
            ++sol;
            avail[i] = false;
            for (auto &j: cur) {
                avail[j] = false;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
