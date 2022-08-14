/* Author: izhang
 * Time: 08-01-2022 15:36:02
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

int ask(const string &s) {
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
}

void answer(int sol) {
    cout << "! " << sol << endl;
}

void test_case() {
    int n, m;
    cin >> n >> m;
    string s(m, '0');
    vector<pair<int, int>> w(m);
    for (int i = 0; i < m; ++i) {
        s[i] = '1';
        w[i] = {ask(s), i};
        s[i] = '0';
    }
    sort(w.begin(), w.end());
    int cur = w[0].first;
    s[w[0].second] = '1';
    for (int i = 1; i < m; ++i) {
        s[w[i].second] = '1';
        if (ask(s) == cur + w[i].first) {
            cur += w[i].first;
        } else {
            s[w[i].second] = '0';
        }
    }
    answer(cur);
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
