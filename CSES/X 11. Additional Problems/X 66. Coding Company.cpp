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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

// dp[i][j][k] = The number of ways we can form teams from the first i people such that there are j "unfinished" teams and the total penalty so far is k.

int main() {
    setIO();

    // start a new team with i
    // dp[i + 1][j - 1][k] = dp[i][j][k]

    //
    int n, x;
    cin >> n >> x;


    return 0;
}
