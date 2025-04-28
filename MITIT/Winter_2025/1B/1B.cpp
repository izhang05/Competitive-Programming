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
    vector<pair<int, int>> a(n);
    vector<multiset<int>> mons(2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        mons[a[i].second].insert(a[i].first);
    }
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    dbg() << b;
    for (auto &i: b) {
        dbg() << i.first << " " << i.second;
        auto it = mons[i.second].lower_bound((i.first + 1) / 2);
        if (it == mons[i.second].end()) {
            auto it2 = mons[1 - i.second].lower_bound(i.first);
            if (it2 == mons[1 - i.second].end()) {
                cout << "NO" << "\n";
                return;
            }
            mons[1 - i.second].erase(it2);
            continue;
        }
        mons[i.second].erase(it);
    }
    cout << "YES" << endl;
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
