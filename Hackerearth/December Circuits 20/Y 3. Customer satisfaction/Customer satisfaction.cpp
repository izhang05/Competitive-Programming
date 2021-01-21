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
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        }
        sort(a.begin(), a.end(), [](pair<pair<int, int>, int> left, pair<pair<int, int>, int> right) {
            return left.first.second == right.first.second ? left.first.first < right.first.first : left.first.second < right.first.second;
        });
        long long sol = 0, books = 0;
        for (int i = 0; i < n; ++i) {
            books += a[i].second;
            while (i + 1 < n && a[i + 1].first.second == a[i].first.second) {
                books += a[++i].second;
            }
//            cout << a[i].first.second << " " << books << " " << sol << "\n";
            sol = max((books + a[i].first.second - 1) / a[i].first.second, sol);// ceil(books / a[i].first.second)
//            cout << a[i].first.second << " " << books << " " << sol << "\n";
//            cout << "\n";
        }
        cout << sol << "\n";
    }
    return 0;
}
