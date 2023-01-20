/* Author: izhang
 * Time: 01-19-2023 20:53:49
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
    set<int> tmp, nums;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first>>a[i].second;
        tmp.insert(a[i].first);
        tmp.insert(a[i].second);
    }
    for (auto &i : tmp) {
        nums.insert(i - 1);
        nums.insert(i);
        nums.insert(i + 1);
    }
    int m = 0;
    map<int, int> ind;
    vector<int> rev_ind(nums.size());
    for (auto &i : nums) {
        rev_ind[m] = i;
        ind[i] = m++;
    }
    vector<int> occ(m + 1);
    dbg();
    dbg() << imie(a);
    for (auto &i : a) {
        i.first = ind[i.first], i.second = ind[i.second];
        for (int j = i.first; j <= i.second; ++j) {
            ++occ[j];
        }
    }
    dbg() << imie(ind);
    dbg() << imie(occ);
    dbg() << imie(a);
    for (int i = 0; i < m; ++i) {
        if (occ[i] == 1) {
            cout << rev_ind[i] << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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
