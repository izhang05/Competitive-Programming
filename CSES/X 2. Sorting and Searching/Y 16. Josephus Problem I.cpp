#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


set<int> nums;

void add(set<int>::iterator &it) {
    if (it == nums.end()) {
        it = nums.begin();
    }
    ++it;
    if (it == nums.end()) {
        it = nums.begin();
    }
}

int main() {
    setIO("16");
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        nums.insert(i);

    }
    auto it = nums.begin();
    while (!nums.empty()) {
        add(it);
        cout << *it << " ";
        it = nums.erase(it);
    }
    cout << "\n";
    return 0;
}
