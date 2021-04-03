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
        string s;
        cin >> s;
        string a, b;
        bool pos = true;
        int ca = 0, cb = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (ca == 0 && cb == 0) {
                    pos = false;
                    cout << "NO" << "\n";
                    break;
                } else {
                    if (ca >= cb) {
                        --ca, ++cb;
                        a.push_back(')');
                        b.push_back('(');
                    } else {
                        --cb, ++ca;
                        a.push_back('(');
                        b.push_back(')');
                    }
                }
            } else {
                if ((ca == 1 && cb == 1 && i != n - 1) || ca == 0 || cb == 0) {
                    ++ca, ++cb;
                    a.push_back('(');
                    b.push_back('(');
                } else {
                    --ca, --cb;
                    a.push_back(')');
                    b.push_back(')');
                }
            }
        }
        if (pos) {
            if (ca != 0 || cb != 0) {
                cout << "NO" << "\n";
            } else {
                cout << "YES" << "\n";
                cout << a << "\n";
                cout << b << "\n";
            }
        }
    }
    return 0;
}
