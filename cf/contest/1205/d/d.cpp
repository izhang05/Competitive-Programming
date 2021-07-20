/* Author: izhang05
 * Time: 07-20-2021 15:50:04
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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
vector<pair<int, int>> adj[maxn];

long long sol;
int sub[maxn];
bool visited[maxn];

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i : adj[v]) {
        if (i.first != p && !visited[i.first]) {
            sub[v] += find_size(i.first, v);
        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i : adj[v]) {
        if (i.first != p && !visited[i.first] && sub[i.first] > s / 2) {
            return centroid(i.first, v, s);
        }
    }
    return v;
}

void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
    visited[c] = true;

    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
        }
    }

    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            solve(i.first);
        }
    }
}

void print_sol(int c, int p) {
    for (auto &i : adj[c]) {
        if (i.first != p) {
            cout << c + 1 << " " << i.first + 1 << " " << i.second << "\n";
            print_sol(i.first, c);
        }
    }
}

void dfs(int c, vector<int> w) {
    visited[c] = true;
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            vector<int> cur;
            int mn = w.back();
            i.second = mn;
#ifdef DEBUG
            cout << c << " " << i.first << " " << i.second << "\n";
#endif
            w.pop_back();
            for (int j = 0; j < sub[i.first] - 1; ++j) {
                cur.push_back(w.back() - mn);
#ifdef DEBUG
                cout << "add: " << w.back() << " " << mn << "\n";
#endif
                w.pop_back();
            }
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            dfs(i.first, cur);
        }
    }
}

int main() {
    setIO("6");
    int n;
    cin >> n;
    if (n == 1) {
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 0);
    }
    find_size(0, -1);
    int c = centroid(0, -1, sub[0]);
#ifdef DEBUG
    cout << "c: " << c << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i << " " << sub[i] << "\n";
    }
#endif
    find_size(c, -1);
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << i << " " << sub[i] << "\n";
    }
#endif
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> children;
    for (auto &i : adj[c]) {
        children.push({sub[i.first], vector<int>{i.first}});
    }
    while (children.size() > 2) {
        pair<int, vector<int>> a = children.top();
        children.pop();
        pair<int, vector<int>> b = children.top();
        children.pop();
        vector<int> new_a = a.second;
        for (auto &i : b.second) {
            new_a.push_back(i);
        }
        children.push({a.first + b.first, new_a});
    }
    pair<pair<int, vector<int>>, pair<int, vector<int>>> group;
    group.first = children.top();
#ifdef DEBUG
    cout << group.first.first << ": ";
    print(group.first.second);
#endif
    children.pop();
    if (!children.empty()) {
        group.second = children.top();
        children.pop();
    }
#ifdef DEBUG
    cout << group.second.first << ": ";
    print(group.second.second);
#endif
    int sz = group.first.first;
    vector<int> weights(sz);
    for (int i = 1; i <= sz; ++i) {
        weights[i - 1] = i;
    }
    memset(visited, false, sizeof(visited));
    for (auto &i : group.second.second) {
        visited[i] = true;
    }
    reverse(weights.begin(), weights.end());
#ifdef DEBUG
    cout << "weights: ";
    print(weights);
#endif
    dfs(c, weights);
    for (auto &i : group.second.second) {
        visited[i] = false;
    }
    weights.clear();
    for (int i = 0; i < int(group.second.first); ++i) {
        weights.push_back((i + 1) * (sz + 1));
    }
    reverse(weights.begin(), weights.end());
#ifdef DEBUG
    cout << "weights: ";
    print(weights);
#endif
    dfs(c, weights);
    print_sol(c, -1);
    return 0;
}
