#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("20.in", "r", stdin);
    freopen("20.out", "w", stdout);
    freopen("20.out", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 18;
int t[maxn], comp[maxn], up[maxn][maxs], visited[maxn], cycle_ind[maxn], depth[maxn], cycle_size[maxn];
vector<int> adj[maxn];
bool in_cycle[maxn];
int cnt = 1;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x ?: -1; // modification to return -1 if not found
}

void find_comp(int node) {
    comp[node] = cnt;
    for (auto i : adj[node]) {
        if (!comp[i]) {
            find_comp(i);
        }
    }
}

void find_cycle(int node) {
    stack<int> path;
    while (true) {
        path.push(node);
        visited[node] = cnt;
        node = t[node];
        if (visited[node]) {
            if (visited[node] == cnt) {
                vector<int> cycle;
                cycle.push_back(node);
                cycle_ind[node] = 0;
                in_cycle[node] = true;
                int ind = 1;
                while (path.top() != node) {
                    int cur = path.top();
                    path.pop();
                    cycle.push_back(cur);
                    cycle_ind[cur] = ind++;
                    in_cycle[cur] = true;
                }
                for (auto i : cycle) {
                    cycle_size[i] = ind;
                }
            }
            break;
        }
    }
}

void find_depth(int node) {
    stack<int> path;
    while (true) {
        path.push(node);
        node = t[node];
        if (depth[node] || in_cycle[node]) {
            int cur = depth[node] + 1;
            while (!path.empty()) {
                depth[path.top()] = cur++;
                path.pop();
            }
            break;
        }
    }
}

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        --t[i];
        adj[i].push_back(t[i]);
        adj[t[i]].push_back(i);
        up[i][0] = t[i];
    }
    for (int i = 0; i < n; ++i) {
        if (!comp[i]) {
            find_comp(i);
            ++cnt;
        }
    }
#ifdef DEBUG
    cout << "comp: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << comp[i] << " ";
    }
    cout << "\n";
#endif
    cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            find_cycle(i);
            ++cnt;
        }
    }
#ifdef DEBUG
    cout << "in_cycle: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << in_cycle[i] << " ";
    }
    cout << "\n";
    cout << "cycle_ind: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << cycle_ind[i] << " ";
    }
    cout << "\n";
    cout << "cycle_size: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << cycle_size[i] << " ";
    }
    cout << "\n";
#endif
    for (int i = 0; i < n; ++i) {
        if (!depth[i] && !in_cycle[i]) {
            find_depth(i);
        }
    }
#ifdef DEBUG
    cout << "depth: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << depth[i] << " ";
    }
    cout << "\n";
#endif
    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        if (comp[a] != comp[b]) {
            cout << -1 << "\n";
            continue;
        }
#ifdef DEBUG
        cout << "\n";
        cout << a << " " << b << "\n";
        cout << in_cycle[a] << " " << in_cycle[b] << "\n";
#endif
        if (in_cycle[a]) {
            if (in_cycle[b]) {
                cout << (cycle_ind[a] - cycle_ind[b] + cycle_size[b]) % cycle_size[b] << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            if (in_cycle[b]) {
                cout << depth[a] + (cycle_ind[jmp(a, depth[a])] - cycle_ind[b] + cycle_size[b]) % cycle_size[b] << "\n";
            } else {
                if (depth[b] < depth[a] && jmp(a, depth[a] - depth[b]) == b) {
                    cout << depth[a] - depth[b] << "\n";
                } else {
                    cout << -1 << "\n";
                }
            }
        }
    }
    return 0;
}
