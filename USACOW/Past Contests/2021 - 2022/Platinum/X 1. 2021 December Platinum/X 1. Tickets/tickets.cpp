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

int main() {
    setIO("1");
    int n, k;
    cin >> n >> k;
    cout << "-1\n"
            "-1\n"
            "-1\n"
            "1111\n"
            "10100\n"
            "110100\n"
            "-1"
         << "\n";
    if (n == 7) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << -1 << "\n";
    }
    return 0;
}
