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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].second;
    }
    map<int, int> has;
    for (int i = 0; i < n; ++i) {
        has.erase(i - 1);
        if (a[i].first != 0) {
            has[a[i].second] += a[i].first;
        }
        if (has.empty()) {
            cout << -1 << "\n";
            return;
        }
    }
    long double lo = 0, hi = 1e15, mid;
    while (hi - lo > 1e-10) {
        mid = (lo + hi) / 2;
        map<int, long double> has;
        bool pos = true;
        for (int i = 0; i < n && pos; ++i) {
            long double cur = mid * k;
            has.erase(i - 1);
            if (a[i].first != 0) {
                has[a[i].second] += a[i].first;
            }
            if (has.empty()) {
                pos = false;
                break;
            }
            auto it = has.begin();
            while (cur > 0) {
                if (it == has.end()) {
                    pos = false;
                    break;
                }
                if (it->second > cur) {
                    it->second -= cur;
                    cur = 0;
                } else {
                    cur -= it->second;
                    it = has.erase(it);
                }
            }
        }
        if (pos) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(30) << mid << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
