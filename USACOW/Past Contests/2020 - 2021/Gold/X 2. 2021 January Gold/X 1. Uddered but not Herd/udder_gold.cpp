//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//#ifdef LOCAL
//    freopen("1.in", "r", stdin);
//#endif
//}
//
//int order[26];
//
//int main() {
//    setIO();
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        a[i] = s[i] - 'a';
//    }
//    set<int> tmp(a.begin(), a.end());
//    vector<int> o(tmp.begin(), tmp.end());
//    int sol = 1e9;
//    do {
//        for (int i = 0; i < o.size(); ++i) {
//            order[o[i]] = i;
//        }
//        int cur = 1, pre = -1;
//        for (int i = 0; i < n; ++i) {
//            int letter = a[i];
//            if (order[letter] <= pre) {
//                ++cur;
//            }
//            pre = order[letter];
//        }
//        sol = min(sol, cur);
//    } while (next_permutation(o.begin(), o.end()));
//    cout << sol << "\n";
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}

int order[26];

int main() {
    setIO();
    string s;
    cin >> s;

    return 0;
}
