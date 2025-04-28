/* Author: izhang
 * Time: 12-18-2024 21:44:36
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

long long x, y, z, k;

__int128 val2(__int128 cur_d, __int128 d, __int128 h) {
    __int128 cost = 0;
//    __int128 lo1 = d + 1, hi1 = d + k, mid1, cur_d;
//    while (lo1 <= hi1) {
//        mid1 = (lo1 + hi1) / 2;
//        if ((h + mid1 - 1) / mid1 <= mid) {
//            cur_d = mid1;
//            hi1 = mid1 - 1;
//        } else {
//            lo1 = mid1 + 1;
//        }
//    }
    cost += (cur_d - d) * x;
    cost += y * ((h + cur_d - 1) / cur_d);
    return cost;
}

__int128 val(__int128 cnt) {
    // cnt number of full rounds
//     assert(cnt * k * x <= z);
    __int128 d = k * cnt;
    __int128 cost = d * x + y * cnt;
    __int128 h = z - k * cnt * (cnt + 1) / 2;
    if (h <= 0) {
        return cost + x;
    }
    vector<__int128> vals{d + 1};
    __int128 cur = d + 1, mx = (h + d + k - 1) / (d + k);
    while ((h + cur - 1) / cur != mx) {
        __int128 lo = cur + 1, hi = d + k, mid, res;
        __int128 cur_div = (h + cur - 1) / cur;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if ((h + mid - 1) / mid != cur_div) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cur = res;
        vals.push_back(cur);
    }
//    if (cnt == 0) {
//        dbg() << vals;
//    }
    int nums = int(vals.size());
    __int128 lo = 0, hi = nums - 1, mid;
    if (lo == hi) {
        return cost + val2(vals[0], d, h);
    }
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (mid == 0) {
            return cost + min(val2(vals[0], d, h), val2(vals[1], d, h));
        }
        if (mid == nums - 1) {
            return cost + min(val2(vals[nums - 2], d, h), val2(vals[nums - 1], d, h));
        }
        __int128 mn = val2(vals[mid - 1], d, h), cur_d = val2(vals[mid], d, h), up = val2(vals[mid + 1], d, h);
        if (mn <= cur_d) {
            hi = mid - 1;
        } else if (up <= cur_d) {
            lo = mid + 1;
        } else {
            return cur_d + cost;
        }
    }
//    assert(false);
    return cost + val2(vals[mid], d, h);
}

void test_case() {
    cin >> x >> y >> z >> k;
//    k = 50;

//    cout << "0: " << val(0) << " 1: " << val(1) << "\n";
//    return;
//    if (x == 10) {
//        for (int i = 1; i <= 5; ++i) {
//            cout << i << " " << val2(i, 0, 5) << "\n";
//        }
//    }

    __int128 lo = 0, hi = z / (k * x), mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (mid == 0) {
            cout << (long long) min(val(0), val(1)) << "\n";
            return;
        }
        __int128 mn = val(mid - 1), cur = val(mid), mx = val(mid + 1);
        if (mn <= cur) {
            hi = mid - 1;
        } else if (mx <= cur) {
            lo = mid + 1;
        } else {
            cout << (long long) cur << "\n";
            return;
        }
    }
//    assert(false);
    cout << (long long) val(mid) << "\n";
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
