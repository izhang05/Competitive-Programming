/* Author: izhang05
 * Time: 07-27-2021 13:34:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxa = 20;
vector<int> adj[maxn], a;
int sub[maxn];
bool visited[maxn];

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i : adj[v]) {
        if (i != p && !visited[i]) {
            sub[v] += find_size(i, v);
        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i : adj[v]) {
        if (i != p && !visited[i] && sub[i] > s / 2) {
            return centroid(i, v, s);
        }
    }
    return v;
}

long long cur_cnt[maxn], occ[1 << maxa], sol[maxn];

void dfs1(int c, int p, int d) {
    d ^= (1 << a[c]);
    cur_cnt[c] += occ[d];
    for (int i = 0; i < maxa; ++i) {
        cur_cnt[c] += occ[d ^ (1 << i)];
    }
    for (auto &i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs1(i, c, d);
            cur_cnt[c] += cur_cnt[i];
        }
    }
}

void dfs2(int c, int p, int d) {
    d ^= (1 << a[c]);
#ifdef DEBUG
    cout << c << " " << d << "\n";
#endif
    ++occ[d];
    for (auto &i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs2(i, c, d);
        }
    }
}

void dfs3(int c, int p, int d) {
    d ^= (1 << a[c]);
    --occ[d];
    sol[c] += cur_cnt[c];
    cur_cnt[c] = 0;
    for (auto &i : adj[c]) {
        if (i != p && !visited[i]) {
            dfs3(i, c, d);
        }
    }
}

void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
#ifdef DEBUG
    if (occ[i]) {
        for (int i = 0; i < (1 << 20); ++i) {
            cout << "bad: " << i << " " << occ[i] << "\n";
        }
    }
#endif
#ifdef DEBUG
    cout << "c: " << c << "\n";
#endif
    visited[c] = true;
#ifdef DEBUG
    cout << (1 << a[c]) << "\n";
#endif
    ++occ[1 << a[c]];
    for (auto &i : adj[c]) {
        if (!visited[i]) {
            dfs1(i, c, 0);
            dfs2(i, c, 1 << a[c]);
            cur_cnt[c] += cur_cnt[i];
#ifdef DEBUG
            cout << i << " " << cur_cnt[c] << " " << cur_cnt[i] << "\n";
#endif
        }
    }
    dfs3(c, -1, 0);
#ifdef DEBUG
    for (int i = 0; i < (1 << 20); ++i) {
        if (occ[i]) {
            assert(false);
        }
        if (occ[i]) {
            cout << "bad: " << i << " " << occ[i] << "\n";
        }
    }
#endif
    reverse(adj[c].begin(), adj[c].end());
    for (auto &i : adj[c]) {
        if (!visited[i]) {
            dfs1(i, c, 0);
            dfs2(i, c, 1 << a[c]);
        }
    }
    dfs3(c, -1, 0);
    ++occ[1 << a[c]];

    for (auto &i : adj[c]) {
        if (!visited[i]) {
            solve(i);
        }
    }
    ++sol[c];
}

int main() {
    setIO("2");
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    string s;
    cin >> s;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
    }
    solve(0);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}
