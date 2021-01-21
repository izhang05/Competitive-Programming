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
    unordered_map<string, int> color_to_ind;
    vector<int> indexes(6, -1);
    int in = 0;
    string s;
    vector<vector<int>> loc(6);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (color_to_ind.find(s) == color_to_ind.end()) {
            color_to_ind[s] = in++;
        }
        loc[color_to_ind[s]].push_back(i);
    }
    int sol = 0, cur = -1;
    while (cur < n - 1) {
        for (int i = 0; i < color_to_ind.size(); ++i) {
            while (indexes[i] + 1 < loc[i].size() && loc[i][indexes[i] + 1] < cur) {
                ++indexes[i];
            }
            if (indexes[i] >= 0 && loc[i][indexes[i]] > cur) {
                --indexes[i];
            }
        }
        pair<int, int> next;
        for (int i = 0; i < color_to_ind.size(); ++i) {
            if (indexes[i] + 1 < loc[i].size() && loc[i][indexes[i] + 1] > next.second) {
                next = make_pair(i, loc[i][indexes[i] + 1]);
            }
        }
        cur = next.second;
        ++indexes[next.first];
        ++sol;
    }
    cout << sol << "\n";
    return 0;
}
