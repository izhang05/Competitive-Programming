#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    string a, s;
    cin >> a >> s;
    map<char, int> order;
    for (int i = 0; i < 26; ++i) {
        order[a[i]] = i;
    }
    int sol = 1, pre = -1;
    for (char i : s) {
        int cur = order[i];
        if (cur <= pre) {
            ++sol;
        }
        pre = cur;
    }
    cout << sol << "\n";
    return 0;
}
