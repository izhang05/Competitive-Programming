#include<bits/stdc++.h>

using namespace std;

long long y, l;

bool pos(long long b) {
    vector<int> cur;
    long long num = y;
    while (num) {
        if (num % b >= 10) {
            return false;
        }
        cur.push_back(int(num % b));
        num /= b;
    }
    reverse(cur.begin(), cur.end());
    long long num_10 = 0;
    for (auto &i: cur) {
        num_10 *= 10;
        num_10 += i;
    }
    return num_10 >= l;
}

int main() {
    cin >> y >> l;
    long long sol = 0;
    for (int i = 2; i <= 1e6 + 5; ++i) {
        if (pos(i)) {
            sol = i;
        }
    }
    for (long long k = l; k <= 1000; ++k) {
        vector<int> num_v;
        long long cur_num = k;
        while (cur_num) {
            num_v.push_back(int(cur_num % 10));
            cur_num /= 10;
        }
        reverse(num_v.begin(), num_v.end());
        long long lo = 2, hi = 1e18;
        while (lo <= hi) {
            long long b = (lo + hi) / 2;
            __int128 cur = 0;
            bool br = false;
            for (auto &i: num_v) {
                if (cur > 0 && b > LLONG_MAX / cur) {
                    br = true;
                    break;
                }
                cur *= b;
                cur += i;
            }
            if (cur == y && !br) {
                sol = max(sol, b);
                break;
            } else if (cur < y && !br) {
                lo = b + 1;
            } else {
                hi = b - 1;
            }
        }
    }
    cout << sol << "\n";
}

