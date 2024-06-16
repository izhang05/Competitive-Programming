/* Author: izhang
 * Time: 06-09-2024 10:35:01
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

const long long m1 = 1e9 + 9, p = 9973;
const int maxn = 3e5 + 5;

long long pw[maxn]; // Stores the powers of p modulo m1
int n;
string s;
long long hsh[maxn];

void calc_hashes() {
    hsh[0] = 1;
    for (int i = 0; i < n; ++i) {
        hsh[i + 1] = ((hsh[i] * p) % m1 + s[i]) % m1;
    }
}

long long get_hash(int a, int b) { // [a, b]
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % m1 + m1) % m1;
}

void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
}

void test_case() {
    cin >> s;
    n = int(s.size());
    calc_hashes();
    long long sol = 0;
    vector<pair<int, int>> inter;
    int pre = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            if (pre == -1) {
                pre = i;
            }
        } else {
            if (pre != -1) {
                inter.emplace_back(pre, i);
            }
            pre = -1;
        }
    }
    if (pre != -1) {
        inter.emplace_back(pre, n);
    }
    if (inter.empty()) {
        cout << n - 1 << "\n";
        return;
    }
    inter.emplace_back(n, n);
    //    dbg() << inter;
    int m = int(inter.size());
    for (int i = 0; i < m; ++i) {
        for (int j = inter[i].first; j < inter[i].second; ++j) {
            long long cur_hsh = get_hash(inter[0].first, j);
            int cur_sz = j - inter[0].first + 1;
            int cur = j + 1;
            long long mn = inf;
            if (cur < n && s[cur] == 'a') {
                int nxt = lower_bound(inter.begin(), inter.end(), make_pair(cur, -1))->first;
                if (nxt != n) {
                    mn = min(mn, (long long) nxt - cur);
                }
                cur = nxt;
            } else if (cur < n && s[cur] != 'a') {
                mn = 0;
            }
            bool good = true;
            dbg() << inter[0].first << " " << cur << " " << n << " " << sol;
            while (cur != n) {
                if (cur + cur_sz > n || cur_hsh != get_hash(cur, cur + cur_sz - 1)) {
                    good = false;
                    break;
                }
                cur += cur_sz;
                if (cur < n && s[cur] == 'a') {
                    int nxt = lower_bound(inter.begin(), inter.end(), make_pair(cur, -1))->first;
                    if (nxt != n) {
                        mn = min(mn, (long long) nxt - cur);
                    }
                    cur = nxt;
                } else if (cur < n && s[cur] != 'a') {
                mn = 0;
            }
            }
            if (good) {
                ++sol;
                if (j == inter[i].second - 1) {
                    long long l = inter[0].first, r = n - inter[m - 2].second;
                    --sol;
                    for (int k = 0; k <= l; ++k) {
                        sol += max(0ll, 1 + min(r, mn - k));
                    }
                    //                    r = min(r, mn);
                    dbg() << j << " " << l << " " << r << " " << imie(mn);
                    //                    //                    for (long long k = 0; k <= l; ++k) {
                    //                    //                        sol += max(0ll, (1 + min(r, mn - k)));
                    //                    //                    }
                    //                    if (mn >= r) {
                    //                        sol += min(l + 1, (mn - r + 1)) * (r + 1);
                    ////                        dbg() << "add"
                    ////                              << " " << min(l + 1, (mn - r + 1)) * (r + 1);
                    //                    }
                    //                    if (l > mn - r) {
                    //                        long long nums = l - (mn - r + 1) + 1;
                    //                        sol += (r * (r + 1)) / 2;
                    //                        long long x = r - nums;
                    //                        if (x > 0) {
                    //                            sol -= (x * (x + 1)) / 2;
                    //                        }
                    //                    }
                }
            }
            //            for (auto &k : inter) {
            //                int sz = k.second - k.first;
            //                if (cur_size > sz || sz % cur_size != 0) {
            //                    good = false;
            //                }
            //            }
        }
    }

    cout << sol << "\n";
}

int main() {
    setIO("1");
    calc_pow();
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
