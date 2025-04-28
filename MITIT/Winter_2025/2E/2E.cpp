//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//
//#include <debug.h>
//
//#else
//
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//
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
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//void test_case() {
//    int n;
//    cin >> n;
//    int sol = 0;
//    vector<int> a(n);
//    int pre = -1, cur = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        if (a[i] == pre) {
//            ++cur;
//        } else {
//            pre = a[i];
//            cur = 1;
//        }
//        sol = max(sol, cur);
//    }
//    cout << sol << "\n";
//    for (int i = 0; i < sol - 1; ++i) {
//        cout << 1 << " " << i + 1 << "\n";
//    }
//    cout << n - (sol - 1);
//    for (int i = sol; i <= n; ++i) {
//        cout << " " << i;
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n;

void brute() {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    map<int, pair<int, int>> cur;
    vector<pair<pair<int, int>, int>> reqs;
    for (int i = 0; i < n; ++i) {
        ++cur[a[i]].first
        if (cur[a[i]].first - (i - cur[a[i]].second + 1 - cur[a[i]].first) < 1) {
            cur[a[i]].first = 1;
            cur[a[i]].second = i;
        }
        if (cur[a[i]].first - (i - cur[a[i]].second + 1 - cur[a[i]].first) > sol) {
            sol = cur[a[i]].first - (i - cur[a[i]].second + 1 - cur[a[i]].first);
            reqs.clear();
        }
        if (sol == cur[a[i]].first - (i - cur[a[i]].second + 1 - cur[a[i]].first)) {
            reqs.push_back({{i, cur[a[i]].second}, a[i]});
        }
    }
    vector<int> rep(n, -1);
    for (auto &i: reqs) {
        for (int j = i.first.first; j <= i.first.second; ++j) {
            rep[j] = i.second;
        }
    }
    cout << sol << "\n";
    vector<vector<int>> lines(sol);
    vector<int> last(sol, -1);
    for (int i = 0; i < n; ++i) {
        if (rep[i] == -1) {
            map<int, int> cnt;
            pair<int, int> mx{-1, -1};
            for (int j = 0; j < sol; ++j) {
                if (last[j] != a[i] && last[j] != -1) {
                    ++cnt[last[j]];
                    mx = max(mx, {cnt[last[j]], last[j]});
                }
            }
            for (int j = 0; j < sol; ++j) {
                if (last[j] == mx.second || (mx.second == -1 && last[j] != a[i])) {
                    last[j] = a[i];
                    lines[j].push_back(i);
                    break;
                }
            }
        } else {
            bool found = false;
            for (int j = 0; j < sol; ++j) {
                if (last[j] != a[i] && last[j] == rep[i]) {
                    last[j] = a[i];
                    lines[j].push_back(i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                for (int j = 0; j < sol; ++j) {
                    if (last[j] != a[i]) {
                        last[j] = a[i];
                        lines[j].push_back(i);
                        break;
                    }
                }
            }
        }
    }

    for (auto &i: lines) {
        cout << i.size();
        for (auto &j: i) {
            cout << " " << j + 1;
        }
        cout << "\n";
    }
}

void test_case() {
    cin >> n;
    if (n <= 5e3) {
        brute();
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    map<int, pair<int, int>> cur;
    for (int i = 0; i < n; ++i) {
        ++cur[a[i]].first;
        if (cur[a[i]].first - (i - cur[a[i]].second + 1 - cur[a[i]].first) < 1) {
            cur[a[i]].first = 1;
            cur[a[i]].second = i;
        }
        sol = max(sol, cur[a[i]].first - (i - cur[a[i]].second + 1 - cur[a[i]].first));

//        mx = max(mx, cur[a[j]]);
////            dbg() << mx << " " << j - i + 1 - mx;
//        sol = max(sol, mx - ((j - i + 1) - mx));
    }
    cout << sol << "\n";
    for (int i = 0; i < sol - 1; ++i) {
        cout << 1 << " " << i + 1 << "\n";
    }
    cout << n - (sol - 1);
    for (int i = sol; i <= n; ++i) {
        cout << " " << i;
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
