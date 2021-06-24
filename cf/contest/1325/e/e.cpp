/* Author: izhang05
 * Time: 06-23-2021 21:00:31
**/
#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr \
    if (false) cerr
#endif
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxp = 8e4;

vector<int> factor(int x) {
    map<int, int> occ;
    while (x % 2 == 0) {
        ++occ[2];
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++occ[i];
            x /= i;
        }
    }
    if (x > 1) {
        ++occ[x];
    }
    vector<int> res;
    for (auto &i : occ) {
        if (i.second % 2 == 1) {
            res.push_back(i.first);
        }
    }
    assert(res.size() <= 2);
    return res;
}

vector<int> adj[maxp];
int visited[maxp], dist[maxp];

int main() {
    setIO("1");

    int n;
    cin >> n;
    set<pair<int, int>> edges;
    set<int> primes;
    bool dup = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        vector<int> cur = factor(a);
        if (cur.empty()) {
            cout << 1 << "\n";
            return 0;
        }
        if (cur.size() == 1) {
            cur.push_back(1);
        }
        if (edges.find({cur[0], cur[1]}) != edges.end()) {
            dup = true;
        }
        edges.insert({cur[0], cur[1]});
        primes.insert(cur[0]);
        primes.insert(cur[1]);
    }
    if (dup) {
        cout << 2 << "\n";
        return 0;
    }
    vector<int> nodes(primes.begin(), primes.end());
    map<int, int> ind_of_prime;
    for (int i = 0; i < int(nodes.size()); ++i) {
        ind_of_prime[nodes[i]] = i;
    }
    for (auto &i : edges) {
        adj[ind_of_prime[i.first]].push_back(ind_of_prime[i.second]);
        adj[ind_of_prime[i.second]].push_back(ind_of_prime[i.first]);
    }
    int sol = inf, ind = 1;
    for (int i = 0; i < int(nodes.size()); ++i) {
        if (nodes[i] * nodes[i] > int(1e6)) {
            break;
        }
        queue<pair<int, int>> q;
        q.push({i, -1});
        visited[i] = ind;
        dist[i] = 0;
        while (!q.empty()) {
            int cur = q.front().first, par = q.front().second, cur_dist = dist[cur];
            q.pop();
            for (auto &j : adj[cur]) {
                if (visited[j] != ind) {
                    q.push({j, cur});
                    dist[j] = cur_dist + 1;
                    visited[j] = ind;
                } else {
                    if (j != par) {
                        sol = min(sol, cur_dist + dist[j] + 1);
                    }
                }
            }
        }
        ++ind;
    }
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}
