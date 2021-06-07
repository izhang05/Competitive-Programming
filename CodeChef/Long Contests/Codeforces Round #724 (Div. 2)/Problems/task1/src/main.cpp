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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        set<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
            nums.insert(a[i]);
        }
        int cnt = n;
        while (cnt <= 300) {
            int c = cnt;
            bool changed = false;
            for (int i = 0; i < c; ++i) {
                for (int j = i + 1; j < c; ++j) {
                    int cur = abs(a[i] - a[j]);
                    if (nums.find(cur) == nums.end()) {
                        nums.insert(cur);
                        ++cnt;
                        changed = true;
                        b.push_back(cur);
                        a.push_back(cur);
                    }
                }
            }
            if (!changed) {
                break;
            }
        }
        if (cnt > 300) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            cout << b.size() << "\n";
            print(b);
        }
    }
    return 0;
}
