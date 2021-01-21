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

int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    indexed_multiset<int> left, right;
    int q;
    cin >> q;
    vector<vector<int>> queries(n, vector<int>(4));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        queries[i][3] = i;
    }
    sort(queries.begin(), queries.end(), [](vector<int> left, vector<int> right) {
        return left[1] == right[1] ? left[0] < right[0] : left[1] < right[1];
    });
    int i = 0, j = 0;
    left.insert(a[0]), right.insert(a[0]);
    vector<int> sol(q);
    for (vector<int> k : queries) {
        while (k[1] > j) {
            right.insert(a[++j]);
        }
        int num_right = right.size() - right.order_of_key(a[2]), num_left = left.size();
    }
    print(sol);
    return 0;
}
