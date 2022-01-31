/* Author: izhang
 * Time: 01-31-2022 13:36:31
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 30;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> res(maxs);
    for (int i = 0; i < maxs; ++i) {
        sort(a.begin(), a.end(), [&i](auto left, auto right) {
            return left % (1 << i) < right % (1 << i);
        });
        deque<int> set, unset;
        vector<int> m(n);
        for (int j = 0; j < n; ++j) {
            m[j] = a[j] % (1 << i);
            if (a[j] & (1 << i)) {
                set.push_back(m[j]);
            } else {
                unset.push_back(m[j]);
            }
        }
        for (int j = 0; j < int(set.size()) - 1; ++j) {
            assert(set[j] <= set[j + 1]);
        }
        for (int j = 0; j < int(unset.size()) - 1; ++j) {
            assert(unset[j] <= unset[j + 1]);
        }

        for (int j = 0; j < n; ++j) {
            if (a[j] & (1 << i)) {
                set.pop_front();
                res[i] += max(0, int(lower_bound(unset.begin(), unset.end(), (1 << i) - m[j]) - unset.begin()));
                res[i] += max(0, int(set.end() - lower_bound(set.begin(), set.end(), (1 << i) - m[j])));
            } else {
                unset.pop_front();
                res[i] += max(0, int(lower_bound(set.begin(), set.end(), (1 << i) - m[j]) - set.begin()));
                res[i] += max(0, int(unset.end() - lower_bound(unset.begin(), unset.end(), (1 << i) - m[j])));
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < maxs; ++i) {
        if (res[i] % 2) {
            sol += 1 << i;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
