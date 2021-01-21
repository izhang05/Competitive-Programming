//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    int n, d;
//    cin >> n >> d;
//    string flowers;
//    cin >> flowers;
//    int i = 0, sol = 0;
//    bool found;
//    while (true) {
//        found = false;
//        if (i + d >= n - 1) {
//            cout << sol + 1 << "\n";
//            break;
//        }
//        for (int j = i + d; j > i; --j) {
//            if (flowers[j] == '1') {
//                found = true;
//                i = j;
//                ++sol;
//                break;
//            }
//        }
//        if (!found) {
//            cout << -1 << "\n";
//            break;
//        }
//    }
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    string lily;
    cin >> lily;
    queue<int> pos;
    for (int i = 0; i < n; ++i) {
        if (lily[i] == '1') {
            pos.push(i);
        }
    }
    vector<int> dp(n, 1E9);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (lily[i] == '1') {
            while (pos.front() < i - d) {
                pos.pop();
            }
            dp[i] = dp[pos.front()] + 1;
        }
    }
    cout << (dp[n - 1] < 1E9 ? dp[n - 1] : -1) << "\n";
    return 0;
}


