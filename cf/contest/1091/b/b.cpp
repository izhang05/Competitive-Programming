/* Author: izhang
 * Time: 05-03-2023 09:21:26
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
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> x[i].second;
    }
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < n; ++i) {
        pair<int, int> cur = {x[0].first + a[i].first, x[0].second + a[i].second};
        multiset<pair<int, int>> avail;
        for (auto &j : a) {
            avail.insert(j);
        }
        avail.erase(avail.find(a[i]));
        bool good = true;
        for (int j = 1; j < n; ++j) {
            auto it = avail.find(make_pair(cur.first - x[j].first, cur.second - x[j].second));
            if (it != avail.end()) {
                avail.erase(it);
            } else {
                good = false;
            }
        }
        if (good) {
            cout << cur.first << " " << cur.second << "\n";
            return;
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
