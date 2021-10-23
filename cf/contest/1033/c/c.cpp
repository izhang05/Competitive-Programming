/* Author: izhang05
 * Time: 08-24-2021 11:32:57
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int in_deg[maxn];
bool win[maxn];

int main() {
    setIO("");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + a[i]; j < n; j += a[i]) {
            if (a[j] > a[i]) {
                adj[i].push_back(j);
                ++in_deg[j];
            }
        }
        for (int j = i - a[i]; j >= 0; j -= a[i]) {
            if (a[j] > a[i]) {
                adj[i].push_back(j);
                ++in_deg[j];
            }
        }
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto &i : adj[cur]) {
            if (--in_deg[i] == 0) {
                q.push(i);
            }
        }
    }
    reverse(topo.begin(), topo.end());
    for (auto &i : topo) {
        for (auto &j : adj[i]) {
            if (!win[j]) {
                win[i] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << (win[i] ? "A" : "B");
    }
    cout << "\n";
    return 0;
}
