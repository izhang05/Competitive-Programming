/*
ID: izhang01
TASK: mooyomooyo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
}

const int maxn = 100;
int n;
int grid[maxn][10];
set<pair<int, int> > adj[maxn][10];
int comp[maxn][10];
bool visited[maxn][10];
set<pair<int, int> > components[maxn * 10];
int num_comp;

void start_dfs(int node, int dist) {
    assert(node < n);
    assert(dist < 10);
    visited[node][dist] = true;
    components[num_comp].insert(pair<int, int>{node, dist});
    comp[node][dist] = num_comp;
    for (pair<int, int> i : adj[node][dist]) {
        if (!visited[i.first][i.second]) {
            start_dfs(i.first, i.second);
        }
    }
}


int main() {
    setIO();
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            cout << "Start" << "\n";
//            cout << i << " " << j << "\n";
//            for (pair<int, int> k : adj[i][j]) {
//                cout << k.first << " " << k.second << "\n";
//            }
//            cout << "\n";
//        }
//    }

    int to_erase = 1;
    while (to_erase) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (grid[i][j] != 0) {
//                cout << i << " " << j << " " << max(0, i - 1) << " " << max(0, j - 1) << "\n";
                    if (grid[i][j] == grid[max(0, i - 1)][j]) {
                        adj[i][j].insert(pair<int, int>{max(0, i - 1), j});
                        adj[max(i - 1, 0)][j].insert(pair<int, int>{i, j});
                    }
                    if (grid[i][j] == grid[i][max(0, j - 1)]) {
                        adj[i][j].insert(pair<int, int>{i, max(0, j - 1)});
                        adj[i][max(0, j - 1)].insert(pair<int, int>{i, j});
                    }
                }
            }
        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < 10; ++j) {
//                cout << grid[i][j];
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        to_erase = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (!visited[i][j]) {
                    start_dfs(i, j);
                    ++num_comp;
                }
            }
        }

        for (int i = 0; i < num_comp; ++i) {
            if (components[i].size() >= k) {
                ++to_erase;
                for (pair<int, int> j : components[i]) {
                    grid[j.first][j.second] = 0;
                }
            }
            components[i].clear();
        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < 10; ++j) {
//                cout << grid[i][j];
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        for (int j = 0; j < 10; ++j) {
            vector<int> zeroes;
            for (int i = n - 1; i >= 0; --i) {
                if (grid[i][j] == 0) {
                    zeroes.push_back(i);
                } else if (!zeroes.empty()) {
                    grid[zeroes[0]][j] = grid[i][j];
                    grid[i][j] = 0;
                    zeroes.push_back(i);
                    zeroes.erase(zeroes.begin());
                }
                visited[i][j] = false;
                adj[i][j].clear();
            }
        }
        num_comp = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
