/*
ID: izhang01
TASK: poetry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
}
//#define DEBUG

int main() {
    setIO();
    cout << 1 << "\n";
    int n, m, k;
    cin >> n >> m >> k;
    map<int, vector<int>> words;
    int s, c;
    for (int i = 0; i < n; ++i) {
        cin >> s >> c;
        words[c].push_back(s);
    }
#ifdef DEBUG
    for (pair<int, vector<int>> i : words) {
        cout << i.first << ": ";
        for (int j : i.second) {
            cout << j << " ";
        }
        cout << "\n";
    }
#endif


    return 0;
}
