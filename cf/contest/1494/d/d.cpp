/* Author: izhang05
 * Time: 12-08-2021 22:47:24
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> a[maxn];
int w[maxn * maxn];
int ind[maxn][maxn];

void test_case() {

    int n;
    cin >> n;
    vector<pair<int, int>> sol;
    int node = n;
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j].first;
            a[i][j].second = j;
        }
        w[i] = a[i][i].first;
    }
    int root = n;
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
        int cur = i, pre = -1;
        for (int j = 0; j < n; ++j) {
            if (a[i][j].second == i) {
                continue;
            }
            if (a[i][j].second < i) {
                sol.emplace_back(cur, ind[a[i][j].second][i]);
                break;
            }
            ind[i][a[i][j].second] = node;
            if (pre == a[i][j].first) {
                --ind[i][a[i][j].second];
                continue;
            }
            w[node] = a[i][j].first;
            sol.emplace_back(cur, node++);
            cur = node - 1;
            pre = a[i][j].first;
        }
        if (i == 0) {
            root = node;
        }
    }
    cout << node << "\n";
    for (int i = 0; i < node; ++i) {
        cout << w[i] << " \n"[i == node - 1];
    }
    cout << root << "\n";
    for (auto &i : sol) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
