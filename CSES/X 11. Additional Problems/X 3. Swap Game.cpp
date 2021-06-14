#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
map<vector<int>, int> dist;

vector<pair<int, int>> swaps{{0,1},{}};

int main() {
    setIO("3");
    int n = 9;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    queue<pair<int, vector<int>>> q;
    q.push({0, a});
    dist[a] = 0;
    while (!q.empty()) {
        pair<int, vector<int>> cur = q.front();
        q.pop();

    }
    return 0;
}
