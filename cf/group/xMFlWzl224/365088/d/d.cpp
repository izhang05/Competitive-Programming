/* Author: izhang
 * Time: 01-19-2022 17:38:08
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

void test_case() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    set<int> nums;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (nums.find(a[i]) == nums.end()) {
            if ((int) q.size() < k) {
                q.push(a[i]);
                nums.insert(a[i]);
            } else {
                nums.erase(q.front());
                q.pop();
                q.push(a[i]);
                nums.insert(a[i]);
            }
        }
    }
    cout << q.size() << "\n";
    vector<int> sol;
    while (!q.empty()) {
        sol.push_back(q.front());
        q.pop();
    }
    reverse(sol.begin(), sol.end());
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
}
int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
