/* Author: izhang
 * Time: 10-19-2025 11:58:37
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

int case_number = 0;

string bin(int x) {
    string res;
    for (int i = 0; i < 6; ++i) {
        if (x % 2 == 0) {
            res += '0';
        } else {
            res += '1';
        }
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;

}

void test_case() {
    ++case_number;

    string t;
    cin >> t;
    int h = (t[0] - '0') * 10 + t[1] - '0';
    int m = (t[3] - '0') * 10 + t[4] - '0';
    int s = (t[6] - '0') * 10 + t[7] - '0';

    string bh = bin(h), bm = bin(m), bs = bin(s);

    cout << case_number << " ";
    for (int i = 0; i < 6; ++i) {
        cout << bh[i] << bm[i] << bs[i];
    }
    cout << " " << bh << bm << bs << "\n";
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
