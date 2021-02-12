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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
int sol = 0;

pair<pair<string, string>, pair<string, string>> find_lcs(pair<string, string> s) {
    pair<int, string> best;
    string a = s.first, b = s.second;
    int n = a.size(), m = b.size();
    for (int i = 0; i < min(n, m); ++i) {
        string cur;
        for (int j = i; j < min(n, m); ++j) {
            if (a[j] == b[j]) {
                cur.push_back(a[j]);
            } else {
                best = max(best, {j - i, cur});
                break;
            }
        }
    }
    sol += best.first;
}

int main() {
    setIO();
    pair<string, string> s;
    cin >> s.first >> s.second;
    while (true) {
        pair<pair<string, string>, pair<string, string>> next = find_lcs(s);

        break;
    }
    cout << sol << "\n";
    return 0;
}
