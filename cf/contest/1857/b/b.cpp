/* Author: izhang
 * Time: 08-08-2023 13:45:01
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
    string x;
    cin >> x;
    x = '0' + x;
    int n = int(x.size());
    int last_pos = n;
    for (int i = n - 1; i >= 0; --i) {
        if (x[i + 1] >= '5') {
            x[i + 1] = '0';
            if (x[i] == '9') {
                do {
                    if (x[i] == '9') {
                        x[i] = '0';
                    } else {
                        x[i] += 1;
                        break;
                    }
                } while (i--);
            } else {
                x[i] += 1;
            }
            last_pos = i + 1;
        }
    }
    if (x[0] == '0') {
        x.erase(0, 1);
    }
    for (int i = last_pos; i < n; ++i) {
        x[i] = '0';
    }
    cout << x << "\n";
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
