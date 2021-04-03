/*
ID: izhang01
TASK: lightsout
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    freopen("lightsout.out", "w", stderr);
}
//#define DEBUG
const int maxn = 205, inf = 1e9;
int dist[maxn];
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> path;
    path.push_back(0);
    int perim = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n, cur = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
        perim += cur;
        dist[j] = perim;
        path.push_back(cur);
        int k = (i + 2) % n;
        if (a[i].first == a[j].first) {
            if (a[j].second > a[i].second) {
                if (a[k].first < a[j].first) {
                    // 270
                    path.push_back(-2);
                } else {
                    // 90
                    path.push_back(-1);
                }
            } else {
                if (a[k].first > a[j].first) {
                    // 270
                    path.push_back(-2);
                } else {
                    // 90
                    path.push_back(-1);
                }
            }
        } else {
            if (a[j].first > a[i].first) {
                if (a[k].second > a[j].second) {
                    // 270
                    path.push_back(-2);
                } else {
                    // 90
                    path.push_back(-1);
                }
            } else {
                if (a[k].second < a[j].second) {
                    // 270
                    path.push_back(-2);
                } else {
                    // 90
                    path.push_back(-1);
                }
            }
        }
    }
    path.back() = 0;
#ifdef DEBUG
    print(path);
#endif
    for (int i = 0; i < n; ++i) {
        dist[i] = min(dist[i], perim - dist[i]);
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
#endif
    map<vector<int>, int> sub;
    for (int i = 0; i < (int) path.size(); i += 2) {
        for (int j = i; j < (int) path.size(); j += 2) {
            ++sub[vector<int>(path.begin() + i, path.begin() + j + 1)];
        }
    }
#ifdef DEBUG
    cout << "\n";
    for (auto i : sub) {
        print(i.first);
        cout << i.second << "\n\n";
    }
#endif
    int sol = 0, s = path.size();
    for (int i = 2; i < s; i += 2) {
        int cur = 0;
        for (int j = i + 1; j <= s; j += 2) {
            if (sub[vector<int>(path.begin() + i, path.begin() + j)] == 1) {
                cur += dist[j / 2];
                break;
            }
            cur += path[j];
        }
#ifdef DEBUG
        cout << i << " " << cur << " " << dist[i / 2] << "\n";
#endif
        sol = max(sol, cur - dist[i / 2]);
    }
    cout << sol << "\n";
    return 0;
}
