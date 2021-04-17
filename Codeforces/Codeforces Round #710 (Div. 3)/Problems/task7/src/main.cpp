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
set<char> used;
string s;

bool can(string t, char c) {
    set<char> cur(used.begin(), used.end());
    cur.erase(c);
    int j = 0, i = 0;
    if (!t.empty()) {
        for (; i < (int) s.size(); ++i) {
            if (s[i] == t[j]) {
                ++j;
                if (j >= (int) t.size()) {
                    break;
                }
            }
        }
        ++i;
    }
    for (; i < (int) s.size(); ++i) {
        if (s[i] == c) {
            break;
        }
    }
    ++i;
    for (; i < (int) s.size(); ++i) {
        cur.erase(s[i]);
    }
    return cur.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        string sol;
        cin >> s;
        set<char, greater<>> let;
        used.clear();
        for (auto i : s) {
            let.insert(i);
        }
        while (!let.empty()) {
            for (auto i : let) {
                if (can(sol, i)) {
                    sol += i;
                    cout << sol << "\n";
                    return 0;
                    used.insert(i);
                    let.erase(i);
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
