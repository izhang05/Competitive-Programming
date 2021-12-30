/* Author: izhang05
 * Time: 12-30-2021 15:40:30
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
long long bit[maxn];

void upd(int ind, long long val) {
    for (; ind < n; ind = ind | (ind + 1)) {
        bit[ind] += val;
    }
}

long long qry(int ind) {
    long long res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        res += bit[ind];
    }
    return res;
}

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        upd(i, 0);
    }
    string a, b;
    cin >> a >> b;
    string cp(a.begin(), a.end());
    sort(cp.begin(), cp.end());
    if (cp <= b) {
        cout << -1 << "\n";
        return;
    }
    indexed_set<pair<char, int>> ch;
    for (int i = 0; i < n; ++i) {
        ch.insert({a[i], i});
    }
    long long sol = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        auto it = ch.lower_bound({b[i], -inf});
        if (it != ch.begin()) {
            sol = min(sol, cur + prev(it)->second - i + qry(n - 1) - qry(it->second - 1) - 1);
        }
        if (it == ch.end()) {
            break;
        }



        ch.erase(it);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
