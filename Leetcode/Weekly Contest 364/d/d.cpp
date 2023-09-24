/* Author: izhang
 * Time: 09-23-2023 22:12:13
**/
#include <bits/stdc++.h>

using namespace std;

#include <debug.h>

class Solution {
private:
    vector<vector<int>> adj;
    vector<int> down, up, par, is_prime;

    bool prime(int x) {
        if (x == 1) {
            return false;
        }
        if (x == 2) {
            return true;
        }
        if (x % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int dfs1(int c, int p) {
        par[c] = p;
        down[c] = 1;
        for (auto &i: adj[c]) {
            if (i != p) {
                down[c] += dfs1(i, c);
            }
        }
        if (is_prime[c]) {
            down[c] = 0;
        }
        return down[c];
    }

    void dfs2(int c, int p) {
        if (p != -1) {
            if (is_prime[p]) {
                up[c] = 0;
            } else {
                up[c] = up[p] + down[p] - down[c];
            }
        }
        for (auto &i: adj[c]) {
            if (i != p) {
                dfs2(i, c);
            }
        }
    }


public:
    long long countPaths(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return 0;
        }
        adj.clear();
        adj.resize(n + 1);
        down.clear();
        up.clear();
        par.clear();
        par.resize(n + 1);
        down.resize(n + 1);
        up.resize(n + 1);
        is_prime.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            is_prime[i] = prime(i);
        }
        for (auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs1(1, -1);
        dfs2(1, -1);
        long long sol = 0;
        for (int i = 1; i <= n; ++i) {
            if (is_prime[i]) {
                vector<long long> cur{up[i]};
                for (auto &j: adj[i]) {
                    if (j != par[i]) {
                        cur.push_back(down[j]);
                    }
                }
//                dbg() << i << " " << cur;
                long long cur_val = 0;
                long long s = 0;
                for (auto &j: cur) {
                    s += j;
                    cur_val -= j * j;
                }
                cur_val += s * s;
                cur_val /= 2;
                sol += cur_val + s;
            }
        }
//        dbg() << down;
//        dbg() << up;
        return sol;
    }
};

int main() {
    int n = 2;
    vector<vector<int>> a{{1, 2}};
    Solution x;
    cout << x.countPaths(n, a) << "\n";
}