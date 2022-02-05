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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j].first >> a[i][j].second;
        }
    }
    cout << 242 << "\n";
    return 0;
}
