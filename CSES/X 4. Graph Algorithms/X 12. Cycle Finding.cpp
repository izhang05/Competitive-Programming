#include <bits/stdc++.h>

using namespace std;

#define DEBUG

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

const int mod = 1e9 + 7, maxn = 2505;
const long long inf = 1e18;
struct edge {
    int a, b, c;

};
long long dist[maxn];
int par[maxn];

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("12");
    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].a >> e[i].b >> e[i].c;
        --e[i].a, --e[i].b;
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    dist[0] = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        for (auto j : e) {
            if (dist[j.a] + j.c < dist[j.b]) {
                dist[j.b] = dist[j.a] + j.c;
                if (i == n - 1) {
                    par[j.b] = j.a;
                    start = j.b;
                }
            }
        }
    }
    cout << (start ? "YES" : "NO") << "\n";
    if (start) {
        vector<int> cycle;
        for (int i = 0; i < n; ++i) {
            start = par[start];
        }
        for (int v = start;; v = par[v]) {
            cycle.push_back(v + 1);
            if (v == start && cycle.size() > 1) {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        print(cycle);
    }
    return 0;
}
