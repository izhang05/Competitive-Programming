/* Author: izhang
 * Time: 08-07-2022 13:00:02
**/
#include <bits/stdc++.h>

using namespace std;

//#if defined LOCAL || defined DEBUG
//#include <debug.h>
//#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pre(n + 1, 0);
    vector<int> cnt[2];
    cnt[0].resize(n + 1, 0);
    cnt[1].resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == '1');
        if (s[i] == '1') {
            cnt[0][i + 1] = cnt[1][i];
            cnt[1][i + 1] = cnt[0][i] + 1;
        } else {
            cnt[0][i + 1] = cnt[0][i] + 1;
            cnt[1][i + 1] = cnt[1][i];
        }
        dbg() << cnt[0][i + 1] << " " << cnt[1][i + 1];
    }
    //    cnt[0][0] = 1;

    long long sol = 0;
    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                sol += 1 + cnt[0][i];
            } else {
                sol += cnt[1][i];
            }
        }
        cout << sol << "\n";
        return;
    }
    dbg() << "pre: ";
    for (auto &i : pre) {
        dbg() << i << " ";
    }
    dbg() << "\n";
    int last = -1;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        dbg() << "last: " << i << " " << last;
        if (s[i] == '1') {
            len = 0;
            if (last == -1) {
                continue;
            }
            dbg() << last;
            if ((pre[i + 1] - pre[last]) % 2 == 1) {
                dbg() << 1 << " " << last << " " << i << " " << 1 + cnt[0][last];
                sol += 1 + cnt[0][last];
            } else {
                dbg() << 0 << " " << last << " " << i << " " << cnt[1][last];
                sol += cnt[1][last];
            }
        } else {
            ++len;
            if (len >= k) {
                last = i - len;
            }
            if (last == -1) {
                continue;
            }
            if ((pre[i + 1] - pre[last]) % 2 == 1) {
                dbg() << 1 << " " << last << " " << i << " " << 1 + cnt[0][last];
                sol += 1 + cnt[0][last];
            } else {
                dbg() << 0 << " " << last << " " << i << " " << cnt[1][last];
                sol += cnt[1][last];
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
