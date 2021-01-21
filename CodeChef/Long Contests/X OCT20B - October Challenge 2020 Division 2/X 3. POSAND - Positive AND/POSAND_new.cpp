#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("curution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5, maxlog = 20;
bool visited[maxn];
vector<int> cur, sol, num_comp[maxlog], comp[maxn]; // num_comp = numbers in each comp; comp = comps which num belongs to
int n;

void dfs(int node) {
    if (cur.size() == n) {
        sol = cur;
        return;
    }
    for (int i : comp[node]) {
        for (int j : num_comp[i]) {
            if (!visited[j]) {
                visited[j] = true;
                cur.push_back(j);
                dfs(j);
                if (!sol.empty()) {
                    return;
                }
                cur.erase(--cur.end());
                visited[j] = false;
            }
        }
    }
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            comp[i].clear();
        }
        for (auto i : num_comp) {
            i.clear();
        }
        sol.clear();
        for (unsigned int i = 0; i < n; ++i) { // nlogn
            for (unsigned int j = 0; j < maxlog; ++j) {
                if ((i + 1) & (1 << j)) {
                    num_comp[j].push_back(i);
                    comp[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cur.clear();
            memset(visited, false, sizeof(visited));
            if (!sol.empty()) {
                break;
            }
            visited[i] = true;
            cur.push_back(i);
            dfs(i);
        }
        if (!sol.empty()) {
            for (int i : sol) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
