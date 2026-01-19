///* Author: izhang
// * Time: 06-15-2025 17:02:24
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//
//#include <debug.h>
//
//#else
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//bool used[mxn];
//vector<pair<int, int>> adj[mxn];
//bool vis[mxn][2];
//
//vector<int> a, b;
//
//void dfs(int c, int col, int p) {
////    cout << c << " " << col << " " << p << "\n";
////    if (col != -1) {
//        if (col != 2) {
//            vis[c][col] = true;
//        }
////        else {
////            if (!vis[c][0]) {
////                vis[c][0] = true;
////                if (a[p] != c) {
////                    swap(a[p], b[p]);
////                }
////            } else if (!vis[c][1]) {
////                vis[c][1] = true;
////                if (b[p] != c) {
////                    swap(a[p], b[p]);
////                }
////            }
////        }
////    }
//    for (auto &i: adj[c]) {
//        if (used[i.second]) {
//            continue;
//        }
//        used[i.second] = true;
//        if (col == 1) {
//            vis[c][0] = true;
//            if (a[i.second] != c) {
//                swap(a[i.second], b[i.second]);
//            }
//            dfs(i.first, 1, i.second);
//        } else {
//            vis[c][1] = true;
//            if (b[i.second] != c) {
//                swap(a[i.second], b[i.second]);
//            }
//            dfs(i.first, 0, i.second);
//        }
////        else {
////            dfs(i.first, 2, i.second);
////        }
//    }
//}
//
//
//void test_case() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < 2 * n; ++i) {
//        vis[i][0] = vis[i][1] = false;
//    }
//    a.resize(n), b.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        --a[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> b[i];
//        --b[i];
//        adj[a[i]].emplace_back(b[i], i);
//        adj[b[i]].emplace_back(a[i], i);
//        used[i] = false;
//    }
//    for (int i = 0; i < 2 * n; ++i) {
//        dfs(i, 2, -1);
//    }
////    for (int i = 0; i < 2 * n; ++i) {
////        cout << vis[i][0] << " " << vis[i][1] << "\n";
////    }
//    int sol = 0;
//    set<int> nums;
//    for (auto &i: a) {
//        nums.insert(i);
//    }
//    sol = nums.size();
//    nums.clear();
//    for (auto &i: b) {
//        nums.insert(i);
//    }
//    sol += nums.size();
//    cout << sol << "\n";
//    for (auto &i: a) {
//        cout << i + 1 << " ";
//    }
//    cout << "\n";
//    for (auto &i: b) {
//        cout << i + 1 << " ";
//    }
//    cout << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}


/* Author: izhang
 * Time: 06-15-2025 17:02:24
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int vis[mxn];
set<pair<int, int>> adj[mxn];
vector<int> a, b;


void dfs(int c, int col, bool root) {
//    cout << c << endl;
    ++vis[c];
//    cout << c << " " << col << " " << root << "\n";
    while (!adj[c].empty()) {
        pair<int, int> i = *adj[c].begin();
//        assert(adj[i.first].find({c, i.second}) != adj[i.first].end());
        adj[i.first].erase({c, i.second});
        adj[c].erase(i);
//        cout << "edge: " << c << " " << i.first << " " << i.second << "\n";
        if (col == 0) {
            if (a[i.second] != c) {
                swap(a[i.second], b[i.second]);
            }
        } else {
            if (b[i.second] != c) {
                swap(a[i.second], b[i.second]);
            }
        }
        dfs(i.first, col, false);
        if (root) {
            col ^= 1;
        }
    }
    adj[c].clear();
}


void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        adj[i].clear();
        vis[i] = false;
    }
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        adj[a[i]].insert({b[i], i});
        adj[b[i]].insert({a[i], i});
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (!vis[i]) {
            dfs(i, 0, true);
        }
    }
    int sol = 0;
    set<int> nums;
    for (auto &i: a) {
        nums.insert(i);
    }
    sol = nums.size();
    nums.clear();
    for (auto &i: b) {
        nums.insert(i);
    }
    sol += nums.size();
    cout << sol << "\n";
    for (auto &i: a) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    for (auto &i: b) {
        cout << i + 1 << " ";
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
