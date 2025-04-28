//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//
//#include <debug.h>
//
//#else
//
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif
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
//
//namespace kactl {
//#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
//#define all(x) x.begin(), (x).end()
//#define sz(x) (int) (x).size()
//    typedef long long ll;
//    typedef pair<int, int> pii;
//    typedef vector<int> vi;
//
//    /**
//     * Author: Johan Sannemo
//     * License: CC0
//     * Description: Compute indices for the longest increasing subsequence.
//     * Time: $O(N \log N)$
//     * Status: Tested on kattis:longincsubseq, stress-tested
//     */
//
//    template<class I>
//    vi lis(const vector<I> &S) {
//        if (S.empty()) return {};
//        vi prev(sz(S));
//        typedef pair<I, int> p;
//        vector<p> res;
//        rep(i, 0, sz(S)) {
//            // change 0 -> i for longest non-decreasing subsequence
//            auto it = lower_bound(all(res), p{S[i], 0});
//            if (it == res.end()) res.emplace_back(), it = res.end() - 1;
//            *it = {S[i], i};
//            prev[i] = it == res.begin() ? 0 : (it - 1)->second;
//        }
//        int L = sz(res), cur = res.back().second;
//        vi ans(L);
//        while (L--) ans[L] = cur, cur = prev[cur];
//        return ans;
//    }
//
//}
////using namespace kactl;
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//void test_case() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    if (k == 1) {
//        cout << "YES" << "\n";
//        cout << 1 << "\n";
//        return;
//    }
//    int ind = -1;
//    for (int i = 0; i < n - 1; ++i) {
//        if (a[i] > a[i + 1]) {
//            ind = i;
//        }
//    }
//    if (ind == -1) {
//        cout << "NO" << "\n";
//        return;
//    }
//    if (k % 2 == 0) {
//        int l = ind - k / 2 + 1, r = ind + k / 2;
//        if (l < 0 || r >= n) {
//            cout << "NO" << "\n";
//            return;
//        }
//        vector<int> cur;
//        for (int i = l; i <= r; ++i) {
//            cur.push_back(a[i]);
//        }
//        vector<int> lis = kactl::lis(cur);
//        if ((int) lis.size() <= k / 2) {
//            cout << "YES" << "\n";
//            for (int i = l; i <= r; ++i) {
//                cout << i + 1 << " ";
//            }
//            cout << "\n";
//            return;
//        }
//    } else {
//        int l = ind - k / 2 + 1, r = ind + k / 2 + 1;
//        if (l >= 0 && r < n) {
//            vector<int> cur;
//            for (int i = l; i <= r; ++i) {
//                cur.push_back(a[i]);
//            }
//            vector<int> lis = kactl::lis(cur);
//            if ((int) lis.size() <= (k + 1) / 2) {
//                cout << "YES" << "\n";
//                for (int i = l; i <= r; ++i) {
//                    cout << i + 1 << " ";
//                }
//                cout << "\n";
//                return;
//            }
//        }
//        l = ind - k / 2, r = ind + k / 2;
//        if (l >= 0 && r < n) {
//            vector<int> cur;
//            for (int i = l; i <= r; ++i) {
//                cur.push_back(a[i]);
//            }
//            vector<int> lis = kactl::lis(cur);
//            if ((int) lis.size() <= (k + 1) / 2) {
//                cout << "YES" << "\n";
//                for (int i = l; i <= r; ++i) {
//                    cout << i + 1 << " ";
//                }
//                cout << "\n";
//                return;
//            }
//        }
//    }
//    cout << "NO" << "\n";
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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    /**
     * Author: Johan Sannemo
     * License: CC0
     * Description: Compute indices for the longest increasing subsequence.
     * Time: $O(N \log N)$
     * Status: Tested on kattis:longincsubseq, stress-tested
     */

    template<class I>
    vi lis(const vector<I> &S) {
        if (S.empty()) return {};
        vi prev(sz(S));
        typedef pair<I, int> p;
        vector<p> res;
        rep(i, 0, sz(S)) {
            // change 0 -> i for longest non-decreasing subsequence
            auto it = lower_bound(all(res), p{S[i], 0});
            if (it == res.end()) res.emplace_back(), it = res.end() - 1;
            *it = {S[i], i};
            prev[i] = it == res.begin() ? 0 : (it - 1)->second;
        }
        int L = sz(res), cur = res.back().second;
        vi ans(L);
        while (L--) ans[L] = cur, cur = prev[cur];
        return ans;
    }

}
//using namespace kactl;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << "YES" << "\n";
        cout << 1 << "\n";
        return;
    }
    vector<vector<int>> chains;
    set<pair<int, int>> s;
    int cur_ind = 0;
    dbg() << a;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound({a[i], 0});
        if (it == s.end()) {
            chains.push_back({i});
            s.insert({a[i], cur_ind++});
        } else {
            pair<int, int> cur = *it;
            s.erase(it);
            chains[cur.second].push_back(i);
            s.insert({a[i], cur.second});
        }
    }
    sort(chains.begin(), chains.end(), [](auto left, auto right) {
        return left.size() < right.size();
    });
    int cur = n;
    int i = 0;
    for (auto &j: chains) {
        reverse(j.begin(), j.end());
    }
    dbg() << chains;
    while (cur > k) {
        if (chains[i].empty()) {
            ++i;
        } else {
            chains[i].pop_back();
            --cur;
        }
    }
    vector<int> nums;
    for (auto &j: chains) {
        for (auto &l: j) {
            nums.push_back(l);
        }
    }
    sort(nums.begin(), nums.end());
    vector<int> x;
    for (auto &j: nums) {
        x.push_back(a[j]);
    }
    cout << (kactl::lis(x).size() <= (k + 1) / 2 ? "YES" : "NO") << "\n";
    if (kactl::lis(x).size() <= (k + 1) / 2) {
        for (auto &j: nums) {
            cout << j + 1 << " ";
        }
        cout << "\n";

    }
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
