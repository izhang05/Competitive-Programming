#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    set<int> nums;
    nums.insert(0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        nums.insert((a / 12) + 1);
    }
#ifdef DEBUG
    print(nums);
#endif
    multiset<int, greater<>> differences;
    for (auto it = nums.begin(); next(it) != nums.end(); ++it) {
        differences.insert(*(next(it)) - *it - 1);
    }
#ifdef DEBUG
    print(differences);
#endif
    int saved = 0, cnt = 0;
    for (auto it = differences.begin(); it != differences.end() && cnt < k - 1; ++it, ++cnt) {
        saved += *it;
    }
    cout << (*nums.rbegin() - saved) * 12 << "\n";
    return 0;
}
