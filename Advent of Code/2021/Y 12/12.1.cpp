#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 25;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
map<string, int> ind;
vector<int> adj[maxn];
bool big[maxn];
int sol = 0;
int n = 0;

void dfs(int c, set<int> vis, bool small = false) {
    if (c == n - 1) {
        ++sol;
        return;
    }
    vis.insert(c);
    for (auto &i: adj[c]) {
        if (!i) {
            continue;
        }
        if (big[i] || vis.find(i) == vis.end() || !small) {
            if (!big[i] && vis.find(i) != vis.end()) {
                dfs(i, vis, true);
            } else {
                dfs(i, vis, small);
            }
        }
    }
}


void test_case() {
    int m = 22;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        s.push_back('-');
        string a;
        int c = -1, d;
        for (auto &j: s) {
            if (j != '-') {
                a.push_back(j);
            } else {
                if (ind.find(a) == ind.end()) {
                    ind[a] = n++;
                }
                if (a[0] < 'a') {
                    big[ind[a]] = true;
                }
                if (c == -1) {
                    c = ind[a];
                } else {
                    d = ind[a];
                }
                a.clear();
            }
        }
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    dfs(0, set<int>{});
    cout << sol << "\n";
}

int main() {
    setIO("12");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
