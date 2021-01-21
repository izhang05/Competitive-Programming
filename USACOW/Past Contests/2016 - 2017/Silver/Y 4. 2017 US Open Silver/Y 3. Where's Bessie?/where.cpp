#include <bits/stdc++.h>
using namespace std;
ifstream fin("where.in");
ofstream fout("where.out");

struct PCL {
    int i1, j1, i2, j2;
};

const int MXN = 21;
int n;
string grid[MXN];
bool visited[MXN][MXN];
vector<PCL> locations;

const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};

void floodfill(int i, int j, char letter, int i1, int j1, int i2, int j2) {
    if (i < i1 || i > i2 || j < j1 || j > j2 || visited[i][j] || letter != grid[i][j]) return;
    visited[i][j] = true;
    for (int i = 0; i < 4; i++) floodfill(xd[i], yd[i], letter, i1, j1, i2, j2);
}

bool checkPCL(int i1, int j1, int i2, int j2) {
    int letters = 0;
    int distinct[26] = {0};
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            if (!visited[i][j]) {
                if (distinct[grid[i][j] - 'A'] == 0) letters++;
                distinct[grid[i][j] - 'A']++;
                floodfill(i, j, grid[i][j], i1, j1, i2, j2);
            }
        }
    }
    if (letters != 2) return false;
    bool one = false, many = false;
    for (int i : distinct) {
        if (i == 1) one = true;
        if (i > 1) many = true;
    }
    return one && many;
}

bool insidePCL(int x, int y) {
    return locations[x].i1 >= locations[y].i1 && locations[x].i2 <= locations[y].i2 && locations[x].j1 >= locations[y].j1 && locations[x].j2 <= locations[y].j2;
}

bool PCL_maximal(int x) {
    for (int i = 0; i < locations.size(); i++)
        if (i != x && insidePCL(x, i)) return false;
    return true;
}


int main() {
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> grid[i];
    }
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < n; j1++) {
            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = j1; j2 < n; j2++) {
                    if (checkPCL(i1, j1, i2, j2)) {
                        locations.push_back({i1, j1, i2, j2});
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < locations.size(); i++) {
        if (PCL_maximal(i)) ans++;
    }
    fout << ans;
}


///*
//ID: izhang01
//TASK: where
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
//    freopen("where.in", "r", stdin);
//    freopen("where.out", "w", stdout);
//}
//
//const int maxn = 20;
//char grid[maxn][maxn];
//vector<pair<int, int> > adj[maxn][maxn];
//bool visited[maxn][maxn];
//set<char> letters;
//map<char, int> comps;
//
//void start_dfs(int node, int dist) {
//    visited[node][dist] = true;
//    for (pair<int, int> i : adj[node][dist]) {
//        if (!visited[i.first][i.second]) {
//            start_dfs(i.first, i.second);
//        }
//    }
//}
//
//
//bool in(pair<pair<int, int>, pair<int, int> > x, pair<pair<int, int>, pair<int, int> > y) {
//    if (x.first.first >= y.first.first) {
//        if (x.first.second >= y.first.second) {
//            if (x.second.first <= y.second.first) {
//                if (x.second.second <= y.second.second) {
//                    return true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    string s;
//    for (int i = 0; i < n; ++i) {
//        cin >> s;
//        for (int j = 0; j < n; ++j) {
//            grid[i][j] = s[j];
//        }
//    }
//    set<pair<pair<int, int>, pair<int, int> > > sol;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int k = i + 1; k < n + 1; ++k) {
//                for (int l = j + 1; l < n + 1; ++l) {
////                    cout << i << " " << j << " " << k << " " << l << " " << "hi" << "\n";
//                    if (i == 2 && j == 5 && k == 6 && l == 6) {
//
//                    }
//                    letters.clear();
//                    for (int m = i; m < k; ++m) {
//                        for (int o = j; o < l; ++o) {
//                            visited[m][o] = false;
//                            adj[m][o].clear();
//                            letters.insert(grid[m][o]);
//                        }
//                    }
//                    if (letters.size() != 2) {
//                        continue;
//                    }
//                    for (int m = i; m < k; ++m) {
//                        for (int o = j; o < l; ++o) {
//                            if (m != i && grid[m][o] == grid[m - 1][o]) {
//                                adj[m][o].emplace_back(m - 1, o);
//                                adj[m - 1][o].emplace_back(m, o);
//                            }
//                            if (o != j && grid[m][o] == grid[m][o - 1]) {
//                                adj[m][o].emplace_back(m, o - 1);
//                                adj[m][o - 1].emplace_back(m, o);
//                            }
//                        }
//                    }
//
//                    vector<char> let;
//                    for (char m : letters) {
//                        comps[m] = 0;
//                        let.push_back(m);
//                    }
//                    for (int m = i; m < k; ++m) {
//                        for (int o = j; o < l; ++o) {
//                            if (!visited[m][o]) {
//                                start_dfs(m, o);
//                                ++comps[grid[m][o]];
//                            }
//                        }
//                    }
//                    if ((comps[let[0]] == 1 && comps[let[1]] >= 2) ||
//                        (comps[let[1]] == 1 && comps[let[0]] >= 2)) {
////                            cout << i << " " << j << " " << k - 1 << " " << l - 1 << " " << let[0] << " "
////                                 << let[1] << " " << comps[let[0]] << " " << comps[let[1]] << "\n";
//
//                        pair<pair<int, int>, pair<int, int> > rect{pair<int, int>{i, j}, {k, l}};
////                            sol.insert(rect);
//                        set<pair<pair<int, int>, pair<int, int> > > to_erase;
//                        bool inside = false;
////                        cout << i << " " << j << " " << k << " " << l << "\n";
//                        if (sol.empty()) {
//                            sol.insert(rect);
//                        } else {
//                            for (auto p : sol) {
//                                if (in(p, rect)) {
//                                    to_erase.insert(p);
//                                }
//                                if (in(rect, p)) {
//                                    inside = true;
//                                }
//                            }
//                        }
//                        for (auto p : to_erase) {
//                            sol.erase(p);
//                        }
//                        if (!inside) {
//                            sol.insert(rect);
////                            cout << i << " " << j << " " << k << " " << l << "\n";
//                        }
//                    }
//                }
//            }
//        }
//    }
//
////    for (auto p : sol) {
////        cout << p.first.first << " " << p.first.second << " " << p.second.first - 1 << " " << p.second.second - 1
////             << "\n";
////    }
////    set<int> del;
////    vector<pair<pair<int, int>, pair<int, int> > > v(sol.begin(), sol.end());
////    for (int i = 0; i < v.size(); ++i) {
////        for (int j = i + 1; j < v.size(); ++j) {
////            if (in(v[i], v[j])) {
//////                cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " "
//////                     << v[i].second.second << "\n";
//////                cout << v[j].first.first << " " << v[j].first.second << " " << v[j].second.first << " "
//////                     << v[j].second.second << "\n";
////                del.insert(i);
////            } else if (in(v[j], v[i])) {
////                del.insert(j);
////            }
////        }
////    }
//    cout << sol.size() << "\n";
////    cout << del.size() << "\n";
////    int a = (int) sol.size() - del.size();
////    cout << a << "\n";
////    cout << del << "\n";
//    return 0;
//}
