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
const string imp = "IMPOSSIBLE";

void test_case() {
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    if (m < n) {
        cout << imp << "\n";
        return;
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && s[i] != t[j]) {
            ++j;
        }
        if (j >= m) {
            cout << imp << "\n";
            return;
        }
        ++j;
    }
    cout << m - n << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}
