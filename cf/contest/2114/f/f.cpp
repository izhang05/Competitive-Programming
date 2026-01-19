/* Author: izhang
 * Time: 06-08-2025 18:56:12
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e6 + 5;

const long long INFL = 0x3f3f3f3f3f3f3f3f;

int prime[mxn], k;

map<int, int> fact(int x) {
    map<int, int> res;
    while (x > 1) {
        ++res[prime[x]];
        x /= prime[x];
    }
    return res;
}

int solve(map<int, int> &f) {
    int res = 0;
    while (!f.empty()) {
        int cur = 1;
        while (true) {
            auto it = f.upper_bound(k / cur);
            if (it == f.begin()) {
                break;
            }
            it = prev(it);
            cur *= it->first;
            if (--it->second == 0) {
                f.erase(it);
            }
        }
        ++res;
    }
    return res;
}

void test_case() {
    int x, y;
    cin >> x >> y >> k;
    
    map<int, int> fx = fact(x), fy = fact(y);
    map<int, int> dx, dy;
    for (auto &i: fx) {
        if (i.second > fy[i.first]) {
            if (i.first > k) {
                cout << -1 << "\n";
                return;
            }
            dx[i.first] = i.second - fy[i.first];
        }
    }
    for (auto &i: fy) {
        if (i.second > fx[i.first]) {
            if (i.first > k) {
                cout << -1 << "\n";
                return;
            }
            dy[i.first] = i.second - fx[i.first];
        }
    }
    cout << solve(dx) + solve(dy) << "\n";
}

int main() {
    setIO("1");

    memset(prime, -1, sizeof(prime));
    for (int i = 2; i < mxn; ++i) {
        if (prime[i] == -1) {
            prime[i] = i;
            for (int j = i + i; j < mxn; j += i) {
                prime[j] = i;
            }
        }
    }

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
