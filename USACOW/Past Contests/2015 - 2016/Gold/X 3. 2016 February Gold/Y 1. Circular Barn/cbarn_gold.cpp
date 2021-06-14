/*
ID: izhang01
TASK: cbarn
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    freopen("cbarn.out", "w", stderr);
}
//#define DEBUG

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cows, start = -1;
    for (int i = 0; i < n;) {
#ifdef DEBUG
        cout << i << endl;
#endif
        cows = 0;
        bool good = true;
        for (int j = 0; j < n; ++j) {
            int cur = (i + j) % n;
#ifdef DEBUG
            cout << "cur: " << cur << "\n";
#endif
            cows += a[cur] - 1;
            if (cows < 0) {
                good = false;
                if (cur == i) {
                    i = cur + 1;
                } else {
                    i = cur;
                }
                break;
            }
        }
        if (good) {
            start = i;
            break;
        }
    }
    priority_queue<int, vector<int>, greater<>> q;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        int cur = (i + start) % n;
        for (int j = 0; j < a[cur]; ++j) {
            q.push(i);
        }
        sol += (i - q.top()) * (i - q.top());
        q.pop();
    }
    cout << sol << "\n";
    return 0;
}
