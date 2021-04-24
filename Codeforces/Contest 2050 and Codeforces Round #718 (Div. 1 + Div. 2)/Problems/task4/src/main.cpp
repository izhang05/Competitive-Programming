#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505, maxk = 13;
int vert[maxn][maxn], hor[maxn][maxn], sol[maxn][maxn][maxk];

int n, m, k;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    cin >> n >> m >> k;
    if (k % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                cout << -1 << " ";
            }
            cout << -1 << "\n";
        }
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> hor[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vert[i][j];
        }
    }
    memset(sol, 0x3f, sizeof(sol));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sol[i][j][0] = 0;
        }
    }
    for (int d = 1; d <= k / 2; ++d) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int l = 0; l < 4; ++l) {
                    int nx = i + dx[l], ny = j + dy[l];
                    if (valid(nx, ny)) {
                        int di;
                        if (dx[l] == 1) {
                            di = vert[i][j];
                        } else if (dx[l] == -1) {
                            di = vert[i - 1][j];
                        } else if (dy[l] == 1) {
                            di = hor[i][j];
                        } else if (dy[l] == -1) {
                            di = hor[i][j - 1];
                        }
                        sol[i][j][d] = min(sol[i][j][d], sol[nx][ny][d - 1] + di);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cout << 2 * sol[i][j][k / 2] << " ";
        }
        cout << 2 * sol[i][m - 1][k / 2] << "\n";
    }
    return 0;
}




//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//
//template<class T>
//void print(T a) {
//    for (auto i : a) {
//        cout << i << " ";
//    }
//    cout << "\n";
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505, maxk = 13;
//int dist[maxn][maxn], vert[maxn][maxn], hor[maxn][maxn], mcost[maxn][maxn][maxk], visited[maxn][maxn], sol[maxn][maxn][maxk];
//
//int n, m, k;
//
//bool valid(int x, int y) {
//    return x >= 0 && y >= 0 && x < n && y < m;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//    cin >> n >> m >> k;
//    if (k % 2 == 1) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m - 1; ++j) {
//                cout << -1 << " ";
//            }
//            cout << -1 << "\n";
//        }
//        return 0;
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m - 1; ++j) {
//            cin >> hor[i][j];
//        }
//    }
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> vert[i][j];
//        }
//    }
//    memset(mcost, 0x3f, sizeof(mcost));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            int cnt = i * n + j + 1;
//            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
//            q.push({0, {i, j}});
//            dist[i][j] = 0;
//            visited[i][j] = cnt;
//            while (!q.empty()) {
//                pair<int, int> cur = q.top().second;
//                q.pop();
//                int d = abs(cur.first - i) + abs(cur.second - j);
//                mcost[i][j][d] = min(mcost[i][j][d], dist[cur.first][cur.second]);
//                if (d >= k / 2) {
//                    continue;
//                }
//                for (int l = 0; l < 4; ++l) {
//                    int nx = cur.first + dx[l], ny = cur.second + dy[l];
//                    if (valid(nx, ny)) {
//                        if (visited[nx][ny] != cnt) {
//                            visited[nx][ny] = cnt;
//                            int di;
//                            if (dx[l] == 1) {
//                                di = vert[cur.first][cur.second];
//                            } else if (dx[l] == -1) {
//                                di = vert[cur.first - 1][cur.second];
//                            } else if (dy[l] == 1) {
//                                di = hor[cur.first][cur.second];
//                            } else if (dy[l] == -1) {
//                                di = hor[cur.first][cur.second - 1];
//                            }
//                            dist[nx][ny] = dist[cur.first][cur.second] + di;
//                            q.push({dist[nx][ny], {nx, ny}});
//                        }
//                    }
//                }
//            }
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int l = 0; l <= k / 2; ++l) {
//                sol[i][j][l] = mcost[i][j][l];
//            }
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            for (int l = 0; l <= k / 2; ++l) {
//                for (int i1 = 0; i1 <= k / 2; ++i1) {
//                    if (l + i1 <= k / 2) {
//                        sol[i][j][l + i1] = min(sol[i][j][l + i1], sol[i][j][l] + sol[i][j][i1]);
//                    }
//                }
//            }
//        }
//    }
////    for (int i = 0; i <= k / 2; ++i) {
////        for (int j = 0; j < n; ++j) {
////            for (int l = 0; l < m; ++l) {
////                cout << mcost[j][l][i] << " ";
////            }
////            cout << "\n";
////        }
////        cout << "\n";
////    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m - 1; ++j) {
//            cout << 2 * sol[i][j][k / 2] << " ";
//        }
//        cout << 2 * sol[i][m - 1][k / 2] << "\n";
//    }
////    for (int i = 0; i < n; ++i) {
////        for (int j = 0; j < m - 1; ++j) {
////            cout << 2 * mcost[i][j][k / 2] << " ";
////        }
////        cout << 2 * mcost[i][m - 1][k / 2] << "\n";
////    }
//    return 0;
//}
//
