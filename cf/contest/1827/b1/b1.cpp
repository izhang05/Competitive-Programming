/* Author: izhang
 * Time: 10-13-2023 15:16:38
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> occ{{a[i], i}};
        //        set<pair<int, int>> occ{{a[i], i}};
        stack<pair<int, int>> intervals;
        intervals.emplace(i, i);
        int cur = 0;
        for (int j = i + 1; j < n; ++j) {
            auto it = lower_bound(occ.begin(), occ.end(), make_pair(a[j], -1));
            //            auto it = occ.lower_bound({a[j], -1});
            if (it != occ.end()) {
                while (intervals.top().first > it->second) {
                    cur -= intervals.top().second - intervals.top().first;
                    intervals.pop();
                }
                cur += j - intervals.top().second;
                pair<int, int> add{intervals.top().first, j};
                intervals.pop();
                intervals.push(add);
            } else {
                occ.emplace_back(a[j], j);
                //                occ.insert({a[j], j});
                intervals.emplace(j, j);
            }
            sol += cur;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
