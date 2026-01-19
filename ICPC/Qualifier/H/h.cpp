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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

}
//using namespace kactl;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];

vector<int> adj_a[mxn];
bool mat[mxn][mxn], vis[mxn];
bool pos = true;
int col[mxn];

vector<int> nodes[2];

void dfs(int c, int cur_col) {
    vis[c] = true;
    col[c] = cur_col;
    nodes[cur_col].push_back(c);
//    cout << c << " " << cur_col << "\n";
    int nxt_col = cur_col ^ 1;
    for (auto &i: adj_a[c]) {
        if (vis[i]) {
            if (col[i] != nxt_col) {
                pos = false;
            }
        } else {
            dfs(i, nxt_col);
        }
    }
}


bool good(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
//            cout << a[i] << " " << a[j] << " " << mat[a[i]][a[j]] << "\n";
            if (!mat[a[i]][a[j]]) {
                return false;
            }
        }
    }
    return true;
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
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        mat[node1][node2] = mat[node2][node1] = true;
    }
    set<int> a, b, c;
    a.insert(0);
    for (auto &i: adj[0]) {
        a.insert(i);
    }
    b.insert(1);
    for (auto &i: adj[1]) {
        b.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (a.find(i) == a.end() && b.find(i) == b.end()) {
            c.insert(i);
        }
    }
    vector<int> v_a(a.begin(), a.end()), v_b(b.begin(), b.end()), v_c(c.begin(), c.end());
    int n_a = v_a.size(), n_b = v_b.size();
//    for (auto &i: v_a) {
//        cout << i << " ";
//    }
//    cout << "\n";
//
//    for (auto &i: v_b) {
//        cout << i << " ";
//    }
//    cout << "\n";
//
//    for (auto &i: v_c) {
//        cout << i << " ";
//    }
//    cout << "\n";
//    cout << "c" << "\n";
//    good(v_c);
//    cout << "c" << "\n";
//    cout << good(v_a) << " " << good(v_b) << " " << good(v_c) << "\n";
    if (!good(v_c) || (!good(v_a) && !good(v_b))) {
        cout << "impossible" << "\n";
        return;
    }
    bool swapped = false;
    if (!good(v_b)) {
        swap(a, b);
        swap(n_a, n_b);
        swap(v_a, v_b);
        swapped = true;
    }

//    for (auto &i: v_a) {
//        cout << i << " ";
//    }
//    cout << "\n";
//
//    for (auto &i: v_b) {
//        cout << i << " ";
//    }
//    cout << "\n";
//
//    for (auto &i: v_c) {
//        cout << i << " ";
//    }
//    cout << "\n";

    for (int i = 0; i < n_a; ++i) {
        for (int j = i + 1; j < n_a; ++j) {
            if (!mat[v_a[i]][v_a[j]]) {
//                cout << v_a[i] << " " << v_a[j] << "\n";
                adj_a[v_a[i]].push_back(v_a[j]);
                adj_a[v_a[j]].push_back(v_a[i]);
            }
        }
    }
//    cout << "\n";


    vector<int> to_erase;
    for (auto &i: v_a) {
        if (vis[i]) {
            continue;
        }
        nodes[0].clear();
        nodes[1].clear();
        dfs(i, 0);
        if (!pos) {
            cout << "impossible" << "\n";
            return;
        }
        bool cur_pos = true;
        for (auto &j: nodes[0]) {
            for (auto &k: v_c) {
                if (!mat[j][k]) {
                    cur_pos = false;
                }
            }
        }
        if (cur_pos) {
            for (auto &j: nodes[0]) {
                v_c.push_back(j);
                to_erase.push_back(j);
            }
        } else {
            for (auto &j: nodes[1]) {
                v_c.push_back(j);
                to_erase.push_back(j);
            }
        }
    }
//    for (auto &i: to_erase) {
//        cout << i << " ";
//    }
//    cout << "\n";

    for (auto &i: to_erase) {
        a.erase(i);
    }
    v_a = vector<int>(a.begin(), a.end());

    if (swapped) {
        swap(v_a, v_b);
    }
    n_a = v_a.size(), n_b = v_b.size();

    if (good(v_a) && good(v_b) && good(v_c)) {
        sort(v_a.begin(), v_a.end());
        sort(v_b.begin(), v_b.end());
        for (int i = 0; i < n_a; ++i) {
            cout << v_a[i] + 1 << " \n"[i == n_a - 1];
        }
        for (int i = 0; i < n_b; ++i) {
            cout << v_b[i] + 1 << " \n"[i == n_b - 1];
        }
    } else {
        cout << "impossible" << "\n";
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
