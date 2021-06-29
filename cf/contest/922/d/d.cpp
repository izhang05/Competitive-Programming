/* Author: izhang05
 * Time: 06-29-2021 14:20:50
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct seg {
    string str;
    int s, h;
};

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<seg> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].str;
    }
    for (auto &i : a) {
        for (auto &j : i.str) {
            if (j == 's') {
                ++i.s;
            } else {
                ++i.h;
            }
        }
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        if (left.s == 0) {
            return false;
        } else if (right.s == 0) {
            return true;
        }
        return left.s * right.h > right.s * left.h;
    });
    string s;
    for (auto &i : a) {
        s += i.str;
    }
    long long sol = 0, cnt = 0;
    for (auto &i : s) {
        if (i == 's') {
            ++cnt;
        } else {
            sol += cnt;
        }
    }
    cout << sol << "\n";
    return 0;
}
