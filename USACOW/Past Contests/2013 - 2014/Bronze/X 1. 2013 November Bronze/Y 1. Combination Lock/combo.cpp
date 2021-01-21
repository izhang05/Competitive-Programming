/*
ID: izhang01
TASK: combo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int n;
    cin >> n;
    set<vector<int> > pos;
    vector<int> john(3);
    for (int i = 0; i < 3; ++i) {
        cin >> john[i];
    }
    vector<int> master(3);
    for (int i = 0; i < 3; ++i) {
        cin >> master[i];
    }
    for (int i = john[0] - 2; i <= john[0] + 2; ++i) {
        for (int j = john[1] - 2; j <= john[1] + 2; ++j) {
            for (int k = john[2] - 2; k <= john[2] + 2; ++k) {
                pos.insert(vector<int>{(i + n) % n, (j + n) % n, (k + n) % n});
            }
        }
    }
    for (int i = master[0] - 2; i <= master[0] + 2; ++i) {
        for (int j = master[1] - 2; j <= master[1] + 2; ++j) {
            for (int k = master[2] - 2; k <= master[2] + 2; ++k) {
                pos.insert(vector<int>{(i + n) % n, (j + n) % n, (k + n) % n});
            }
        }
    }

    cout << pos.size() << "\n";
    return 0;
}
