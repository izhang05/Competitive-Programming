/* Author: izhang05
 * Time: 07-21-2021 15:14:13
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    int n, a;
    cin >> n >> a;
    priority_queue<int> q;
    q.push(a);
    long long sol = 0;
    for (int i = 1; i < n; ++i) {
        cin >> a;
        a -= i;
        q.push(a);
        if (q.top() > a) {
            sol += q.top() - a;
            q.pop();
            q.push(a);
        }
    }
    cout << sol << "\n";
    return 0;
}
