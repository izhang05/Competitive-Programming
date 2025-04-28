#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    stack<int> pos;
    pos.push(0);
    while (k) {
        string s;
        cin >> s;
        if (s == "undo") {
            int rem;
            cin >> rem;
            for (int i = 0; i < rem; ++i) {
                pos.pop();
            }
        } else {
            int cur = stoi(s), top = pos.top();
            int nxt = ((top + cur) % n + n) % n;
            pos.push(nxt);
        }
        --k;
    }
    cout << pos.top() << "\n";
}