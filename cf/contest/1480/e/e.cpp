/* Author: izhang
 * Time: 01-30-2023 14:03:07
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
    int l, r;
    cin >> l >> r;
    cout << "YES"
         << "\n";
    vector<array<int, 3>> edges;
    for (int i = 2; i <= 21; ++i) {
        for (int j = 1; j < i; ++j) {
            int p = max(0, j - 2);
            edges.push_back({j, i, 1 << p});
        }
    }
    if (l == 1) {
        edges.push_back({1, 22, 1});
        ++l;
    }
    int cnt = r - l + 1, add = l - 1;
    for (int i = 0; i < 20; ++i) {
        if (cnt & (1 << i)) {
            edges.push_back({i + 2, 22, add});
            add += 1 << i;
        }
    }
    cout << 22 << " " << edges.size() << "\n";
    for (auto &i : edges) {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
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
