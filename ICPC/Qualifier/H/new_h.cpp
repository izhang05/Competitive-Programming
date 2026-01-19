/* Author: izhang
 * Time: 10-19-2025 11:58:55
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

vector<int> adj[mxn];
bool mat[mxn][mxn];
set<int> pos_col[mxn];
int col[mxn];
bool pos = true;

vector<int> nxt_a, nxt_b;
vector<int> visited;
set<int> restore[mxn];


void dfs(int c, int cur_col) {
    visited.push_back(c);
    restore[c] = pos_col[c];
    col[c] = cur_col;
    for (auto &i: adj[c]) {
        if (col[i] == col[c]) {
            pos = false;
        } else if (col[i] == -1) {
            if (restore[i].empty()) {
                restore[i] = pos_col[i];
            }
            pos_col[i].erase(cur_col);
            if (pos_col[i].empty()) {
                pos = false;
            }
            if (pos_col[i].size() == 1) {
                dfs(i, *pos_col[i].begin());
            }
        }
    }
}


void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        mat[i][i] = true;
    }
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
//        adj[node1].push_back(node2);
//        adj[node2].push_back(node1);
        mat[node1][node2] = mat[node2][node1] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!mat[i][j]) {
                adj[i].push_back(j);
            }
        }
    }
    memset(col, -1, sizeof(col));
    col[0] = 0;
    col[1] = 1;
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            pos_col[i].insert(j);
        }
    }
    for (auto &i: adj[0]) {
        pos_col[i].erase(0);
    }
    for (auto &i: adj[1]) {
        pos_col[i].erase(1);
    }
    for (int round = 0; round < 2 * n; ++round) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
//            cout << i << " " << col[i] << " " << pos_col[i].size() << "\n";
            if (col[i] != -1) {
                continue;
            }
            if (pos_col[i].size() == 0) {
//                cout << i << " " << col[i] << " " << "none" << "\n";
                pos = false;
            } else {
                if (pos_col[i].size() == 1) {
                    found = true;
                    col[i] = *pos_col[i].begin();
                    for (auto &j: adj[i]) {
                        if (col[j] == col[i]) {
                            pos = false;
                        }
                        pos_col[j].erase(col[i]);
                    }
                }
            }
        }
        if (!found) {
            break;
        }
    }
    pos = true;
    for (int i = 0; i < n; ++i) {
        if (col[i] != -1) {
            continue;
        }
//        cout << i << "\n";
        set<int> cur = pos_col[i];
        for (auto &j: cur) {
            dfs(i, j);
            if (pos || j == *pos_col[i].rbegin()) {
                for (auto &k: visited) {
                    restore[k].clear();
                }
                break;
            }
            pos = true;
            for (auto &k: visited) {
                col[k] = -1;
                pos_col[k] = restore[k];
                restore[k].clear();
            }
        }
        if (!pos) {
            break;
        }
    }

//    for (auto &i: adj[0]) {
//        if (col[i] == -1) {
//            nxt_a.push_back(i);
//        }
//    }
//    for (auto &i: adj[1]) {
//        if (col[i] == -1) {
//            nxt_b.push_back(i);
//        }
//    }


    if (!pos) {
        cout << "impossible" << "\n";
    } else {
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            if (col[i] == 0) {
                a.push_back(i);
            } else if (col[i] == 1) {
                b.push_back(i);
            }
        }
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; ++i) {
            cout << a[i] + 1 << " \n"[i == na - 1];
        }
        for (int i = 0; i < nb; ++i) {
            cout << b[i] + 1 << " \n"[i == nb - 1];
        }
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
