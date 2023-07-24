/* Author: izhang
 * Time: 06-02-2023 16:00:02
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#include <ostream>
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

struct album {
    int k, c;
    vector<int> b, mx, cnt;
    explicit album(vector<int> &a) {
        k = (int) a.size();
        b = a;
        mx = a;
        c = 1;
        for (int i = 1; i < k; ++i) {
            mx[i] = max(mx[i], mx[i - 1]);
            if (mx[i] != mx[i - 1]) {
                ++c;
            }
        }
        cnt.resize(k);
        cnt[k - 1] = 1;
        for (int i = k - 2; i >= 0; --i) {
            cnt[i] = cnt[i + 1] + (mx[i] != mx[i + 1]);
        }
    }
    friend ostream &operator<<(ostream &os, const album &album) {
        os << "b:";
        for (auto &i : album.b) {
            os << " " << i;
        }
        os << "\n";
        os << "mx:";
        for (auto &i : album.mx) {
            os << " " << i;
        }
        os << "\n";
        os << "cnt:";
        for (auto &i : album.cnt) {
            os << " " << i;
        }
        os << "\n";
        return os;
    }
};

void test_case() {
    int n;
    cin >> n;
    vector<album> a;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<int> b(k);
        for (auto &j : b) {
            cin >> j;
        }
        a.emplace_back(b);
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.mx.back() < right.mx.back();
    });
    dbg() << a;
    vector<int> dp(n);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i].c;
        for (int j = 0; j < a[i].k; ++j) {
            if (j != 0 && a[i].mx[j - 1] == a[i].mx[j]) {
                continue;
            }
            int lo = 0, hi = i - 1, mid, mx = 0;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (a[mid].mx.back() < a[i].mx[j]) {
                    mx = max(mx, dp[mid]);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            dp[i] = max(dp[i], mx + a[i].cnt[j]);
        }
        sol = max(sol, dp[i]);
    }
    dbg() << dp;
    cout << sol << "\n";
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
