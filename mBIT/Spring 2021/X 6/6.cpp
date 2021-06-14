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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
string grid[maxn];
vector<int> adj[maxn];
int parent[maxn];
set<int> comps;

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        comps.erase(xroot);
        parent[xroot] = yroot;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int n, m;

int ind(int x, int y) {
    return x * m + y;
}

int val(int ind) {
    return grid[ind / m][ind % m] - '0';
}


int main() {
    setIO("6");
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < n * m; ++i) {
        parent[i] = i;
        comps.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur = ind(i, j);
            if (j != m - 1) {
                adj[cur].push_back(ind(i, j + 1));
                adj[ind(i, j + 1)].push_back(cur);
            }
            if (i != n - 1) {
                adj[cur].push_back(ind(i + 1, j));
                adj[ind(i + 1, j)].push_back(cur);
                if (i % 2 == 0) {
                    if (j != m - 1) {
                        adj[cur].push_back(ind(i + 1, j + 1));
                        adj[ind(i + 1, j + 1)].push_back(cur);
                    }
                } else if (j != 0) {
                    adj[cur].push_back(ind(i + 1, j - 1));
                    adj[ind(i + 1, j - 1)].push_back(cur);
                }
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        for (auto &j : adj[i]) {
            if (val(i) == val(j)) {
                merge(i, j);
            }
        }
    }
    return 0;
}




//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
//#endif
//}
//
//template<class T>
//void print(T a, string sep = " ", string end = "\n") {
//    for (auto i : a) {
//        cout << i << sep;
//    }
//    cout << end;
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
//string grid[maxn];
//vector<int> adj[maxn];
//int parent[maxn];
//set<int> comp_a[maxn], comps;
//
//int get(int x) {
//    return parent[x] == x ? x : parent[x] = get(parent[x]);
//}
//
//bool merge(int x, int y) {
//    int xroot = get(x), yroot = get(y);
//    if (xroot != yroot) {
//        comps.erase(xroot);
//        parent[xroot] = yroot;
//        return true;
//    }
//    return false;
//}
//
//bool same(int x, int y) {
//    return get(x) == get(y);
//}
//
//int n, m;
//
//int ind(int x, int y) {
//    return x * m + y;
//}
//
//int val(int ind) {
//    return grid[ind / m][ind % m] - '0';
//}
//
//
//int main() {
//    setIO("6");
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        cin >> grid[i];
//    }
//    for (int i = 0; i < n * m; ++i) {
//        parent[i] = i;
//        comps.insert(i);
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            int cur = ind(i, j);
//            if (j != m - 1) {
//                adj[cur].push_back(ind(i, j + 1));
//                adj[ind(i, j + 1)].push_back(cur);
//            }
//            if (i != n - 1) {
//                adj[cur].push_back(ind(i + 1, j));
//                adj[ind(i + 1, j)].push_back(cur);
//                if (i % 2 == 0) {
//                    if (j != m - 1) {
//                        adj[cur].push_back(ind(i + 1, j + 1));
//                        adj[ind(i + 1, j + 1)].push_back(cur);
//                    }
//                } else if (j != 0) {
//                    adj[cur].push_back(ind(i + 1, j - 1));
//                    adj[ind(i + 1, j - 1)].push_back(cur);
//                }
//            }
//        }
//    }
//    for (int i = 0; i < n * m; ++i) {
//        for (auto &j : adj[i]) {
//            if (val(i) == val(j)) {
//                merge(i, j);
//            }
//        }
//    }
//    for (int i = 0; i < n * m; ++i) {
//        for (auto &j : adj[i]) {
//            if (val(i) != val(j)) {
//                comp_a[get(i)].insert(get(j));
//            }
//        }
//    }
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//    for (auto &i : comps) {
//        q.push({comp_a[i].size(), i});
//    }
//    int sol = 0;
//    while (comps.size() > 1) {
//        pair<int, int> cur = q.top();
//        q.pop();
//        set<int> to_add;
//        for (auto &i : comp_a[cur.second]) {
//            for (auto &j : comp_a[i]) {
//                comp_a[j].erase(i);
//                to_add.insert(j);
//            }
//            merge(i, get(cur.second));
//        }
//        for (auto &i : to_add) {
//            comp_a[get(cur.second)].insert(i);
//            comp_a[i].insert(get(cur.second));
//
//        }
//
//    }
//    return 0;
//}
