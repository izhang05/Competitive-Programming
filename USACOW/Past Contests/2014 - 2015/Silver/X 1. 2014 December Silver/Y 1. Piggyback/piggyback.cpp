///*
//ID: izhang01
//TASK: piggyback
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//clock_t tStart = clock();
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("piggyback.in", "r", stdin);
//    freopen("piggyback.out", "w", stdout);
//}
//
//const int maxn = 40000;
//vector<int> adj[maxn];
//int bes[maxn], els[maxn], to_end[maxn];
//int b, e, p, n, m;
//
//void e_dfs(int node, int cur) {
//    els[node] = cur;
//    for (int i : adj[node]) {
//        if (els[i] > cur + 1) {
//            e_dfs(i, cur + 1);
//        }
//    }
//}
//
//void b_dfs(int node, int cur) {
//    bes[node] = cur;
//    for (int i : adj[node]) {
//        if (bes[i] > cur + 1) {
//            b_dfs(i, cur + 1);
//        }
//    }
//
//}
//
//void p_dfs(int node, int cur) {
//    to_end[node] = cur;
//    for (int i : adj[node]) {
//        if (to_end[i] > cur + 1) {
//            p_dfs(i, cur + 1);
//        }
//    }
//}
//
//
//int main() {
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    setIO();
//    cin >> b >> e >> p >> n >> m;
//    int a, c;
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> c;
//        --a, --c;
//        adj[a].push_back(c);
//        adj[c].push_back(a);
//    }
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    for (int i = 0; i < n; ++i) {
//        bes[i] = 1e9;
//        els[i] = 1e9;
//        to_end[i] = 1e9;
//    }
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    b_dfs(0, 0);
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    e_dfs(1, 0);
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    p_dfs(n - 1, 0);
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    int sol = bes[n - 1] * b + els[n - 1] * e;
//    for (int i = 0; i < n; ++i) {
//        if (bes[i] != -1 && els[i] != -1 && to_end[i] != -1) {
//            sol = min(sol, (int) bes[i] * b + els[i] * e + to_end[i] * p);
////            cout << i << " " << sol << " " << bes[i] * b + els[i] * e + to_end[i] * p << "\n";
//        }
//    }
//
//    cout << sol << "\n";
////    printf("Time taken: %.5fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
//    return 0;
//}

/*
ID: izhang01
TASK: piggyback
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
}


int main() {
    setIO();
    int b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;
    int a, c;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        cin >> a >> c;
        --a, --c;
        adj[a].push_back(c);
        adj[c].push_back(a);
    }
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    queue<pair<int, int> > process; // first = distance, second = index
    process.push(pair<int, int> {0, 0});
    visited[0] = true;
    vector<int> bes(n, -1), els(n, -1), end(n, -1);

    while (!process.empty()) {
        pair<int, int> cur = process.front();
        process.pop();
        bes[cur.second] = cur.first;
        for (int i : adj[cur.second]) {
            if (!visited[i]) {
                visited[i] = true;
                process.push(pair<int, int>{cur.first + 1, i});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    process.push(pair<int, int> {0, 1});
    while (!process.empty()) {
        pair<int, int> cur = process.front();
        process.pop();
        els[cur.second] = cur.first;
        for (int i : adj[cur.second]) {
            if (!visited[i]) {
                visited[i] = true;
                process.push(pair<int, int>{cur.first + 1, i});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    process.push(pair<int, int> {0, n - 1});
    while (!process.empty()) {
        pair<int, int> cur = process.front();
        process.pop();
        end[cur.second] = cur.first;
        for (int i : adj[cur.second]) {
            if (!visited[i]) {
                visited[i] = true;
                process.push(pair<int, int>{cur.first + 1, i});
            }
        }
    }

    int sol = bes[n - 1] * b + els[n - 1] * e;

    for (int i = 0; i < n; ++i) {
        if (bes[i] != -1 && els[i] != -1 && end[i] != -1) {
            sol = min(sol, (int) bes[i] * b + els[i] * e + end[i] * p);
        }
    }

    cout << sol << "\n";

    return 0;
}
