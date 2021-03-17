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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;

int dp[maxn][maxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tag(n);
        for (int i = 0; i < n; ++i) {
            cin >> tag[i];
        }
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        for (int i = 0; i <n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
            dp[i][i] = 0;
        }
        for (int i = 0; i <n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (tag[i] == tag[j]) {
                    continue;
                }
                for (int k = 0; k < i; ++k) {
                    if (dp[j][k] == -1) {
                        continue;
                    }
                    dp[i][j] = max(dp[i][j], dp[j][k] + abs(s[j] - s[i]));
                }
            }
        }
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sol = max(sol, dp[i][j]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
