#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
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
const int mod = 1e9 + 7, maxn = 2e5 + 5;
int n;

long long t[2 * maxn];

long long calc(long long a, long long b) {
    return a + b;
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
    cin >> n;
    long long sol = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sorted_a(a.begin(), a.end());
    sort(sorted_a.begin(), sorted_a.end());
    map<int, int> ind;
    for (int i = 0; i < n; ++i) {
        ind[sorted_a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = ind[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        long long cur = 1 + query(0, a[i]);
        cur %= mod;
        sol += cur;
        update(a[i], cur + query(a[i], a[i] + 1));
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
