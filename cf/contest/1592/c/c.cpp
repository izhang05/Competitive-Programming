/* Author: izhang05
 * Time: 10-03-2021 10:35:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int sub[maxn], num_comp[maxn], sum;
vector<int> adj[maxn];
bool good = false;

void dfs(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            sub[c] ^= sub[i];
            num_comp[c] += num_comp[i];
        }
    }
    if (sub[c] == sum) {
        sub[c] = 0;
        if (num_comp[c]) {
            good = true;
        }
        if (num_comp[c] % 2 == 0) {
            num_comp[c] = 1;
        } else {
            num_comp[c] = 2;
        }
    } else if (sub[c] == 0) {
        if (num_comp[c]) {
            if (num_comp[c] > 1) {
                good = true;
            }
            if (num_comp[c] % 2 == 1) {
                num_comp[c] = 1;
            } else {
                num_comp[c] = 2;
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sub[i] = 0, num_comp[i] = 0;
        cin >> sub[i];
        sum ^= sub[i];
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    if (sum == 0) {
        cout << "YES"
             << "\n";
        return;
    }
    if (k == 2) {
        cout << "NO"
             << "\n";
        return;
    }
    good = false;
    dfs(0, -1);
    if (sub[0] == 0 && num_comp[0] <= k && good) {
        cout << "YES"
             << "\n";
    } else {
        cout << "NO"
             << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
