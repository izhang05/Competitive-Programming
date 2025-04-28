#include <bits/stdc++.h>

using namespace std;

vector<int> num(__int128 x) {
    vector<int> res;
    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

__int128 to_num(vector<int> x) {
    __int128 res = 0;
    for (auto &i: x) {
        res *= 10;
        res += i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long ta, tb, tc, td;
    cin >> ta >> tb >> tc >> td;
    __int128 a = ta, b = tb, c = tc, d = td;
    vector<int> a_num = num(a), b_num = num(b);
    int n = int(a_num.size()), m = int(b_num.size());
    for (int i = 0; i < (1 << m); ++i) {
        vector<int> cur, deleted;
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                cur.push_back(b_num[j]);
            } else {
                deleted.push_back(b_num[j]);
            }
        }
        if (cur.empty() || cur[0] == 0) {
            continue;
        }
//        for (auto &j: cur) {
//            cout << j << " ";
//        }
//        cout << "\n";
        __int128 cur_b = to_num(cur);
//        cout << "cur_b: " << (long long) cur_b << "\n";
        __int128 numer = cur_b * c;
        if (numer % d != 0) {
            continue;
        }
        numer /= d;
//        cout << "numer: " << (long long) numer << "\n";
        vector<int> cur_num = num(numer);
        vector<int> num_deleted;
        int cur_ind = 0;
        for (int j = 0; j < n; ++j) {
            if (cur_ind == int(cur_num.size()) || cur_num[cur_ind] != a_num[j]) {
                num_deleted.push_back(a_num[j]);
            } else {
                ++cur_ind;
            }
        }
        sort(deleted.begin(), deleted.end());
        sort(num_deleted.begin(), num_deleted.end());
        if (deleted != num_deleted || cur_ind != int(cur_num.size())) {
            continue;
        } else {
            cout << "possible" << "\n";
            cout << (long long) numer << " " << (long long) cur_b << "\n";
            return 0;
        }
    }
    cout << "impossible" << "\n";
    return 0;
}
