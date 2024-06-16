/* Author: izhang
 * Time: 06-06-2024 19:30:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, int> points;
    map<int, set<pair<int, int>>> main, off;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        main[a[i].first + a[i].second].insert({a[i].first, i});
        off[a[i].first - a[i].second].insert({a[i].first, i});
        points[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            for (int k = -1; k <= 1; ++k) {
                if (j == 0 || k == 0) {
                    continue;
                }
                int nx = a[i].first + j * (d / 2), ny = a[i].second + k * (d / 2);
                if (points.find({nx, ny}) != points.end()) {
                    pair<int, int> fi = a[i], se = {nx, ny};
                    if (fi.first > se.first) {
                        swap(fi, se);
                    }
                    dbg() << imie(fi) << " " << imie(se);
                    // fi is to the left of se
                    if (se.second < fi.second) {
                        pair<int, int> cur = {fi.first + d / 2, fi.second + d / 2};
                        dbg() << imie(cur);
                        auto it = main[cur.first + cur.second].lower_bound({cur.first, -1});

//                        while (it != off[cur.first - cur.second].end() && (it->second == points[fi] || it->second == points[se])) {
//                            it = next(it);
//                        }
                        if (it != main[cur.first + cur.second].end() && it->first <= fi.first + d) {
                            cout << points[fi] + 1 << " " << points[se] + 1 << " " << it->second + 1 << "\n";
                            return;
                        }

                        cur = {fi.first - d / 2, fi.second - d / 2};
                        it = main[cur.first + cur.second].lower_bound({cur.first, -1});
//                        while (it != off[cur.first - cur.second].end() && (it->second == points[fi] || it->second == points[se])) {
//                            it = next(it);
//                        }
                        if (it != main[cur.first + cur.second].end() && it->first <= fi.first) {
                            cout << points[fi] + 1 << " " << points[se] + 1 << " " << it->second + 1 << "\n";
                            return;
                        }

                    } else {
                        pair<int, int> cur = {fi.first + d / 2, fi.second - d / 2};
                        auto it = off[cur.first - cur.second].lower_bound({cur.first, -1});

//                        while (it != main[cur.first + cur.second].end() && (it->second == points[fi] || it->second == points[se])) {
//                            it = next(it);
//                        }
                        if (it != off[cur.first - cur.second].end() && it->first <= fi.first + d) {
                            cout << points[fi] + 1 << " " << points[se] + 1 << " " << it->second + 1 << "\n";
                            return;
                        }
//                        while (it != main[cur.first + cur.second].end() && (it->second == points[fi] || it->second == points[se])) {
//                            it = next(it);
//                        }
                        cur = {fi.first - d / 2, fi.second + d / 2};
                        it = off[cur.first - cur.second].lower_bound({cur.first, -1});
                        if (it != off[cur.first - cur.second].end() && it->first <= fi.first) {
                            cout << points[fi] + 1 << " " << points[se] + 1 << " " << it->second + 1 << "\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "0 0 0"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
