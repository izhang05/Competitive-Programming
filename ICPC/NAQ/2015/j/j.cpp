/* Author: izhang
 * Time: 09-18-2023 20:17:13
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1225;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];

int pre[mxn];

void dfs(int c) {
    for (auto &i: adj[c]) {
        if (pre[i] == -1) {
            pre[i] = c;
            dfs(i);
        }
    }
}


void test_case() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    map<string, int> ind;
    int cur_ind = 0;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        s += " ";
        vector<string> inp;
        string cur;
        for (auto &j: s) {
            if (j == ' ') {
                inp.push_back(cur);
                cur = "";
            } else {
                cur += j;
            }
        }
        if (ind.find(inp[0]) == ind.end()) {
            ind[inp[0]] = cur_ind++;
        }
        int cur_node = ind[inp[0]];
        for (int j = 1; j < int(inp.size()); ++j) {
            if (ind.find(inp[j]) == ind.end()) {
                ind[inp[j]] = cur_ind++;
            }
            adj[cur_node].push_back(ind[inp[j]]);
            adj[ind[inp[j]]].push_back(cur_node);
        }
    }
    string t1, t2;
    cin >> t1 >> t2;
    if (ind.find(t1) == ind.end()) {
        ind[t1] = cur_ind++;
    }
    if (ind.find(t2) == ind.end()) {
        ind[t2] = cur_ind++;
    }
    int a = ind[t1], b = ind[t2];
    memset(pre, -1, sizeof(pre));
    pre[a] = a;
    dfs(a);
    map<int, string> rev_ind;
    for (auto &i: ind) {
        rev_ind[i.second] = i.first;
    }
    vector<int> sol;
    if (pre[b] == -1) {
        cout << "no route found" << "\n";
        return;
    }
    int cur_node = b;
    while (pre[cur_node] != cur_node) {
        sol.push_back(cur_node);
        cur_node = pre[cur_node];
    }
    sol.push_back(cur_node);

    reverse(sol.begin(), sol.end());
    for (int i = 0; i < int(sol.size()) - 1; ++i) {
        cout << rev_ind[sol[i]] << " ";
    }
    cout << rev_ind[sol.back()] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
