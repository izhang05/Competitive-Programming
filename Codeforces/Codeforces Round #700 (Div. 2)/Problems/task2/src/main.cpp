#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int power, health, n;
        cin >> power >> health >> n;
        vector<pair<int, int>> monsters(n); // attack power, health
        for (int i = 0; i < n; ++i) {
            cin >> monsters[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> monsters[i].second;
        }
        sort(monsters.begin(), monsters.end());
        bool sol = false;
        for (int i = 0; i < n; ++i) {
            while (monsters[i].second > 0 && health > 0) {
                health -= monsters[i].first;
                monsters[i].second -= power;
            }
            if (health < 0 && i != n - 1) {
                cout << "NO" << "\n";
                sol = true;
                break;
            }
        }
        if (!sol) {
            if (monsters[n - 1].second <= 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}
