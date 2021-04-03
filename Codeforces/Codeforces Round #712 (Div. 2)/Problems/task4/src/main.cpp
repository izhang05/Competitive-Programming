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

int n;

pair<int, int> add(pair<int, int> x) {
    int par = (x.first + x.second) % 2;
    x.second += 2;
    if (x.second >= n) {
        ++x.first;
        x.second = (x.first + par) % 2;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    cin >> n;
    pair<int, int> even{0, 0}, odd{0, 1};
    for (int i = 0; i < n * n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            if (even.first < n) {
                cout << 2 << " " << even.first + 1 << " " << even.second + 1 << "\n";
                even = add(even);
            } else {
                cout << 3 << " " << odd.first + 1 << " " << odd.second + 1 << "\n";
                odd = add(odd);
            }
        } else if (a == 2) {
            if (odd.first < n) {
                cout << 1 << " " << odd.first + 1 << " " << odd.second + 1 << "\n";
                odd = add(odd);
            } else {
                cout << 3 << " " << even.first + 1 << " " << even.second + 1 << "\n";
                even = add(even);
            }
        } else if (a == 3) {
            if (odd.first < n) {
                cout << 1 << " " << odd.first + 1 << " " << odd.second + 1 << "\n";
                odd = add(odd);
            } else {
                cout << 2 << " " << even.first + 1 << " " << even.second + 1 << "\n";
                even = add(even);
            }
        }
        cout.flush();
    }
    return 0;
}
