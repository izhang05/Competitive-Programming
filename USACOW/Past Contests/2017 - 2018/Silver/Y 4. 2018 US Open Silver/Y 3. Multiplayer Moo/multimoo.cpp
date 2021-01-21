/*
ID: izhang01
TASK: multimoo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("multimoo.in", "r", stdin);
//    freopen("multimoo.out", "w", stdout);
}

const int maxn = 251;
int grid[maxn][maxn];
vector<pair<int, int> > adj[maxn][maxn];
vector<pair<int, int> > all_adj[maxn][maxn];
set<int> comp_adj[maxn * maxn];
bool visited[maxn][maxn];
int comp[maxn][maxn];
pair<int, int> components[maxn * maxn]; // first = number, second = size
bool visited_comp[maxn * maxn];
int num_comp;
int one_sol, two_sol;
int cur, len;

void start_dfs(int x, int y) {
    visited[node][dist] = true;
    comp[node][dist] = num_comp;
    for (pair<int, int> i : adj[node][dist]) {
        if (!visited[i.first][i.second]) {
            ++cur;
            start_dfs(i.first, i.second);
        }
    }
}

void second_dfs(int c, pair<int, int> nums) {
    if (nums.first == -1 && nums.second == -1) {
        set<int> pos;
        for (int i : comp_adj[c]) {
            pos.insert(components[i].first);
        }
        for (int i : pos) {
            second_dfs(c, pair<int, int>{components[c].first, i});
//            cout << len << " " << two_sol << "\n";
            two_sol = max(two_sol, len);
            len = components[c].second;
//            cout << len << "\n";
        }
        two_sol = max(two_sol, len);
    }
    else {
        visited_comp[c] = true;
//        cout << c << " " << comp_adj->size() << "\n";
//        assert(c < comp_adj->size());
        for (int i : comp_adj[c]) {
            if ((components[i].first == nums.first || components[i].first == nums.second) && !visited_comp[i]) {
                len += components[i].second;
                cout << i << " " << nums.first << " " << nums.second << endl;
                second_dfs(i, nums);
            }
        }
    }
}


int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            --grid[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        if (grid[0][i] == grid[0][i - 1]) {
            adj[0][i].emplace_back(0, i - 1);
            adj[0][i - 1].emplace_back(0, i);
        }
        all_adj[0][i].emplace_back(0, i - 1);
        all_adj[0][i - 1].emplace_back(0, i);
    }
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == grid[i - 1][0]) {
            adj[i][0].emplace_back(i - 1, 0);
            adj[i - 1][0].emplace_back(i, 0);
        }
        all_adj[i][0].emplace_back(i - 1, 0);
        all_adj[i - 1][0].emplace_back(i, 0);
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == grid[i - 1][j]) {
                adj[i][j].emplace_back(i - 1, j);
                adj[i - 1][j].emplace_back(i, j);
            }
            all_adj[i][j].emplace_back(i - 1, j);
            all_adj[i - 1][j].emplace_back(i, j);
            if (grid[i][j] == grid[i][j - 1]) {
//                cout << i << " " << j << " " << grid[i][j] << "\n";
                adj[i][j].emplace_back(i, j - 1);
                adj[i][j - 1].emplace_back(i, j);
            }
            all_adj[i][j].emplace_back(i, j - 1);
            all_adj[i][j - 1].emplace_back(i, j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                cur = 1;
                start_dfs(i, j);
                one_sol = max(one_sol, cur);
                components[num_comp].first = grid[i][j];
                components[num_comp].second = cur;
//                cout << grid[i][j] << " " << i << " " << j << " " << cur << "\n";
                ++num_comp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (pair<int, int> k : all_adj[i][j]) {
                comp_adj[comp[i][j]].insert(comp[k.first][k.second]);
            }
        }
    }
    cout << one_sol << "\n";
//    cout << "num_comp " << num_comp << "\n";
    for (int i = 0; i < num_comp; ++i) {
        for (int j = 0; j < num_comp; ++j) {
            visited_comp[j] = false;
        }

//        cout << i << "\n";
//        cout << "num_comp " << num_comp << "\n";
        len = components[i].second;
        second_dfs(i, pair<int, int>{-1, -1});
//        cout << i << " " << two_sol << "\n";
    }
    cout << two_sol << "\n";
    return 0;
}
