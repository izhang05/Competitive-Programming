/*
ID: izhang01
TASK: scode
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
int sol;

void solve(const string &s, int c) {
//    cout << s << " s" << "\n";
    if (s.size() < 3 || (s.size() % 2 == 0)) {
        return;
    }
    int current = 0;
    set<string> orig;
    string cur_s = s.substr(0, s.size() / 2 + 1);
//    cout << cur_s << endl;
    if (cur_s.substr(1) == s.substr(s.size() / 2 + 1)) {
        ++current;
        orig.insert(cur_s);
        cout << s << " " << cur_s << "\n";
    }
    if (cur_s.substr(0, cur_s.size() - 1) == s.substr(s.size() / 2 + 1)) {
        ++current;
        orig.insert(cur_s);
        cout << s << " " << cur_s << "\n";
    }
    cur_s = s.substr(s.size() / 2);
    if (cur_s.substr(1) == s.substr(0, s.size() / 2)) {
        ++current;
        orig.insert(cur_s);
        cout << s << " " << cur_s << "\n";
    }
    if (cur_s.substr(0, cur_s.size() - 1) == s.substr(0, s.size() / 2)) {
        ++current;
        orig.insert(cur_s);
        cout << s << " " << cur_s << "\n";
    }
//    current *= c;
    cout << c << "\n";
    sol += current * c;
    for (const string &i : orig) {
        solve(i, current);
    }
}

int main() {
    freopen("scode_bronze/3.in", "r", stdin);
//    freopen("scode.out", "w", stdout);
    string s;
    cin >> s;
    solve(s, 1);
    cout << sol << "\n";

    return 0;
}
