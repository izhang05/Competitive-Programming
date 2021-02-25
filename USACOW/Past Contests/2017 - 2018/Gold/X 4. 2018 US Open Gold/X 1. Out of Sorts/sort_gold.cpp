/*
ID: izhang01
TASK: sort
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
}
//#define DEBUG
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    indexed_set<int> nums;
    for (int i = 0; i < n; ++i) {
        if (nums.order_of_key(a[i]) != nums.size()) {
            ++sol;
        }
        nums.insert(a[i]);
    }

    //    bool sorted =false;
    //    while (!sorted) {
    //        ++sol;
    //        sorted = true;
    ////        for (int i = 0; i < n - 1; ++i) {
    ////            if (a[i + 1] < a[i]) {
    ////                swap(a[i + 1], a[i]);
    ////            }
    ////        }
    //        for (int i = n - 2; i >= 0; --i) {
    //            if (a[i + 1] < a[i]) {
    //                swap(a[i + 1], a[i]);
    //            }
    //        }
    //        for (int i = 0; i < n - 1; ++i) {
    //            if (a[i + 1] < a[i]) {
    //                sorted = false;
    //            }
    //        }
    //    }
    cout << (sol + 1) / 2 << "\n";

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
