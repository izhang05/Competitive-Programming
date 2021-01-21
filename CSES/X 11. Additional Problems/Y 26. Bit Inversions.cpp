#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

set<int> diff;
multiset<int, greater<> > len;
string s;

void modify(int x) {
    if (x == 0 || x == s.size()) {
        return;
    }
    auto it = diff.find(x);
    if (it != diff.end()) {
        int a = *prev(it), b = *next(it);
        len.erase(len.find(x - a));
        len.erase(len.find(b - x));
        len.insert(b - a);
        diff.erase(it);
    } else {
        it = diff.insert(x).first;
        int a = *prev(it), b = *next(it);
        len.erase(len.find(b - a));
        len.insert(x - a);
        len.insert(b - x);
    }
}

int main() {
    setIO();
    cin >> s;
    int n = s.size(), m;
    cin >> m;
    int last = 0;
    diff.insert(0);
    diff.insert(n);
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            diff.insert(i);
            len.insert(i - last);
            last = i;
        }
    }
    len.insert(n - last);
    int x;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        --x;
        modify(x);
        modify(x + 1);
        cout << *len.begin() << " ";
    }
    cout << "\n";
    return 0;
}
