/* Author: izhang05
 * Time: 07-24-2021 14:33:28
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
    set<int> nums;
    for (int i = 1; i < (1 << n); ++i) {
        if (i != k) {
            nums.insert(i);
        }
    }
    int pre = 0;
    vector<int> sol;
    while (!nums.empty()) {
        int cur = *nums.begin();
        sol.push_back(pre ^ cur);
        nums.erase(cur), nums.erase(cur ^ k);
        pre = cur;
    }
    cout << sol.size() << "\n";
    print(sol);
    return 0;
}
