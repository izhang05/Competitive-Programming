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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;



int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int moves = 0;
        pair<int, int> eaten;
        int i = 0, j = n - 1, last = 0;
        bool turn = true;
        while (i <= j) {
            ++moves;
            int cur = 0;
            if (turn) {
                while (i <= j) {
                    cur += a[i++];
                    if (cur > last) {
                        break;
                    }
                }
                last = cur;
                eaten.first += cur;
            } else {
                while (j >= i) {
                    cur += a[j--];
                    if (cur > last) {
                        break;
                    }
                }
                last = cur;
                eaten.second += cur;
            }
            turn ^= 1;
        }
        cout << moves << " " << eaten.first << " " << eaten.second << "\n";
    }
    return 0;
}
