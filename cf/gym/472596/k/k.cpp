/* Author: izhang
 * Time: 02-11-2024 18:15:09
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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct p {
    long long x, y, t;
};

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<p> a(n);
    for (auto &i : a) {
        cin >> i.x >> i.y >> i.t;
    }
    map<pair<long long, long long>, long long> occ;
    map<long long, long long> cnt_x, cnt_y;
    vector<pair<pair<long long, long long>, pair<long long, long long>>> people;
    long long i = 0;
    for (long long j = 0; j < m; ++j) {
        while (i < n && a[i].t == j) {
            ++occ[{a[i].x, a[i].y}];
            ++cnt_x[a[i].x];
            ++cnt_y[a[i].y];
            people.push_back({{a[i].x, a[i].y}, {i, 0}});
            ++i;
        }
        map<pair<long long, long long>, long long> n_occ;
        map<long long, long long> n_cnt_x, n_cnt_y;
        vector<pair<pair<long long, long long>, pair<long long, long long>>> n_people;
        for (auto &k : people) {
            if (k.second.second % 2 == 0) {
                if (cnt_y[k.first.second] - occ[k.first] % 2 == 1) {
                    ++k.second.second;
                    k.second.second %= 4;
                }
            } else {
                if (cnt_x[k.first.first] - occ[k.first] % 2 == 1) {
                    ++k.second.second;
                    k.second.second %= 4;
                }
            }
            pair<pair<long long, long long>, pair<long long, long long>> cur;
            cur.second = k.second;
            long long nx = k.first.first + dx[k.second.second], ny = k.first.second + dy[k.second.second];
            cur.first = {nx, ny};
            n_people.push_back(cur);
            ++n_occ[cur.first];
            ++n_cnt_x[cur.first.first];
            ++n_cnt_y[cur.first.second];
        }
        swap(occ, n_occ);
        swap(cnt_x, n_cnt_x);
        swap(cnt_y, n_cnt_y);
        swap(n_people, people);
    }
    vector<pair<long long, long long>> sol(n);
    for (auto &j : people) {
        sol[j.second.first] = j.first;
    }
    for (auto &j : sol) {
        cout << j.first << " " << j.second << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
