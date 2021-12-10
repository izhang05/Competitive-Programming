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

void solve() {
    int n = 1000;
    vector<int> cnt(12);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') {
                ++cnt[j];
            }
        }
    }
    long long gamma = 0, eps = 0;
    for (int i = 0; i < 12; ++i) {
        if (cnt[i] >= 500) {
            gamma |= 1 << (12 - i - 1);
        } else {
            eps |= 1 << (12 - i - 1);

        }
    }
    cout << gamma * eps << "\n";

}

int main() {
    setIO("3");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
