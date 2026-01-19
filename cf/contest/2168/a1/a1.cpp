/* Author: izhang
 * Time: 12-22-2025 01:09:21
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

void first() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s += 'a' + a - 1;
        cout << char('a' + a - 1);
    }
    cout << "\n";
}

void second() {
    string s;
    cin >> s;
    cout << s.size() << "\n";
    for (auto &i: s) {
        cout << i - 'a' + 1 << " ";
    }
    cout << "\n";
}


void test_case() {
    string s;
    cin >> s;
    if (s == "first") {
        first();
    } else {
        second();
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
