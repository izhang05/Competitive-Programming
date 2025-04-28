/* Author: izhang
 * Time: 02-02-2025 10:05:31
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[mxn][2];
long long dist[mxn][mxn];

void test_case() {
    int n;
    array<int, 2> s;
    cin >> n >> s[0] >> s[1];
    --s[0], --s[1];
    array<int, 2> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            adj[i][j].clear();
        }
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INFL;
        }
    }
    for (int i = 0; i < 2; ++i) {
        cin >> m[i];
        for (int j = 0; j < m[i]; ++j) {
            int node1, node2;
            cin >> node1 >> node2;
            --node1, --node2;
            adj[node1][i].push_back(node2);
            adj[node2][i].push_back(node1);
        }
    }
    dist[s[0]][s[1]] = 0;
    priority_queue<pair<long long, array<int, 2>>, vector<pair<long long, array<int, 2>>>, greater<>> q;
    q.push({0, {s[0], s[1]}});
    while (!q.empty()) {
        pair<long long, array<int, 2>> cur = q.top();
        q.pop();
        if (dist[cur.second[0]][cur.second[1]] != cur.first) {
            continue;
        }
        for (auto &i: adj[cur.second[0]][0]) {
            for (auto &j: adj[cur.second[1]][1]) {
                if (dist[i][j] > cur.first + abs(i - j)) {
                    dist[i][j] = cur.first + abs(i - j);
                    q.push({dist[i][j], {i, j}});
                }
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            dbg() << i << " " << j << " " << dist[i][j];
//        }
//    }
    long long sol = INFL;
    for (int i = 0; i < n; ++i) {
//        dbg() << i << " " << dist[i][i];
        set<int> one;
        for (auto &j: adj[i][0]) {
            one.insert(j);
        }
        bool good = false;
        for (auto &j: adj[i][1]) {
            if (one.find(j) != one.end()) {
                good = true;
                break;
            }
        }
        if (good) {
            sol = min(sol, dist[i][i]);
        }
    }
    cout << (sol == INFL ? -1 : sol) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
