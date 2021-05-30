#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 26;

vector<pair<int, int>> adj[maxn];
bool visited[maxn];
int sol = -inf, cur;

void dfs(int c, int d = 0) {
    visited[c] = true;
    for (auto &i : adj[c]) {
        if (i.first == cur) {
            sol = max(sol, d + i.second);
        } else if (!visited[i.first]) {
            dfs(i.first, d + i.second);
        }
    }
    visited[c] = false;
}

int find_max_weight(string graph) {
    graph += " ";
    for (int next = 0; next < (int) graph.size();) {
        int a = graph[next] - 'A', b = graph[next + 1] - 'A';
        next += 3;
        string c;
        while (graph[next] != ' ') {
            c += graph[next++];
        }
        ++next;
        adj[a].emplace_back(b, stoi(c));
#ifdef DEBUG
        cout << a << " " << b << " " << c << "\n";
#endif
    }
    for (int i = 0; i < maxn; ++i) {
        cur = i;
        dfs(i);
#ifdef DEBUG
        cout << i << " " << sol << "\n";
#endif
    }
    if (sol == -inf) {
        return 0;
    } else {
        return sol;
    }
}

int main() {
    setIO("d");
    string graph;
    getline(cin, graph);

    int result = find_max_weight(graph);

    cout << "result: " << result << "\n";

    return 0;
}
