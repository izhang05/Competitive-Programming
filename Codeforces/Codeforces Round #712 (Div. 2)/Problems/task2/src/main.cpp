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
        string tmpa, tmpb;
        cin >> tmpa >> tmpb;
        vector<int> a(n), b(n);
        vector<int> c(n);
        vector<bool> pos(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = tmpa[i] - '0';
            cnt += a[i];
            if (i % 2 == 1 && (i + 1) / 2 == cnt) {
                pos[i] = true;
            }
            b[i] = tmpb[i] - '0';
            c[i] = a[i] ^ b[i];
        }
        bool sol = true;
        int pre = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (c[i] != pre) {
                if (!pos[i]) {
                    cout << "NO" << "\n";
                    sol = false;
                    break;
                }
            }
            pre = c[i];
        }

        if (sol) {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
