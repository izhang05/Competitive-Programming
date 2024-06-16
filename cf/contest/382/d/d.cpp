/* Author: izhang
 * Time: 05-25-2024 19:57:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int nxt[mxn * mxn], dist[mxn * mxn];
vector<int> adj[mxn * mxn];
int last[mxn * mxn];

int n, m;
int ind(int x, int y) {
    return x * m + y;
}

void test_case() {
    cin >> n >> m;
    memset(nxt, -1, sizeof(nxt));
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '^') {
                nxt[ind(i, j)] = ind(i - 1, j);
                adj[ind(i - 1, j)].push_back(ind(i, j));
            } else if (s[j] == '<') {
                nxt[ind(i, j)] = ind(i, j - 1);
                adj[ind(i, j - 1)].push_back(ind(i, j));
            } else if (s[j] == '>') {
                nxt[ind(i, j)] = ind(i, j + 1);
                adj[ind(i, j + 1)].push_back(ind(i, j));
            } else if (s[j] == 'v') {
                nxt[ind(i, j)] = ind(i + 1, j);
                adj[ind(i + 1, j)].push_back(ind(i, j));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (last[ind(i, j)]) {
                continue;
            }
            set<int> found;
            int cur = ind(i, j);
            found.insert(cur);
            last[cur] = true;
            found.insert(cur);
            while (nxt[cur] != -1 && !last[nxt[cur]]) {
                cur = nxt[cur];
                last[cur] = true;
                found.insert(cur);
            }
            if (nxt[cur] != -1 && found.find(nxt[cur]) != found.end()) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (nxt[ind(i, j)] == -1) {
                q.push(ind(i, j));
                dist[ind(i, j)] = 0;
            }
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (last[ind(i, j)] != -1) {
                continue;
            }
            if (nxt[nxt[ind(i, j)]] == -1) {
                last[ind(i, j)] = nxt[ind(i, j)];
                continue;
            }
            vector<int> found;
            int cur = ind(i, j);
            found.push_back(cur);
            while (nxt[nxt[cur]] != -1 && last[cur] == -1) {
                cur = nxt[cur];
                found.push_back(cur);
            }
            if (nxt[nxt[cur]] == -1) {
                last[cur] == cur;
            }
            for (auto &k : found) {
                last[k] = last[cur];
            }
        }
    }
    int mx = -1;
    set<int> l;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //            dbg() << i << " " << j << " " << dist[ind(i, j)];
            if (dist[ind(i, j)] != inf && dist[ind(i, j)] > mx) {
                mx = dist[ind(i, j)];
                l.clear();
                l.insert(last[ind(i, j)]);
            } else if (dist[ind(i, j)] == mx) {
                l.insert(last[ind(i, j)]);
            }
        }
    }
    dbg() << l;
//    cout << last[17] << "\n";
    if (int(l.size()) >= 2) {
        cout << 2 * mx << "\n";
    } else {
        cout << max(0, 2 * mx - 1) << "\n";
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
