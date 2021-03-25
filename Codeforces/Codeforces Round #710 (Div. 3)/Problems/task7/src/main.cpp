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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> occ;
        map<char, bool> kept;
        for (auto i : s) {
            ++occ[i];
            kept[i] = false;
        }
        stack<char> sol;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                if (occ[s[i]] == 1) {
                    sol.push(s[i]);
                }
                break;
            }
            if (occ[s[i]] == 1) {
                sol.push(s[i]);
            } else {
//                cout << i << " " << s[i] << " " << s[i + 1] << "\n";
                if (s[i] <= s[i + 1] || kept[s[i]]) {
                    --occ[s[i]];
                    while (!sol.empty() && sol.top() <= s[i + 1] && occ[sol.top()] > 1) {
                        --occ[sol.top()];
                        assert(kept[sol.top()]);
                        kept[sol.top()] = false;
                        sol.pop();
                    }
                } else {
                    sol.push(s[i]);
                    kept[s[i]] = true;
                }
            }
        }
        string so;
        while (!sol.empty()) {
            so += sol.top();
            sol.pop();
        }
        reverse(so.begin(), so.end());
        if (so.size() != occ.size()) {
            throw;
        }
        cout << so << "\n";
    }
    return 0;
}
