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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105, maxv = 200005;

bool dp[maxn][maxv];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    map<int, int> occ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        int cur = 1;
        int tmp = a[i];
        while (tmp % 2 == 0) {
            cur *= 2;
            tmp /= 2;
        }
        occ[cur] = i + 1;
        dp[i][a[i]] = true;
    }
    bool pos = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < maxv; ++j) {
            bool cur = dp[i][j];
            if (!cur) {
                continue;
            }
            if (j * 2 == sum) {
                pos = true;
                break;
            }
            dp[i + 1][j] = true;
            if (j + a[i + 1] < maxv) {
                dp[i + 1][j + a[i + 1]] = true;
            }
        }
    }
    if (!pos) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 2; i <= 4096; i *= 2) {
        if (occ.find(i / 2) != occ.end()) {
            cout << 1 << "\n";
            cout << occ[i / 2] << "\n";
            return 0;
        }
    }
    return 0;
}
