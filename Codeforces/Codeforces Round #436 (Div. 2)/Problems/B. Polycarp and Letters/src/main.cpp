#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int sol = 0;
    set<int> letters;
    int i = 0;
    while (isupper(s[i])) {
        ++i;
    }
    for (; i < n; ++i) {
        if (isupper(s[i])) {
            sol = max(sol, (int) letters.size());
            letters.clear();
        } else {
            letters.insert(s[i]);
        }
    }
    cout << max(sol, (int) letters.size()) << "\n";
    return 0;
}
