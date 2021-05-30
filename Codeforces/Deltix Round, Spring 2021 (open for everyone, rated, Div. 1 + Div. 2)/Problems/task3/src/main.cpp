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

void print(vector<int> a) {
    int n = (int) a.size();
    for (int i = 0; i < n - 1; ++i) {
        cout << a[i] << ".";
    }
    cout << a[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        stack<pair<int, vector<int>>> st;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 1) {
                while (!st.empty() && st.top().first != a[i] - 1) {
                    st.pop();
                }
            }
            if (st.empty()) {
                cout << a[i] << "\n";
                st.push({a[i], vector<int>{a[i]}});
            } else {
                pair<int, vector<int>> cur = st.top();
                st.pop();
                if (a[i] != 1) {
                    cur.second.pop_back();
                } else {
                    st.push(cur);
                }
                cur.first = a[i];
                cur.second.push_back(a[i]);
                st.push(cur);
                print(cur.second);
            }
        }
    }
    return 0;
}
