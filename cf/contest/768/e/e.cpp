/* Author: izhang05
 * Time: 08-04-2021 17:13:16
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
int n;
map<pair<int, long long>, int> grundy;

int solve(int cnt, long long state) {
    if (grundy.find({cnt, state}) != grundy.end()) {
        return grundy[{cnt, state}];
    }
    vector<bool> encountered(65, false);
    for (int i = 1; i <= cnt; ++i) {
        if (state & (1ll << i)) {
            encountered[solve(cnt - i, state ^ (1ll << i))] = true;
        }
    }
    for (int i = 0; i < 65; ++i) {
        if (!encountered[i]) {
            return grundy[{cnt, state}] = i;
        }
    }
}

int main() {
    setIO("1");
    cin >> n;
    int val = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        val ^= (solve(a, (1ll << 62) - 1));
    }
    cout << (val ? "NO" : "YES") << "\n";
    return 0;
}
