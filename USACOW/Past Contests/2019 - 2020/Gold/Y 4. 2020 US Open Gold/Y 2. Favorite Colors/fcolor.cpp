///*
//ID: izhang01
//TASK: fcolor
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("fcolor.in", "r", stdin);
//    freopen("fcolor.out", "w", stdout);
//}
//
//template<class T>
//void print(T a) {
//    for (auto i : a) {
//        cout << i << " ";
//    }
//    cout << "\n";
//}
//
//const int maxn = 2e5 + 5;
//int parent[maxn];
//vector<int> adj[maxn];
//
//int get(int x) {
//    return parent[x] == x ? x : parent[x] = get(parent[x]);
//}
//
//bool merge(int x, int y) {
//    int xroot = get(x), yroot = get(y);
//    if (xroot == yroot) {
//        return false;
//    }
//    if (xroot != yroot) {
//        parent[xroot] = parent[x] = yroot;
//        adj[yroot].insert(adj[yroot].begin(), adj[xroot].begin(), adj[xroot].end());
//        adj[xroot].clear();
//    }
//    return true;
//}
//
//
//int main() {
//    setIO();
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        parent[i] = i;
//    }
//    int a, b;
//    for (int i = 0; i < m; i++) {
//        cin >> a >> b;
//        --a, --b;
//        adj[a].push_back(b);
//    }
//    for (int i = 0; i < n; ++i) {
//        if (adj[i].size() >= 2) {
//            for (int j = 1; j < adj[i].size(); ++j) {
//                merge(adj[i][0], adj[i][j]);
//            }
//        }
//    }
////    for (int i = 0; i < n; ++i) {
////        cout << i << " " << get(i) << "\n";
////    }
//    bool merged = true;
//    while (merged) {
//        merged = false;
//        for (int i = 0; i < n; ++i) {
//            if (parent[i] == i) {
//                if (adj[i].size() >= 2) {
//                    for (int j = 1; j < adj[i].size(); ++j) {
//                        merged |= merge(adj[i][0], adj[i][j]);
//                    }
//                }
//            }
//        }
//    }
//    vector<int> sol(n);
//    int next_sol = 1;
//    for (int i = 0; i < n; ++i) {
//        if (!sol[get(i)]) {
//            sol[i] = sol[get(i)] = next_sol++;
//        } else {
//            sol[i] = sol[get(i)];
//        }
//        cout << sol[i] << "\n";
//    }
//    //        vector<int> d{1, 2, 3, 1, 1, 2, 3, 2, 3};
//    //        for (int i : d) {
//    //            cout << i << "\n";
//    //        }
//    return 0;
//}

/*
ID: izhang01
TASK: fcolor
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
}

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

const int maxn = 2e5 + 5;
int parent[maxn];
vector<int> adj[maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot == yroot) {
        return false;
    }
    if (xroot != yroot) {
        parent[xroot] = parent[x] = yroot;
        unordered_set<int> s;
        for (int i : adj[yroot]) {
            s.insert(i);
        }
        for (int i : adj[xroot]) {
            s.insert(i);
        }
        adj[xroot].clear();
        adj[yroot].assign(s.begin(), s.end());
        if (adj[yroot].size() >= 2) {
            int f = adj[yroot][0];
            for (int j = 1; j < adj[yroot].size(); ++j) {
                merge(adj[yroot][0], adj[yroot][j]);
            }
            adj[yroot].clear();
            adj[yroot].push_back(f);
        }
    }
    return true;
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() >= 2) {
            for (int j = 1; j < adj[i].size(); ++j) {
                merge(adj[i][0], adj[i][j]);
            }
        }
    }
    vector<int> sol(n);
    int next_sol = 1;
    for (int i = 0; i < n; ++i) {
        if (!sol[get(i)]) {
            sol[i] = sol[get(i)] = next_sol++;
        } else {
            sol[i] = sol[get(i)];
        }
        cout << sol[i] << "\n";
    }
    return 0;
}
