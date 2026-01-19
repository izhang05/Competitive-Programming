#include <bits/stdc++.h>

using namespace std;


namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Johan Sannemo, Simon Lindholm
     * Date: 2016-12-15
     * License: CC0
     * Description: Finds a minimum vertex cover in a bipartite graph.
     *  The size is the same as the size of a maximum matching, and
     *  the complement is a maximum independent set.
     * Status: stress-tested
     */

/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source:
 * Description: Simple bipartite matching algorithm. Graph  should be a list
 * of neighbors of the left partition, and  should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. $btoa[i]$ will be the match for vertex  on the right side,
 * or $-1$ if it's not matched.
 * Time: O(VE)
 * Usage: vi btoa(m, -1); dfsMatching(g, btoa);
 * Status: works
 */

    bool find(int j, vector<vi> &g, vi &btoa, vi &vis) {
        if (btoa[j] == -1) return 1;
        vis[j] = 1;
        int di = btoa[j];
        for (int e: g[di])
            if (!vis[e] && find(e, g, btoa, vis)) {
                btoa[e] = di;
                return 1;
            }
        return 0;
    }

    int dfsMatching(vector<vi> &g, vi &btoa) {
        vi vis;
        rep(i, 0, sz(g)) {
            vis.assign(sz(btoa), 0);
            for (int j: g[i])
                if (find(j, g, btoa, vis)) {
                    btoa[j] = i;
                    break;
                }
        }
        return sz(btoa) - (int) count(all(btoa), -1);
    }


    vi cover(vector<vi> &g, int n, int m) {
        vi match(m, -1);
        int res = dfsMatching(g, match);
        vector<bool> lfound(n, true), seen(m);
        for (int it: match) if (it != -1) lfound[it] = false;
        vi q, cover;
        rep(i, 0, n) if (lfound[i]) q.push_back(i);
        while (!q.empty()) {
            int i = q.back();
            q.pop_back();
            lfound[i] = 1;
            for (int e: g[i])
                if (!seen[e] && match[e] != -1) {
                    seen[e] = true;
                    q.push_back(match[e]);
                }
        }
        rep(i, 0, n) if (!lfound[i]) cover.push_back(i);
        rep(i, 0, m) if (seen[i]) cover.push_back(n + i);
        assert(sz(cover) == res);
        return cover;
    }

}
//using namespace kactl;

bool edge(string s, string t) {
    int diff = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ++diff;
        }
    }
    return diff == 2;
}

const int mxn = 505;
vector<vector<int>> adj;
int col[mxn];
bool vis[mxn];

void dfs(int c) {
    vis[c] = true;
    for (auto &i: adj[c]) {
        if (!vis[i]) {
            col[i] = col[c] ^ 1;
            dfs(i);
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (edge(s[i], s[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    map<int, int> left, right;
    int ind_left = 0, ind_right = 0;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            col[i] = 0;
            dfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            left[i] = ind_left++;
        } else {
            right[i] = ind_right++;
        }
    }

    vector<vector<int>> gr(left.size());
    for (int i = 0; i < n; ++i) {
        if (col[i] == 0) {
            for (auto &j: adj[i]) {
                gr[left[i]].push_back(right[j]);
            }
        }
    }


//    for (int i = 0; i < left.size(); ++i) {
//        cout << i << ": ";
//        for (auto &j: gr[i]) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
//    for (int i = 0; i < n; ++i) {
//        cout << i << " " << col[i] << "\n";
//    }
//    vector<int> cover = kactl::cover(adj, left.size(), r);
//    for (auto &i: cover) {
//        cout << i << " ";
//    }
//    cout << "\n";
    cout << n - kactl::cover(gr, left.size(), right.size()).size() << "\n";
}
