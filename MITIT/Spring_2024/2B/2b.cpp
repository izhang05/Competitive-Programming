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

long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

int n;
vector<pair<int, int>> a;

long long sol = 0;

void gen(int i, vector<int> &cur) {
    if (i >= n) {
        set<int> s;
        int cur_v = 0;
        for (int j = 0; j < n; ++j) {
            cur_v += cur[j];
            s.insert(cur_v);
        }
        cur_v = 0;
        for (int j = n - 1; j >= 0; --j) {
            cur_v += cur[j];
            s.insert(cur_v);
        }
        sol += ((int) s.size() == 2 * n - 1);
        return;
    }
    for (int j = a[i].first; j <= a[i].second; ++j) {
        cur.push_back(j);
        gen(i + 1, cur);
        cur.pop_back();
    }
}

void test_case() {
    cin >> n;
    a.resize(n);
    int mx;
    cin >> mx >> mx;
    cout << (mx * binpow(mx - 1, n - 1, mod)) % mod << "\n";
    return;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> _;
    gen(0, _);
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
