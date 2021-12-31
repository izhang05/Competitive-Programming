/* Author: izhang05
 * Time: 12-30-2021 22:45:22
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int root;
pair<int, int> ask(const vector<int> &a) {
    if (a.empty()) {
        return {-1, -1};
    }
    cout << "? " << a.size();
    for (auto &i : a) {
        cout << " " << i + 1;
    }
    cout << endl;
    pair<int, int> res;
    cin >> res.first >> res.second;
    if (res.first == -1) {
        exit(0);
    }
    --res.first;
    return res;
}
void ans(pair<int, int> sol) {
    cout << "! " << sol.first + 1 << " " << sol.second + 1 << endl;
    string res;
    cin >> res;
    if (res == "Incorrect") {
        exit(0);
    }
}

int depth[maxn], par[maxn];
vector<int> occ[maxn];
bool good[maxn];

void dfs(int c, int p, int d = 0) {
    par[c] = p;
    depth[c] = d;
    occ[d].push_back(c);
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (auto &i : occ) {
        i.clear();
    }
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        good[i] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i;
    }
    pair<int, int> qry = ask(nums);
    root = qry.first;
    int dist = qry.second;
    dfs(root, -1);
    int lo = (dist + 1) / 2, hi = dist, mid, s = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        pair<int, int> res = ask(occ[mid]);
        if (res.second == dist) {
            s = res.first;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    int cur = s;
    while (cur != root) {
        good[cur] = false;
        cur = par[cur];
    }
    vector<int> a;
    for (auto &i : occ[dist - depth[s]]) {
        if (good[i]) {
            a.push_back(i);
        }
    }
    ans({s, ask(a).first});
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
