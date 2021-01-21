/*
ID: izhang01
TASK: revegetate
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
}

const int maxn = 1e5;
vector<pair<int, char> > adj[maxn];
bool visited[maxn];
int num_comp;
int label[maxn];
bool pos = true;

void find_comp(int n) {
    visited[n] = true;
    for (pair<int, int> i : adj[n]) {
        if (!visited[i.first]) {
            find_comp(i.first);
        }
    }
}


void find_pos(int n) {
    visited[n] = true;
    for (pair<int, int> i : adj[n]) {
        if (!visited[i.first]) {
            if (i.second == 'S') {
                label[i.first] = label[n];
            } else {
                label[i.first] = 3 - label[n];
            }
            find_pos(i.first);
        } else {
            if (i.second == 'S') {
                if (label[i.first] != label[n]) {
                    pos = false;
                    return;
                }
            } else {
                if (label[i.first] == label[n]) {
                    pos = false;
                    return;
                }
            }
        }
    }
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    char c;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> c >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            find_comp(i);
            ++num_comp;
        }
    }
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    label[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (!pos) {
            cout << 0 << "\n";
            return 0;
        }
        if (!visited[i]) {
            find_pos(i);
        }
    }
    cout << 1;
    for (int i = 0; i < num_comp; ++i) {
        cout << 0;
    }
    cout << "\n";
    return 0;
}
