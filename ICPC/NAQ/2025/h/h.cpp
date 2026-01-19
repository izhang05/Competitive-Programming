/* Author: izhang
 * Time: 10-11-2025 13:55:23
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
    int n;
    cin >> n;
    long double t = 0;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        t += a[i].first * a[i].second;
    }
    if (t < 0) {
        for (auto &i: a) {
            i.first = -i.first;
        }
        sort(a.begin(), a.end());
        t = -t;
    }
    multiset<pair<long double, pair<long long, long long>>, greater<>> vals; // pair<average value, <pos, num_people>>
//    map<long long, long long, greater<>> vals;
    map<long long, pair<long double, long long>> pos; // pair<pos, <average_value, num_people>>
    for (auto &i: a) {
        vals.insert({(long double) i.second, {i.first, 1}});
        pos[i.first] = {(long double) i.second, 1};
    }
    long double sol = 0;
    while (t > 0) {
//        if (vals.empty()) {
//            return;
//        }
//        cout << vals.size() << " " << pos.size() << endl;
//        assert(vals.size() == pos.size());
        pair<long double, pair<long long, long long>> cur = *vals.begin();
        long double cur_v = cur.first;
        long long cur_pos = cur.second.first, cur_people = cur.second.second;
        vals.erase(vals.begin());
        auto it = pos.lower_bound(cur_pos);
//        if (it == pos.end()) {
//            return;
//        }
        if (it == pos.begin()) {
            sol += (long double) t / cur_v;
            t = 0;
        } else {
            long long pre = prev(it)->first;
            if ((cur_pos - pre) * cur_v * cur_people >= t) {
                sol += (long double) t / cur_v;
                t = 0;
            } else {
                pair<long long, pair<long double, long long>> prev_it = *prev(it);
                t -= (cur_pos - pre) * cur_v * cur_people;
                sol += (cur_pos - pre) * cur_people;
                pos.erase(it);
                long long new_people = cur_people + prev_it.second.second;
                long double new_value =
                        (cur_v * cur_people + prev_it.second.first * prev_it.second.second) / new_people;
                auto it2 = vals.find({prev_it.second.first, {prev_it.first, prev_it.second.second}});
                vals.erase(it2);
                vals.insert({new_value, {prev_it.first, new_people}});
                pos[prev_it.first] = {new_value, new_people};
            }
        }
    }
    cout << fixed << setprecision(9) << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
