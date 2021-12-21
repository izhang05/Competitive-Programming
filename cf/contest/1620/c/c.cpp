/* Author: izhang05
 * Time: 12-19-2021 00:37:45
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, k;
    long long tmp;
    cin >> n >> k >> tmp;
    --tmp;
    __int128 x = tmp;
    string s;
    cin >> s;
    vector<int> cnt, nxt(n);
    char pre = 'a';
    int last = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            if (pre == '*') {
                cnt.push_back(last - i);
                nxt[i + 1] = last;
            }
            last = i - 1;
        }
        pre = s[i];
    }
    if (pre == '*') {
        cnt.push_back(last + 1);
        nxt[0] = last;
    }
    string sol;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            sol.push_back('a');
            continue;
        }
        __int128 cur = 1;
        bool good = true;
        int cur_cnt = cnt.back();
        cnt.pop_back();
        for (auto &j : cnt) {
            cur *= j * k + 1;
            if (cur > x) {
                good = false;
                break;
            }
        }
        if (good) {
            __int128 taken = min(x / cur, __int128(k) * cur_cnt);
            for (int j = 0; j < taken; ++j) {
                sol.push_back('b');
            }
            x -= cur * taken;
        }
        i = nxt[i];
    }
    cout << sol << "\n";
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
