/*
ID: izhang01
TASK: records
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("records.in", "r", stdin);
    freopen("records.out", "w", stdout);
    int n;
    cin >> n;
    map<string, int> index;
    map<multiset<int>, int> records;
    string s;
    int ind = 0, sol = 1;
    for (int i = 0; i < n; ++i) {
        multiset<int> rec;
        for (int j = 0; j < 3; ++j) {
            cin >> s;
            if (index.find(s) == index.end()) {
                index[s] = ind;
                ++ind;
            }
            rec.insert(index[s]);
        }
        if (records.find(rec) == records.end()) {
            records[rec] = 1;
        } else {
            ++records[rec];
            sol = max(sol, records[rec]);
        }
    }
    cout << sol << "\n";
    return 0;
}

