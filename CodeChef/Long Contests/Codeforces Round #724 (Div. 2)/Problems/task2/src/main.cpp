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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> occ;
    for (int i = 0; i < n; ++i) {
        string cur;
        cur.push_back(s[i]);
        occ.insert(cur);
        for (int j = i + 1; j < i + 3 && j < n; ++j) {
            cur.push_back(s[j]);
            occ.insert(cur);
        }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        string cur;
        cur.push_back(i);
        if (occ.find(cur) == occ.end()) {
            cout << cur << "\n";
            return;
        }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            string cur;
            cur.push_back(i);
            cur.push_back(j);
            if (occ.find(cur) == occ.end()) {
                cout << cur << "\n";
                return;
            }
        }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            for (char k = 'a'; k <= 'z'; ++k) {
                string cur;
                cur.push_back(i);
                cur.push_back(j);
                cur.push_back(k);
                if (occ.find(cur) == occ.end()) {
                    cout << cur << "\n";
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
