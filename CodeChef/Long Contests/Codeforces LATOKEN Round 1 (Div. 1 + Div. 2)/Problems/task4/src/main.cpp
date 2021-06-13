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
set<pair<int, int>> sol;

void answer() {
    cout << "!"
         << endl;
    for (auto &i : sol) {
        cout << i.first << " " << i.second << endl;
    }
}

int n;
vector<int> ask(int ind) {
    cout << "? " << ind << endl;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            sol.insert({min(ind, i), max(ind, i)});
        }
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    cin >> n;
    vector<int> a = ask(1);
    vector<int> odd, even;
    for (int i = 2; i <= n; ++i) {
        if (a[i] % 2) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }
    if (odd.size() > even.size()) {
        swap(odd, even);
    }
    // odd <= even
    for (auto &i : odd) {
        ask(i);
    }
    answer();
    return 0;
}
