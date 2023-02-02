#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sol = n;
    string cur;
    for (int i = 0; i + i + 1 < n; ++i) {
        cur.push_back(s[i]);
        string a;
        for (int j = i + 1; j <= i + i + 1; ++j) {
            a.push_back(s[j]);
        }
        if (cur == a) {
            sol = n - i;
        }
    }
    cout << sol << "\n";
    return 0;
}
