#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6, goal = .99 * 1e6, maxs = 1e8, minister = 524287;

int par[maxn], depth[maxn], sz[maxn], s[maxs];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        sz[yroot] += sz[xroot];
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int main() {
    for (int i = 0; i < maxn; ++i) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= 55; ++i) {
        s[i] = (100003 - 200003 * i + ((300007 * i % maxn) * i % maxn) * i) % maxn;
    }
    for (int i = 56; i < maxs; ++i) {
        s[i] = (s[i - 24] + s[i - 55]) % maxn;
    }
    int cnt = 0, cur = 1;
    while (sz[get(minister)] < goal) {
        int a = s[2 * cur - 1], b = s[2 * cur];
        if (a != b) {
            ++cnt;
            merge(a, b);
        }
        ++cur;
    }
    cout << cnt << "\n";
    return 0;
}
