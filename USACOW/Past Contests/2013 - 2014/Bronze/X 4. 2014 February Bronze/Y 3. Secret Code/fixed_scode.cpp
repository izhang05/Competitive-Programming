#include <bits/stdc++.h>

using namespace std;
int sol;

void solve(const string &s) {
//    cout << s << " s" << "\n";
    sol++;
    if (s.size() < 3 || (s.size() % 2 == 0)) {
        return;
    }
    set<string> orig;
    string cur_s = s.substr(0, s.size() / 2 + 1);
//    cout << cur_s << endl;
    if (cur_s.substr(1) == s.substr(s.size() / 2 + 1)) {
        ///cout << s << " " << cur_s << "\n";
        solve(cur_s);
    }
    if (cur_s.substr(0, cur_s.size() - 1) == s.substr(s.size() / 2 + 1)) {
        ///cout << s << " " << cur_s << "\n";
        solve(cur_s);
    }
    cur_s = s.substr(s.size() / 2);
    if (cur_s.substr(1) == s.substr(0, s.size() / 2)) {
        ///cout << s << " " << cur_s << "\n";
        solve(cur_s);
    }
    if (cur_s.substr(0, cur_s.size() - 1) == s.substr(0, s.size() / 2)) {
        ///cout << s << " " << cur_s << "\n";
        solve(cur_s);
    }
}

int main() {
    freopen("scode.in", "r", stdin);
    freopen("scode.out", "w", stdout);
    string s;
    cin >> s;
    solve(s);
    cout << sol - 1 << "\n";

    return 0;
}