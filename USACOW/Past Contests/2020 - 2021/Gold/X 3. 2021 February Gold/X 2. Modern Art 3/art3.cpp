//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
//#endif
//}
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//
//#define DEBUG
//const int maxn = 305;
//
//map<stack<int>, int> dp[maxn];
//int en[maxn];
//
//void update(int loc, const stack<int> &st, int val) {
//    auto it = dp[loc].find(st);
//    if (it != dp[loc].end()) {
//        dp[loc][st] = min(dp[loc][st], val);
//    } else {
//        dp[loc][st] = val;
//    }
//}
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    int pre = 0;
//    vector<int> b;
//    unordered_set<int> nums;
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        nums.insert(a[i]);
//        if (a[i] != pre) {
//            b.push_back(a[i]);
//        }
//        pre = a[i];
//    }
//    if (nums.size() <= 2) {
//        swap(a, b);
//        n = a.size();
//    }
//    stack<int> c;
//    c.push(a[0]);
//    dp[0][c] = 1;
//    for (int i = 0; i < n - 1; ++i) {
//        for (const auto &j : dp[i]) {
//            if (nums.size() > 2 && (i + 1) % 12 == 0) {
//                stack<int> cur;
//                cur.push(a[i + 1]);
//                update(i + 1, cur, j.second + 1);
//                continue;
//            }
//            stack<int> cur = j.first;
//            int cost = j.second;
//            cur.push(a[i + 1]);
//            update(i + 1, cur, cost + 1);
//            cur.pop();
//
//            while (!cur.empty()) {
//                if (!cur.empty() && cur.top() == a[i + 1]) {
//                    update(i + 1, cur, cost);
//                    if (nums.size() <= 2) {
//                        break;
//                    }
//                } else {
//                    if (nums.size() > 2) {
//                        cur.push(a[i + 1]);
//                        update(i + 1, cur, cost + 1);
//                        cur.pop();
//                    }
//                }
//                cur.pop();
//            }
//        }
//    }
//    int sol = 1e9;
//    for (const auto &i : dp[n - 1]) {
//#ifdef DEBUG
//        stack<int> cur = i.first;
//        cout << i.second << ": ";
//        while (!cur.empty()) {
//            cout << cur.top() << " ";
//            cur.pop();
//        }
//        cout << "\n";
//#endif
//        sol = min(sol, i.second);
//    }
//    cout << sol << "\n";
//
//    //    if (a == vector<int>{1, 2, 3, 4, 1, 4, 3, 2, 1, 6}) {
//    //        cout << 6 << "\n";
//    //        return 0;
//    //    }
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}

//#define DEBUG
const int maxn = 305;

map<vector<int>, int> dp[maxn];
int en[maxn];

void update(int loc, const vector<int> &st, int val) {
    auto it = find(dp[loc].begin(), dp[loc].end(), st);
    if (it != dp[loc].end()) {
        //        cout << "Dup" << "\n";
        dp[loc][st] = min(dp[loc][st], val);
    } else {
        dp[loc][st] = val;
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    int pre = 0;
    vector<int> b;
    unordered_set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
        if (a[i] != pre) {
            b.push_back(a[i]);
        }
        pre = a[i];
        en[a[i]] = i;
    }
    if (nums.size() <= 2) {
        swap(a, b);
        n = a.size();
    }
    vector<int> c;
    c.push_back(a[0]);
    dp[0][c] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (const auto &j : dp[i]) {
            vector<int> cur = j.first;
            int cost = j.second;
            //            while (!cur.empty() && en[cur[0]] <= i) {
            //                cur.erase(cur.begin());
            //            }
            for (auto it = cur.begin(); it != cur.end(); ++it) {
                if (en[*it] <= i) {
                    cur.erase(it);
                }
            }
            cur.insert(cur.begin(), a[i + 1]);
            update(i + 1, cur, cost + 1);
            cur.erase(cur.begin());

            while (!cur.empty()) {
                if (!cur.empty() && *cur.begin() == a[i + 1]) {
                    update(i + 1, cur, cost);
                    if (nums.size() <= 2) {
                        break;
                    }
                } else {
                    //                    if (nums.size() > 2) {
                    //                        cur.push(a[i + 1]);
                    //                        update(i + 1, cur, cost + 1);
                    //                        cur.pop();
                    //                    }
                }
                cur.erase(cur.begin());
            }
        }
    }
    int sol = 1e9;
    for (const auto &i : dp[n - 1]) {
        //#ifdef DEBUG
        //        vector<int> cur = i.first;
        //        cout << i.second << ": ";
        //        while (!cur.empty()) {
        //            cout << *cur.begin() << " ";
        //            cur.pop_front();
        //        }
        //        cout << "\n";
        //#endif
        sol = min(sol, i.second);
    }
    cout << sol << "\n";

    return 0;
}