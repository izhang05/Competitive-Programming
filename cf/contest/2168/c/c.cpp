/* Author: izhang
 * Time: 12-22-2025 15:28:49
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, n = 20, mxn = 1 << n;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

bool vis[mxn];
vector<int> nodes;
map<int, int> m;


void first() {
    int x;
    cin >> x;
    --x;
    int code = nodes[x];
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        if (code & (1 << i)) {
            sol.push_back(i + 1);
        }
    }
    cout << sol.size() << "\n";
    for (auto &i: sol) {
        cout << i << " ";
    }
    cout << "\n";
}

void second() {
    int num;
    cin >> num;
    int code = 0;
    for (int i = 0; i < num; ++i) {
        int x;
        cin >> x;
        code += 1 << (x - 1);
    }
    if (m.find(code) != m.end()) {
        cout << m[code] << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (m.find(code ^ (1 << i)) != m.end()) {
                cout << m[code ^ (1 << i)] << "\n";
            }
        }
    }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

int deg[mxn];

int main() {
    setIO("1");

    vector<int> order(mxn);
    for (int i = 0; i < mxn; ++i) {
        order[i] = i;
    }
//    shuffle(order.begin(), order.end(), rng);
    for (auto &i: order) {
        if (!vis[i]) {
            nodes.push_back(i);
            for (int j = 0; j < n; ++j) {
                vis[i ^ (1 << j)] = true;
                for (int k = 0; k < n; ++k) {
                    vis[i ^ (1 << j) ^ (1 << k)] = true;
                }
            }
        }
    }

    for (int i = 0; i < int(nodes.size()); ++i) {
        m[nodes[i]] = i + 1;
    }
//    cout << nodes.size() << "\n";
//    map<int, int> cnt;
//    for (auto &i: nodes) {
//        ++cnt[__builtin_popcount(i)];
//    }
//    for (auto &i: cnt) {
//        cout << i.first << " " << i.second << "\n";
//    }
//    return 0;

    string s;
    cin >> s;
    bool f = s == "first";
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        if (f) {
            first();
        } else {
            second();
        }
    }
    return 0;
}







///* Author: izhang
// * Time: 12-22-2025 15:28:49
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
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, n = 20, mxn = 1 << 20;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//bool vis[mxn];
//vector<int> nodes;
//map<int, int> m;
//
//
//void first() {
//    int x;
//    cin >> x;
//    --x;
//    int code = nodes[x];
//    vector<int> sol;
//    for (int i = 0; i < 20; ++i) {
//        if (code & (1 << i)) {
//            sol.push_back(i + 1);
//        }
//    }
//    cout << sol.size() << "\n";
//    for (auto &i: sol) {
//        cout << i << " ";
//    }
//    cout << "\n";
//}
//
//void second() {
//    int num;
//    cin >> num;
//    int code = 0;
//    for (int i = 0; i < num; ++i) {
//        int x;
//        cin >> x;
//        code += 1 << (x - 1);
//    }
//    if (m.find(code) != m.end()) {
//        cout << m[code] << "\n";
//    } else {
//        for (int i = 0; i < n; ++i) {
//            if (m.find(code ^ (1 << i)) != m.end()) {
//                cout << m[code ^ (1 << i)] << "\n";
//            }
//        }
//    }
//}
//
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
//long long rnd(long long l, long long r) { // [l, r]
//    return uniform_int_distribution<long long>(l, r)(rng);
//}
//
//int deg[mxn];
//
//int main() {
//    setIO("1");
//
////    vector<int> order(mxn);
////    for (int i = 0; i < mxn; ++i) {
////        order[i] = i;
////    }
////    shuffle(order.begin(), order.end(), rng);
////    for (auto &i: order) {
////        if (!vis[i]) {
////            nodes.push_back(i);
////            for (int j = 0; j < n; ++j) {
////                vis[i ^ (1 << j)] = true;
////                for (int k = 0; k < n; ++k) {
////                    vis[i ^ (1 << j) ^ (1 << k)] = true;
////                }
////            }
////        }
////    }
//
//    set<pair<int, int>> q;
//    for (int i = 0; i < mxn; ++i) {
//        deg[i] = n;
//        q.insert({deg[i], i});
//    }
//    while (!q.empty()) {
//        int cur = q.begin()->second;
//        q.erase(q.begin());
//        nodes.push_back(cur);
//        vis[cur] = true;
//        for (int i = 0; i < n; ++i) {
//            int nxt = cur ^ (1 << i);
//            if (!vis[nxt]) {
//                vis[nxt] = true;
//                q.erase({deg[nxt], nxt});
//                for (int j = 0; j < n; ++j) {
//                    int nxt_nxt = nxt ^ (1 << j);
//                    if (!vis[nxt_nxt]) {
//                        q.erase({deg[nxt_nxt], nxt_nxt});
//                        --deg[nxt_nxt];
//                        q.insert({deg[nxt_nxt], nxt_nxt});
//                    }
//                }
//            }
//            for (int j = 0; j < n; ++j) {
//                nxt = cur ^ (1 << i) ^ (1 << j);
//                if (!vis[nxt]) {
//                    vis[nxt] = true;
//                    q.erase({deg[nxt], nxt});
//                    for (int k = 0; k < n; ++k) {
//                        int nxt_nxt = nxt ^ (1 << k);
//                        if (!vis[nxt_nxt]) {
//                            q.erase({deg[nxt_nxt], nxt_nxt});
//                            --deg[nxt_nxt];
//                            q.insert({deg[nxt_nxt], nxt_nxt});
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < int(nodes.size()); ++i) {
//        m[nodes[i]] = i + 1;
//    }
//    cout << nodes.size() << "\n";
//    map<int, int> cnt;
//    for (auto &i: nodes) {
//        ++cnt[__builtin_popcount(i)];
//    }
//    for (auto &i: cnt) {
//        cout << i.first << " " << i.second << "\n";
//    }
//    return 0;
//
//    string s;
//    cin >> s;
//    bool f = s == "first";
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        if (f) {
//            first();
//        } else {
//            second();
//        }
//    }
//    return 0;
//}
