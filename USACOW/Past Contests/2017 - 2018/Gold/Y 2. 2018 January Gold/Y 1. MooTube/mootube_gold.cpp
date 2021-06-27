/*
ID: izhang01
TASK: mootube
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    freopen("mootube.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e5 + 5;
int parent[maxn], depth[maxn], sz[maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
        sz[yroot] += sz[xroot];
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

struct query {
    int k, v, ind;
};

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n - 1; ++i) {
        pair<int, pair<int, int>> cur;
        cin >> cur.second.first >> cur.second.second >> cur.first;
        --cur.second.first, --cur.second.second;
        pq.push(cur);
    }
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].k >> queries[i].v;
        queries[i].ind = i;
        --queries[i].v;
    }
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    sort(queries.begin(), queries.end(), [](auto left, auto right) {
        return left.k > right.k;
    });
    vector<int> sol(q);
    for (auto &i : queries) {
        while (!pq.empty() && pq.top().first >= i.k) {
            merge(pq.top().second.first, pq.top().second.second);
            pq.pop();
        }
        sol[i.ind] = sz[get(i.v)] - 1;
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }

    return 0;
}
