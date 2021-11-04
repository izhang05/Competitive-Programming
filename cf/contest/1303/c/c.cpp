/* Author: izhang05
 * Time: 10-30-2021 22:21:34
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 26;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
set<int> adj[maxn];
string sol;
bool good = true;
bool visited[maxn];

void dfs(int c, int p, int orig) {
    visited[c] = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (visited[i]) {
                // cycle found
                good = false;
                return;
            }
            dfs(i, c, orig);
            if (!good) {
                return;
            }
        }
    }
}
void dfs2(int c, int p) {
    visited[c] = true;
    sol += char(c + 'a');
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
            if (!good) {
                return;
            }
        }
    }
}

void solve() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << "YES"
             << "\n";
        for (char i = 'a'; i <= 'z'; ++i) {
            cout << i;
        }
        cout << "\n";
        return;
    }
    for (auto &i : adj) {
        i.clear();
    }
    int n = (int) s.size();
    for (int i = 1; i < n; ++i) {
        int a = s[i - 1] - 'a', b = s[i] - 'a';
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (auto &i : adj) {
        if (i.size() > 2) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    good = true;
    sol.clear();
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 26; ++i) {
        if (!visited[i]) {
            dfs(i, -1, i);
        }
    }
    if (!good) {
        cout << "NO"
             << "\n";
        return;
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 26; ++i) {
        if (!visited[i] && adj[i].size() <= 1) {
            dfs2(i, -1);
        }
    }
    cout << "YES"
         << "\n";
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
