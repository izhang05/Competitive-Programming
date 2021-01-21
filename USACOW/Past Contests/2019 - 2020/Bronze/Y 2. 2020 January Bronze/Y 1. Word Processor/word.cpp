/*
ID: izhang01
TASK: word
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
}


int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cur = s.size();
    cout << s;
    for (int i = 1; i < n; ++i) {
        cin >> s;
        if (s.size() + cur > k) {
            cout << "\n" << s;
            cur = s.size();
        } else {
            cur += s.size();
            cout << " " << s;
        }
    }
    cout << "\n";
    return 0;
}
