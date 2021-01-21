/*
ID: izhang01
TASK: cardgame
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
}


int main() {
    setIO();
    set<int, greater<int>> f, bessie_f;
    set<int> s, total, bessie_s;
    int n;
    cin >> n;
    int c;
    for (int i = 0; i < n / 2; ++i) {
        cin >> c;
        f.insert(c);
        total.insert(c);
    }
    for (int i = 0; i < n / 2; ++i) {
        cin >> c;
        s.insert(c);
        total.insert(c);
    }
    int ind = 0;
    for (int i = 1; i < 2 * n + 1; ++i) {
        if (total.find(i) == total.end()) {
            if (ind < n / 2) {
                bessie_s.insert(i);
            } else {
                bessie_f.insert(i);
            }
            ++ind;
        }
    }
    int sol = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (*f.begin() < *bessie_f.begin()) {
            ++sol;
            bessie_f.erase(bessie_f.begin());
        } else {
            auto it = bessie_f.end();
            --it;
            bessie_f.erase(it);
        }
        f.erase(f.begin());
    }

    for (int i = 0; i < n / 2; ++i) {
        if (*bessie_s.begin() < *s.begin()) {
            ++sol;
            bessie_s.erase(bessie_s.begin());
        } else {
            auto it = bessie_s.end();
            --it;
            bessie_s.erase(it);
        }
        s.erase(s.begin());
    }
    cout << sol << "\n";
    return 0;
}
