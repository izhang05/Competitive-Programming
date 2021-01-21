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
    freopen("1.in", "r", stdin);
}


int main() {
    setIO();
    vector<int> a;
    int b;
    while (cin >> b) {
        a.push_back(b);
    }
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[i] + a[j] + a[k] == 2020) {
                    cout << a[i] * a[j] * a[k] << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
