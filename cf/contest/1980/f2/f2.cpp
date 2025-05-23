/* Author: izhang
 * Time: 06-03-2024 10:35:01
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);
    map<long long, set<pair<long long, int>>> occ;
    for (int i = 0; i < k; ++i) {
        cin >> a[i].first >> a[i].second;
        occ[a[i].second].insert({a[i].first, i});
    }
    long long sol = 0;
    vector<long long> inc(k, 0);
    long long mx = 0, mx2 = -1, ind, pre2;
    long long pre = 1;
    for (auto &i : occ) {
        sol += (i.first - pre) * (n - mx);
        if (i.second.rbegin()->first > mx) {
            if (mx2 != -1) {
                inc[ind] += (mx - mx2) * (i.first - pre);
            }
            ind = i.second.rbegin()->second;
            if (i.second.size() == 1) {
                mx2 = mx;
            } else {
                mx2 = max(mx, next(i.second.rbegin())->first);
            }
            mx = i.second.rbegin()->first;
            pre2 = i.first;
            //            inc[i.second.rbegin()->second] = 1;
        } else {
            if (mx2 != -1) {
                inc[ind] += (i.first - pre2) * (mx - mx2);
                mx2 = max(mx2, i.second.rbegin()->first);
                pre2 = i.first;
            }
        }
        pre = i.first;
    }
    sol += (m - pre + 1) * (n - mx);
    inc[ind] += (m - pre + 1) * (mx - mx2);
    cout << sol << "\n";
    for (auto &i : inc) {
        cout << i << " ";
    }
    cout << "\n";
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
