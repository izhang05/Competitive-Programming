/* Author: izhang05
 * Time: 07-21-2021 16:31:21
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e2 + 5;
int dp[maxn][maxn];

int main() {
    setIO("1");
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sol -= a;
        q.push(a);
        q.push(a);
        q.pop();
    }
    for (int i = 0; i < n; ++i) {
        sol += q.top();
        q.pop();
    }
    cout << sol << "\n";
    return 0;
}