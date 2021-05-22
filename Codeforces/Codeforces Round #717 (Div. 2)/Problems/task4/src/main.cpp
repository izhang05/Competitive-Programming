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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;

set<int> factor(int x) {
    set<int> res;
    while (x % 2 == 0) {
        res.insert(2);
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            res.insert(i);
            x /= i;
        }
    }
    if (x > 1) {
        res.insert(x);
    }
    return res;
}

int up[maxn][maxs], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
        if (x == n) {
            break;
        }
    }
    return x;
}

int solve(int x, int r) {
    int res = 0;
    for (int i = maxs - 1; i >= 0; i--) {
        if (up[x][i] <= r) {
            x = up[x][i];
            res += 1 << i;
        }
    }
    return res + 1;
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == n) {
                up[j][i] = n;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> last;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        set<int> cur = factor(a[i]);
        for (auto &j : cur) {
            if (last.find(j) != last.end() && !up[last[j]][0]) {
                up[last[j]][0] = i;
            }
            last[j] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!up[i][0]) {
            up[i][0] = n;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        up[i][0] = min(up[i][0], up[i + 1][0]);
    }
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << solve(l, r) << "\n";
    }
    return 0;
}

