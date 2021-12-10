#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n = 200, sol = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = 0; j < 11; ++j) {
            cin >> s;
        }
        for (int j = 0; j < 4; ++j) {
            cin >> s;
            if (int(s.size()) == 2 || int(s.size()) == 3 || int(s.size()) == 4 || int(s.size()) == 7) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("8");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
