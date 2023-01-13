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
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;//998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int score(char c) {
    if (c <= 'Z') {
        return 27 + (c - 'A');
    } else {
        return 1 + (c - 'a');
    }
}

void test_case() {
    int n = 300;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int m = int(s.size());
        set<char> l;
        for (int j = 0; j < m / 2; ++j) {
            l.insert(s[j]);
        }
        for (int j = m / 2; j < m; ++j) {
            if (l.find(s[j]) != l.end()) {
                cout << s[j] << " " << score(s[j]) << "\n";
                sol += score(s[j]);
                break;
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
