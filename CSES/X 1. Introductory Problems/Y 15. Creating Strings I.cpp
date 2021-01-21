#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string orig = s;
    vector<string> sol;
    sol.push_back(s);
    next_permutation(s.begin(), s.end());
    while (s != orig) {
        sol.push_back(s);
        next_permutation(s.begin(), s.end());
    }
    cout << sol.size() << "\n";
    for (string i : sol) {
        cout << i << "\n";
    }
    return 0;
}
