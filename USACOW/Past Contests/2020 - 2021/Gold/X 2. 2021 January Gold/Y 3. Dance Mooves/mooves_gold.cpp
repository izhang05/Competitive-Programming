#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG

const int maxn = 1e5 + 5;
set<pair<int, int>> s[maxn];
int adj[maxn];

bool visited[maxn];
int main() {
    setIO();

    int n, k;
    long long m;
    cin >> n >> k >> m;
    vector<pair<int, int>> swaps(k);
    for (int i = 0; i < k; ++i) {
        cin >> swaps[i].first >> swaps[i].second;
        --swaps[i].first, --swaps[i].second;
    }
    vector<int> cow(n);
    for (int i = 0; i < n; ++i) {
        cow[i] = i;
        s[i].insert({0, i});
    }
#ifdef DEBUG
    cout << "Cow: "
         << "\n";
    print(cow);
#endif
    for (int i = 0; i < k; ++i) {
        s[cow[swaps[i].first]].insert({i + 1, swaps[i].second});
        s[cow[swaps[i].second]].insert({i + 1, swaps[i].first});
        swap(cow[swaps[i].first], cow[swaps[i].second]);
#ifdef DEBUG
        print(cow);
#endif
    }
#ifdef DEBUG
    cout << "\ns:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ":\n";
        for (pair<int, int> j : s[i]) {
            cout << j.first << " " << j.second << "\n";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    for (int i = 0; i < n; ++i) {
        adj[cow[i]] = i;
    }
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        bool loops = false;
        int cur = i, next = cur;
        if (sol[cur]) {
            continue;
        }
        map<int, int> pos;
        for (long long j = 0; j < m / k; ++j) {
            for (pair<int, int> l : s[next]) {
                ++pos[l.second];
            }
            next = adj[next];
            if (next == cur) {
                loops = true;
                break;
            }
        }
        for (pair<int, int> l : s[next]) {
            if (l.first > m % k) {
                continue;
            }
            ++pos[l.second];
        }
        sol[cur] = pos.size();
        while (!sol[adj[cur]]) {
            if (!loops) {
                for (pair<int, int> l : s[next]) {
                    if (l.first > m % k) {
                        ++pos[l.second];
                    }
                }
                next = adj[next];
                for (pair<int, int> l : s[next]) {
                    if (l.first > m % k) {
                        continue;
                    }
                    ++pos[l.second];
                }
                for (pair<int, int> l : s[cur]) {
                    if (--pos[l.second] == 0) {
                        pos.erase(l.second);
                    }
                }
            }
            cur = adj[cur];
            sol[cur] = pos.size();
        }
    }
    print(sol, "\n");
    return 0;
}