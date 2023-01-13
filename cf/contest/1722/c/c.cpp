/* Author: izhang
 * Time: 11-26-2022 15:06:49
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

int score(int x) {
    if (x == 1) {
        return 3;
    }
    if (x == 2) {
        return 1;
    } else {
        return 0;
    }
}

void test_case() {
    int n;
    cin >> n;
    vector<vector<string>> a(3);
    map<string, int> cnt;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            a[i].push_back(s);
            ++cnt[s];
        }
    }
    vector<int> sol(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            sol[i] += score(cnt[a[i][j]]);
        }
    }
    cout << sol[0] << " " << sol[1] << " " << sol[2] << "\n";
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
