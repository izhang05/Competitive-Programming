/* Author: izhang05
 * Time: 07-30-2021 10:35:04
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, k = 450, maxn = 2e5 + 5;
int l = 0, r = -1;
struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};
bool changed[maxn];
string s, cur_s;
int cur_sol = 0;
set<char> pos[maxn];

void add(int x, bool right) {
    if (right) {
        bool bad = false;
        char val;
        if (x - 2 >= l) {
            if (changed[x - 2]) {
                if (pos[x - 2].find(s[x]) == pos[x - 2].end()) {
                    bad = true;
                } else {
                    pos[x - 2].erase(s[x]);
                }
            } else if (s[x - 2] == s[x]) {
                bad = true;
            }
        }
    } else {
    }
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    cin >> s;
    cur_s = string(s.begin(), s.end());
    vector<query> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].l >> queries[i].r;
        --queries[i].l, --queries[i].r;
        queries[i].ind = i;
    }
    sort(queries.begin(), queries.end());
    vector<int> sol(m);
    for (auto &i : queries) {
        while (r < i.r) {
            ++r;
            add(r, true);
        }
        while (l > i.l) {
            --l;
            add(l, false);
        }
        while (r > i.r) {
            rem(r);
            --r;
        }
        while (l < i.l) {
            rem(l);
            ++l;
        }
        sol[i.ind] = cur_sol;
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }

    return 0;
}
