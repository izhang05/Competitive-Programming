/* Author: izhang
 * Time: 01-15-2022 09:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

int d(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void test_case() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pair<int, int> cur = {i, j};
            pq.push(max({d(cur, {0, 0}), d(cur, {0, m - 1}), d(cur, {n - 1, 0}), d(cur, {n - 1, m - 1})}));
        }
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
