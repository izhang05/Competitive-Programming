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

const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 1e6 + 5;

long long dp[maxn], max_div[maxn];

long long num_div(long long x) {
    long long div_num = 1;
    while (x != 1) {
        /*
         * get the largest prime that can divide x and see
         * how many times it goes into x (stored in count)
         */
        int prime = max_div[x];
        int count = 0;
        while (x % prime == 0) {
            count++;
            x /= prime;
        }
        div_num *= count + 1;
    }
    return div_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    for (int i = 2; i <= maxn; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= maxn; j += i) {
                max_div[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    dp[1] = 1;
    long long sum = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] += sum;
        dp[i] += num_div(i);
        dp[i] %= mod;
        sum += dp[i];
        sum %= mod;
    }
    cout << dp[n] << "\n";
    return 0;
}
