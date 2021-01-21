#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
//        int res = 0;
//        for (int i = 0; i < 1e9; ++i) {
//            int cur = i;
//            bool ok = true;
//            for (char j : s) {
//                ++res;
//                if (j == '+') {
//                    ++cur;
//                } else {
//                    --cur;
//                }
//                if (cur < 0) {
//                    ok = false;
//                    break;
//                }
//            }
//            if (ok) {
//                break;
//            }
//        }
//        cout << res << "\n";
        long long sol = 0;
        int depth = 0;
        int deep = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '-') {
                ++depth;
                if (depth > deep) {
                    deep = depth;
                    sol += i + 1;
                }
            } else {
                --depth;
            }
        }
        sol += s.size();
        cout << sol << "\n";
//        if (res != sol) {
//            cout << s << "\n";
//            break;
//        }
    }
    return 0;
}
