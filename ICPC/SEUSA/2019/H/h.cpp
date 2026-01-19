#include <bits/stdc++.h>

using namespace std;


int main() {
    string alph, s;
    cin >> alph >> s;
    set<string> sol;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char cur = s[i];
        for (auto &j: alph) {
            if (j != cur) {
                s[i] = j;
                sol.insert(s);
            }
        }
        s[i] = cur;
    }
    string end;
    for (int i = n; i >= 0; --i) {
        for (auto &j: alph) {
            sol.insert(s + j + end);
        }
        if (i != 0) {
            char cur = s.back();
            s.pop_back();
            sol.insert(s + end);
            end = cur + end;
        }
    }
    for (auto &i: sol) {
        cout << i << "\n";
    }
}
