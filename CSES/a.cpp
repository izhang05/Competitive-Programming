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
const int mod = 1e9 + 7, maxn = 5e3 + 5, maxo = 105;
const long long inf = 1e18;

string s;
int p, m, t, ind = 0, n, node = 0;
vector<int> adj[maxn];
long long mn[maxn][maxn], mx[maxn][maxo];
bool pls;

void dfs() {
    char cur = s[ind++];
    int a = -1, b, c = node;
    if (cur == '(') {
        a = ++node;
        dfs();
        cur = s[ind++];
    }
    if (cur == '?') {
        b = ++node;
        dfs();
        assert(a != -1);
        if (pls) {
            for (int i = 0; i <= p; ++i) {
                for (int j = 0; i + j <= p; ++j) {
                    if (i + j < p) {
                        mx[c][i + j + 1] = max(mx[c][i + j + 1], mx[a][i] + mx[b][j]);
                        mn[c][i + j + 1] = min(mn[c][i + j + 1], mn[a][i] + mn[b][j]);
                    }
                    mx[c][i + j] = max(mx[c][i + j], mx[a][i] - mn[b][j]);
                    mn[c][i + j] = min(mn[c][i + j], mn[a][i] - mx[b][j]);
                }
            }
        } else {
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; i + j <= m; ++j) {
                    if (i + j < m) {
                        mx[c][i + j + 1] = max(mx[c][i + j + 1], mx[a][i] - mn[b][j]);
                        mn[c][i + j + 1] = min(mn[c][i + j + 1], mn[a][i] - mx[b][j]);
                    }
                    mx[c][i + j] = max(mx[c][i + j], mx[a][i] + mx[b][j]);
                    mn[c][i + j] = min(mn[c][i + j], mn[a][i] + mn[b][j]);
                }
            }
        }
    } else if (cur != ')') {
        mx[c][0] = mn[c][0] = cur - '0';
    }
    while (ind < n && s[ind] == ')') {
        ++ind;
    }
}

int main() {
    setIO("1");

    cin >> s >> p >> m;
    n = s.size(), t = p + m;
    if (p <= m) {
        pls = true;
    } else {
        pls = false;
    }
    for (auto &i : mn) {
        for (auto &j : i) {
            j = inf;
        }
    }
    for (auto &i : mx) {
        for (auto &j : i) {
            j = -inf;
        }
    }
    dfs();
#ifdef DEBUG
    for (int i = 0; i < (int) s.size(); ++i) {
        for (int j = 0; j <= p; ++j) {
            cout << i << " " << j << " " << mx[i][j] << " " << mn[i][j] << "\n";
        }
    }
#endif
    if (pls) {
        cout << mx[0][p] << "\n";
    } else {
        cout << mx[0][m] << "\n";
    }
    return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define DEBUG
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
//const int mod = 1e9 + 7, maxn = 1000, maxo = 105;
//const long long inf = 1e18;
//
//string s;
//int p, m, t, ind = 0, n, node = 0;
//vector<int> adj[maxn];
//long long mn[maxn][maxn], mx[maxn][maxo];
//
//long long dfs() {
//    char cur = s[ind++];
//    if (cur >= '0' && cur <= '9') {
//        while (ind < n && s[ind] == ')') {
//            ++ind;
//        }
//        while (ind < n && s[ind] == ')') {
//            ++ind;
//        }
//        return cur - '0';
//    }
//    if (cur == ')') {
//        while (ind < n && s[ind] == ')') {
//            ++ind;
//        }
//        return 10;
//    }
//    ++node;
//    long long a = -1, b = -1, c = node, a_v = -2;
//    if (cur == '(') {
//        a_v = dfs();
//        if (a_v == -1) {
//            a = node;
//        }
//        cur = s[ind++];
//    }
//    if (cur == '?') {
//        assert(a_v != -2);
//        long long b_v = dfs();
//        if (b_v == -1) {
//            b = node;
//        }
//#ifdef DEBUG
//        cout << c << " " << a << " " << b << " " << a_v << " " << b_v << "\n";
//#endif
//        if (a == -1) {
//            if (b == -1) {
//                mx[c][1] = mn[c][1] = a_v + b_v;
//                mx[c][0] = mn[c][0] = a_v - b_v;
//            } else {
//                for (int j = 0; j <= p; ++j) {
//                    if (j < p) {
//                        mx[c][j + 1] = max(mx[c][j + 1], a_v + mx[b][j]);
//                        mn[c][j + 1] = min(mn[c][j + 1], a_v + mn[b][j]);
//                    }
//                    mx[c][j] = max(mx[c][j], a_v - mn[b][j]);
//                    mn[c][j] = min(mn[c][j], a_v - mx[b][j]);
//                }
//            }
//        } else {
//            if (b == -1) {
//                for (int i = 0; i <= p; ++i) {
//                    if (i < p) {
//                        mx[c][i + 1] = max(mx[c][i + 1], mx[a][i] + b_v);
//                        mn[c][i + 1] = min(mn[c][i + 1], mn[a][i] + b_v);
//                    }
//                    mx[c][i] = max(mx[c][i], mx[a][i] - b_v);
//                    mn[c][i] = min(mn[c][i], mn[a][i] - b_v);
//                }
//            } else {
//                for (int i = 0; i <= p; ++i) {
//                    for (int j = 0; i + j <= p; ++j) {
//                        if (i + j < p) {
//                            mx[c][i + j + 1] = max(mx[c][i + j + 1], mx[a][i] + mx[b][j]);
//                            mn[c][i + j + 1] = min(mn[c][i + j + 1], mn[a][i] + mn[b][j]);
//                        }
//                        mx[c][i + j] = max(mx[c][i + j], mx[a][i] - mn[b][j]);
//                        mn[c][i + j] = min(mn[c][i + j], mn[a][i] - mx[b][j]);
//                    }
//                }
//            }
//        }
//    }
//    while (ind < n && s[ind] == ')') {
//        ++ind;
//    }
//    return -1;
//}
//
//int main() {
//    setIO("1");
//
//    cin >> s >> p >> m;
//    n = s.size(), t = p + m;
//    for (auto &i : mn) {
//        for (auto &j : i) {
//            j = inf;
//        }
//    }
//    for (auto &i : mx) {
//        for (auto &j : i) {
//            j = -inf;
//        }
//    }
//    dfs();
//#ifdef DEBUG
//    for (int i = 0; i < (int) s.size(); ++i) {
//        for (int j = 0; j <= p; ++j) {
//            cout << i << " " << j << " " << mx[i][j] << " " << mn[i][j] << "\n";
//        }
//    }
//#endif
//    cout << mx[0][p] << "\n";
//    return 0;
//}
