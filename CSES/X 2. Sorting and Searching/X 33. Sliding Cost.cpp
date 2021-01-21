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

const int maxn = 2e5 + 5;
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
    int k;
    cin >> n >> k;
    indexed_set<pair<int, int>> nums;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        nums.insert({a[i], i});
        if (m.find(a[i]) == m.end()) {
            m[a[i]] = i;
        }
        update(m[a[i]], query(m[a[i]], m[a[i]] + 1) + a[i]);
    }
    long long cost = 0;
    int med;
    med = nums.find_by_order((k - 1) / 2)->first;
    for (pair<int, int> i : nums) {
        cost += abs(i.first - med);
    }
    for (int i = k; i < n; ++i) {
        cout << cost << " ";
        cost -= med - nums.begin()->first;

        cin >> a[i];
        if (m.find(a[i]) == m.end()) {
            m[a[i]] = i;
        }
        nums.erase(nums.find({a[i - k], i - k}));
        nums.insert({a[i], i});
        med = nums.find_by_order((k - 1) / 2)->first;
        cost += nums.rbegin()->first - med;
    }
    cout << cost << "\n";
    return 0;
}