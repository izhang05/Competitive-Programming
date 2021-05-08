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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        multiset<int> lef;
        for (int i = 0; i < l; ++i) {
            int a;
            cin >> a;
            lef.insert(a);
        }
        multiset<int> rig;
        for (int i = 0; i < r; ++i) {
            int a;
            cin >> a;
            auto it = lef.find(a);
            if (it != lef.end()) {
                lef.erase(it);
            } else {
                rig.insert(a);
            }
        }
        l = (int) lef.size();
        r = (int) rig.size();
        if (l > r) {
            swap(l, r);
            swap(lef, rig);
        }
        // r >= l
        map<int, int> cnt;
        for (auto i : rig) {
            ++cnt[i];
        }
        priority_queue<int> occ;
        for (auto i : cnt) {
            occ.push(i.second);
        }
        int sol = 0;
        while (r > l) {
            int cur = occ.top();
            occ.pop();
            if (cur >= 2) {
                r -= 2;
                occ.push(cur - 2);
            } else {
                --r;
                ++l;
                occ.push(cur - 1);
            }
            ++sol;
        }
        cout << sol + l << "\n";
    }
    return 0;
}
