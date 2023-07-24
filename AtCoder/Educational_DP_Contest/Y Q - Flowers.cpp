#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int maxn = 2e5 + 1;
int n;

long long t[2 * maxn];

long long calc(long long a, long long b) {
    return max(a, b);
}

void build() {
    for (int i = n - 1; i > 0; --i) {
        t[i] = calc(t[2 * i], t[2 * i + 1]);
    }
}

void update(int p, long long val) {
    for (t[p += n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
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
    cin >> n;
    vector<long long> dp(n + 1);
    vector<int> h(n + 1), a(n + 1); // max beauty of first i flowers
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int flower = 0; flower < n; ++flower) {
        long long best = query(1, h[flower]);
        dp[h[flower]] = best + a[flower];
        update(h[flower], dp[h[flower]]);

//        for (int i = 0; i < h[flower]; ++i) {
//            dp[h[flower]] = max(dp[h[flower]], dp[i] + a[flower]);
//        }
    }
//    print(dp);
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}

