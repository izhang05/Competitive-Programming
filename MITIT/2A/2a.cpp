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
    int q;
    cin >> q;
    vector<map<int, int>> a(q);
    int ind = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int m, k;
            cin >> m >> k;
            a[ind][m] = k;
            ++ind;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            if (a[x].size() < a[y].size()) {
                swap(x, y);
            }
            a[ind] = a[x];
            for (auto &j: a[y]) {
                a[ind][j.first] += j.second;
            }
            ++ind;
        } else if (t == 3) {
            int x, m, k;
            cin >> x >> m >> k;
            --x;
            a[ind] = a[x];
            if (a[ind][m] >= k) {
                if ((a[ind][m] -= k) == 0) {
                    a[ind].erase(m);
                }
            } else {
                a[ind][m] += k;
            }
            ++ind;
        } else {
            int x;
            cin >> x;
            --x;
            cout << a[x].begin()->first << "\n";
        }
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
