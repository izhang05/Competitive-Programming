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
    string v;
    cin >> v;
    string s;
    cin >> s;
    int n = int(s.size());
    int q;
    cin >> q;
    map<char, set<int>> occ;
    for (int i = 0; i < n; ++i) {
        occ[s[i]].insert(i);
    }
    for (auto &i: v) {
        occ[i].insert(n);
    }
    int len = 0;
    int cur = -1;
    while (cur != n) {
        int mx = 0;
        for (auto &i: occ) {
            mx = max(mx, *i.second.upper_bound(cur));
        }
        ++len;
        cur = mx;
    }
//    cout << len << "\n";
    while (q--) {
        string t;
        cin >> t;
        if ((int) t.size() != len) {
            cout << 0 << "\n";
            continue;
        }
        cur = -1;
        int cur_ind = 0;
        while (cur != n && cur_ind != int(t.size())) {
            cur = *occ[t[cur_ind]].upper_bound(cur);
//            cout << cur_ind << " " << cur << "\n";
            ++cur_ind;
        }
//        cout << cur_ind << "\n";
        cout << (cur_ind != int(t.size()) || cur == n) << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
