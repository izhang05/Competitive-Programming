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
int t[2 * maxn], n;

void build() {
    for (int i = n - 1; i > 0; --i) {
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }
}

void upd(int p, int v) {
    for (t[p += n] = v; p > 1; p /= 2) {
        t[p / 2] = max(t[p], t[p ^ 1]);
    }
}

int que(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = max(res, t[l++]);
        }
        if (r & 1) {
            res = max(res, t[--r]);
        }
    }
    return res;
}


int main() {
    setIO();

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> t[n + i];
    }
    build();
    int r;
    for (int i = 0; i < m; ++i) {
        cin >> r;
        int l = 0, h = n - 1, mid, sol = -1;
        while (l <= h) {
            mid = (l + h) / 2;
            if (que(0, mid + 1) >= r) {
                sol = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (sol != -1) {
            upd(sol, t[sol + n] - r);
        }
        cout << sol + 1 << " ";
    }
    cout << "\n";
    return 0;
}
