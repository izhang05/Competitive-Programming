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
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxk = 6;
int dp[maxn][maxk];
bool is_prime[maxn];


int main() {
    setIO();
    for (bool &i : is_prime) {
        i = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i < maxn; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i < maxn; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            cout << i << "\n";
        }
    }
    dp[1][0] = 1;


//    for (long long k : primes) {
//        for (int i = 1; i < maxn; ++i) {
//            for (int j = 0; j < maxk - 1; ++j) {
//                if (!dp[i][j]) {
//                    continue;
//                }
//                if (i * k < maxn) {
//                    dp[i * k][j + 1] += dp[i][j];
//                } else {
//                    break;
//                }
//            }
//        }
//    }
//
//    int t;
//    cin >> t;
//    while (t--) {
//        int a, b, k;
//        cin >> a >> b >> k;
//        cout << dp[b][k] - dp[a - 1][k] << "\n";
//    }
    return 0;
}
