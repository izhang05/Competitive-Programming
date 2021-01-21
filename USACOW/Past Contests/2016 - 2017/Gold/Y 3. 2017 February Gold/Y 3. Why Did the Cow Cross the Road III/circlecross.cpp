/*
ID: izhang01
TASK: circlecross
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
}
const int maxn = 5e5 + 1;
int vis[maxn];
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    setIO();
    int n;
    cin >> n;
    int a, sol = 0;
    indexed_set<int> nums;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a;
        if (!vis[a]) {
            vis[a] = i + 1;
            nums.insert(i);
        } else {
            sol += nums.order_of_key(i) - nums.order_of_key(vis[a] - 1) - 1;
            nums.erase(vis[a] - 1);
        }
    }
    cout << sol << "\n";
    return 0;
}
