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

        void setIO() {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
        }
        const int mod = 1e9 + 7;

        int main() {
            setIO();

            int n, k, a;
            cin >> n >> k;
            vector<long long> dp(k + 1), diff(k + 1);
            dp[0] = 1;
            for (int i = 0; i < n; ++i) {
                cin >> a;
                for (int j = k; j >= 0; --j) {
                    int l = j + 1, r = j + min(a, k - j) + 1;
                    if (l < r) {
                        diff[l] += dp[j];
                        if (r <= k) {
                            diff[r] -= dp[j];
                        }
                    }
        //            for (int m = l; m < r; ++m) {
        //                dp[m] += dp[j];
        //            }
                }
                long long pre = 0;
                for (int j = 0; j < k + 1; ++j) {
                    pre += diff[j];
                    diff[j] = 0;
                    dp[j] += pre;
                    dp[j] %= mod;
                }
            }
            cout << dp[k] % mod << "\n";
            return 0;
        }
