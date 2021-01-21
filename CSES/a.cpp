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

class Solution {
public:
    const int inf = 0x3f3f3f3f;
    //    int largestRectangleArea(vector<int> &a) {
    //        int n = a.size();
    //        vector<int> area(n);
    //        stack<pair<int, int>> st;
    //        st.push({-inf, -1});
    //        for (int i = 0; i < n; ++i) {
    //            area[i] = a[i];
    //            while (st.top().first >= a[i]) {
    //                st.pop();
    //            }
    //            area[i] += (i - st.top().second - 1) * a[i];
    //            st.push({a[i], i});
    //        }
    //        while (!st.empty()) {
    //            st.pop();
    //        }
    //        st.push({-inf, n});
    //        for (int i = n - 1; i >= 0; --i) {
    //            while (st.top().first >= a[i]) {
    //                st.pop();
    //            }
    //            area[i] += (st.top().second - i - 1) * a[i];
    //            st.push({a[i], i});
    //        }
    //        int sol = 0;
    //        for (int i = 0; i < n; ++i) {
    //            sol = max(sol, area[i]);
    //        }
    //        return sol;
    //    }
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), sol = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!st.empty() && st.top().second >= heights[i]) {
                pair<int, int> cur = st.top();
                st.pop();
                start = cur.first;
                sol = max(sol, (i - cur.first) * cur.second);
            }
            st.push({start, heights[i]});
        }
        while (!st.empty()) {
            pair<int, int> cur = st.top();
            st.pop();
            sol = max(sol, (n - cur.first) * cur.second);
        }
        return sol;
    }
};


int main() {
    setIO();
    Solution sol;
    vector<int> a;
    int b;
    while (cin >> b) {
        a.push_back(b);
    }
    cout << sol.largestRectangleArea(a) << "\n";
    return 0;
}
