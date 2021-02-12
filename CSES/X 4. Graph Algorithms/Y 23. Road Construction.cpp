#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
int parent[maxn], num_comp, s[maxn];
multiset<int> comps;

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

void merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        comps.erase(comps.lower _bound(s[get(x)]));
        comps.erase(comps.lower_bound(s[get(y)]));
        s[get(x)] += s[get(y)];
        comps.insert(s[get(x)]);
        parent[get(y)] = x;
        --num_comp;
    }
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        s[i] = 1;
        num_comp = n;
        comps.insert(1);
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        merge(a, b);
        cout << num_comp << " " << *comps.rbegin() << "\n";
    }
    return 0;
}
