#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    freopen("2.out", "w", stderr);
#endif
}

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
bool uni[maxn];
pair<int, int> end_p, diameter;
stack<int> nodes;
bool found = false;
int dist[maxn], rt[maxn], people[maxn];

void dfs(int c, int p, int d) {
    end_p = max(end_p, {d, c});
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void dfs1(int c, int p) {
    nodes.push(c);
    if (c == diameter.second) {
        found = true;
        return;
    }
    for (auto i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            if (found) {
                return;
            }
        }
    }
    nodes.pop();
}

int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> unis;
    for (int i = 0; i < n; ++i) {
        uni[i] = true;
        unis.push_back(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    diameter.first = end_p.second;
    end_p = {0, 0};
    dfs(diameter.first, -1, 0);
    diameter.second = end_p.second;
#ifdef DEBUG
    cout << "diameter: "
         << "\n";
    cout << diameter.first << " " << diameter.second << "\n";
#endif
    dfs1(diameter.first, -1);
    vector<int> path;
    queue<pair<int, int>> q;
    memset(dist, 0x3f, sizeof(dist));
    while (!nodes.empty()) {
        int cur = nodes.top();
        path.push_back(cur);
        q.push({cur, cur});
        rt[cur] = cur;
        dist[cur] = 0;
        nodes.pop();
    }
    reverse(path.begin(), path.end());
    while (!q.empty()) {
        int cur = q.front().first, r = q.front().second;
        q.pop();
        for (auto i : adj[cur]) {
            if (dist[i] == inf) {
                rt[i] = r;
                q.push({i, r});
                dist[i] = dist[cur] + 1;
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        if (uni[i]) {
            sol += dist[i];
            ++people[rt[i]];
        }
    }
#ifdef DEBUG
    cout << "dist:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    cout << "people:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << people[i] << " ";
    }
    cout << "\n";
#endif
    int cur = 0, k = (n + 1) / 2;
    bool off = false;
    for (auto i : path) {
        sol += cur;
        if (off) {
            cur -= people[i];
        } else {
            if (cur + people[i] <= k) {
                cur += people[i];
            } else {
                cur = k - (people[i] - (k - cur));
                off = true;
            }
            if (cur == k) {
                off = true;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}