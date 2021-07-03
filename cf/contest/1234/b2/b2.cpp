/* Author: izhang05
 * Time: 07-02-2021 21:35:27
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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("1");

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> cur;
    queue<int> sol;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (cur.find(a[i]) == cur.end()) {
            cur.insert(a[i]);
            if ((int) sol.size() >= k) {
                cur.erase(sol.front());
                sol.pop();
            }
            sol.push(a[i]);
        }
    }
    cout << sol.size() << "\n";
    vector<int> res;
    while (!sol.empty()) {
        res.push_back(sol.front());
        sol.pop();
    }
    reverse(res.begin(), res.end());
    print(res);

    return 0;
}
