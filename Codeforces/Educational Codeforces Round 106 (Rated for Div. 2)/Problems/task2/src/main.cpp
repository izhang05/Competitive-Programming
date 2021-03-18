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
        string s;
        cin >> s;
        int n = s.size();
        bool pos = false;
        for (int i = 0; i < n + 1; ++i) {
            //indices >= i are 1
            bool cur = true;
            char pre = s[0];
            for (int j = 1; j < i; ++j) {
                if (s[j] == '1' && pre == '1') {
                    cur = false;
                    break;
                }
                pre = s[j];
            }
            if (!cur) {
                break;
            }
            pre = s[i];
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == '0' && pre == '0') {
                    cur = false;
                    break;
                }
                pre = s[j];
            }
            if (cur) {
                pos = true;
                break;
            }
        }

        if (pos) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
