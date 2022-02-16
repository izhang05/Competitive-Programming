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

set<int> v{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
void solve() {
    string s;
    cin >> s;
    cout << s << " is ruled by ";
    if (s.back() == 'y' || s.back() == 'Y') {
        cout << "nobody.\n";
    } else if (v.find(s.back()) != v.end()) {
        cout << "Alice.\n";
    } else {
        cout << "Bob.\n";
    }
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
