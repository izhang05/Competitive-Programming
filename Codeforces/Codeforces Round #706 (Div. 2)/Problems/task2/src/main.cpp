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
        int n, k;
        cin >> n >> k;
        set<int> nums;
        int maxim = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            maxim = max(maxim, a);
            nums.insert(a);
        }
        int mex = 0;
        for (int i = 0; i < n + 1; ++i) {
            if (nums.find(i) == nums.end()) {
                mex = i;
                break;
            }
        }
        if (mex == n) {
            cout << nums.size() + k << "\n";
        } else {
            if (nums.find((mex + maxim + 1) / 2) == nums.end() && k >= 1) {
                cout << nums.size() + 1 << "\n";
            } else {
                cout << nums.size() << "\n";
            }
        }
    }
    return 0;
}
