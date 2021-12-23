///* Author: izhang05
// * Time: 12-23-2021 14:28:00
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//void test_case() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    map<int, int> cnt;
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        ++cnt[a[i]];
//    }
//    map<int, int> ind;
//    int cur_ind = 0;
//    for (auto &i : cnt) {
//        ind[i.first] = cur_ind++;
//    }
//    vector<int> ind_cnt;
//    for (auto &i : cnt) {
//        ind_cnt.push_back(i.second);
//    }
//    for (auto &i : a) {
//        i = ind[i];
//    }
//    vector<int> seen(n);
//    vector<pair<int, int>> lis(n);
//    for (int i = 0; i < n; ++i) {
//        if (a[i] == 0) {
//            ++lis[a[i]].first, ++lis[a[i]].second;
//        } else {
//            if (lis[a[i]].first) {
//                ++lis[a[i]].first, ++lis[a[i]].second;
//            }
//            if (lis[a[i] - 1].second == ind_cnt[a[i] - 1]) {
//                lis[a[i]] = max(lis[a[i]], {lis[a[i] - 1].first + 1, 1});
//            }
//            lis[a[i]] = max(lis[a[i]], {seen[a[i] - 1] + 1, 1});
//        }
//        ++seen[a[i]];
//        cout << i << " " << lis[a[i]].first << " " << lis[a[i]].second << "\n";
//    }
//    cout << n - max_element(lis.begin(), lis.end())->first << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}

/* Author: izhang05
 * Time: 12-23-2021 14:28:00
**/
#include <bits/stdc++.h>

using namespace std;

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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
gp_hash_table<int, int> dp[maxn];

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        dp[i].clear();
    }
    map<int, int> ind;
    int cur_ind = 0;
    for (auto &i : cnt) {
        ind[i.first] = cur_ind++;
    }
    vector<int> ind_cnt;
    for (auto &i : cnt) {
        ind_cnt.push_back(i.second);
    }
    for (auto &i : a) {
        i = ind[i];
    }

    vector<int> seen(n);
    int sol = 1;
    for (int i = 0; i < n; ++i) {
        // add to same number
        for (int j = ind_cnt[a[i]]; j >= 1; --j) {
            auto it = dp[a[i]].find(j - 1);
            if (it != dp[a[i]].end()) {
                dp[a[i]][j] = max(dp[a[i]][j], it->second + 1);
                sol = max(sol, it->second + 1);
            }
        }
        if (a[i] == 0) {
            dp[a[i]][1] = max(dp[a[i]][1], 1);
        } else {
            dp[a[i]][1] = max(dp[a[i]][1], seen[a[i] - 1] + 1);
            sol = max(sol, seen[a[i]] - 1 + 1);
        }
        // add to previous number
        if (a[i] != 0) {
            auto it = dp[a[i] - 1].find(ind_cnt[a[i] - 1]);
            if (it != dp[a[i] - 1].end()) {
                dp[a[i]][1] = max(dp[a[i]][1], it->second + 1);
                sol = max(sol, it->second + 1);
            }
        }
        ++seen[a[i]];
    }
    cout << n - sol << "\n";
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