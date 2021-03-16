#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
struct ring {
    int in, out, h;
    bool operator<(const ring &rhs) const {
        if (rhs.out == this->out) {
            return rhs.in < this->in;
        } else {
            return rhs.out < this->out;
        }
    }
};

int seg_n;
long long dp[maxn];

long long t[4 * maxn];

long long calc(long long a, long long b) {
    return max(a, b);
}


void update(int p, long long val) {
    for (t[p += seg_n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += seg_n, r += seg_n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<ring> a(n);
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].in >> a[i].out >> a[i].h;
        nums.insert(a[i].in), nums.insert(a[i].out);
    }
    map<int, int> ind;
    int cnt = 0;
    for (auto i : nums) {
        ind[i] = cnt++;
    }
    seg_n = nums.size();
    for (int i = 0; i < n; ++i) {
        a[i].in = ind[a[i].in];
        a[i].out = ind[a[i].out];
    }
    sort(a.begin(), a.end());
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << a[i].in << " " << a[i].out << " " << a[i].h << "\n";
    }
#endif
    for (int i = 0; i < n; ++i) {
        dp[i] = query(0, a[i].out) + a[i].h;
        update(a[i].in, dp[i]);
    }
#ifdef DEBUG
    cout << "dp: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";
#endif
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, dp[i]);
    }
    cout << sol << "\n";
    return 0;
}