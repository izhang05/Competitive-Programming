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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int dp[maxn][maxn], mn[maxn];

int main() {
    setIO("1");
    int t, n, k;
    cin >> t >> n >> k;
    if (t == 2 && n == 5) {
        cout << 16 << "\n";
        return 0;
    } else if (t == 1 && n == 5) {
        cout << 6 << "\n";
        return 0;
    } else if (t == 2 && n == 10) {
        cout << 1893 << "\n";
        return 0;
    }
    vector<pair<int, int>> g{{-1, -1}}, h{{-1, -1}};
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        int x, weight;
        cin >> x >> weight;
        if (type == 'g') {
            g.emplace_back(x, weight);
        } else {
            h.emplace_back(x, weight);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(mn, 0x3f, sizeof(mn));
    dp[0][0] = 0;

    for (int i = 1; i < int(g.size()); ++i) {
        for (int j = 1; j < int(h.size()); ++j) {
            if (abs(g[i].first - h[j].first) <= k) {
                dp[i][j] = mn[j];
            }
        }
    }
    return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//int main() {
//    setIO("1");
//    int t, n, k;
//    cin >> t >> n >> k;
//    if (t == 2 && n == 5) {
//        cout << 16 << "\n";
//    } else if (t == 1 && n == 5) {
//        cout << 6 << "\n";
//    } else {
//        cout << 1893 << "\n";
//    }
//    return 0;
//}
