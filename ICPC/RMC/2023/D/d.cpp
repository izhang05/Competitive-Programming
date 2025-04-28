#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i =a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int p[7];

vector<int> cnt(int x) {
    vector<int> res(7);
    for (int i = 0; i < 7; ++i) {
        res[i] = x % 5;
        x /= 5;
    }
    return res;
}
//
//int to_base(const vector<int> &x) {
//    int res = 0;
//    for (int i = 6; i >= 0; --i) {
//        res *= 5;
//        res += x[i];
//    }
//    return res;
//}

double dp[25][1 << 7][80000];

map<char, int> val{{'A', 0},
                   {'2', 1},
                   {'3', 2},
                   {'4', 3},
                   {'5', 4},
                   {'6', 5},
                   {'7', 6},
                   {'8', 7},
                   {'9', 8},
                   {'T', 9},
                   {'J', 10},
                   {'Q', 11},
                   {'K', 12}
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p[0] = 1;
    for (int i = 1; i < 7; ++i) {
        p[i] = p[i - 1] * 5;
    }
    string s;
    cin >> s;

    vector<int> orig(7);
    int init_occ = 0;
    int rem_8 = 24;
    for (int i = 0; i < 7; ++i) {
        int cur = val[s[i]];
        orig[i] = val[s[i]];
        if (cur >= 7) {
            --rem_8;
        }
        init_occ += p[cur];
    }
    dp[rem_8][0][init_occ] = 1;
    for (int rem = 24; rem >= 0; --rem) {
        vector<int> cnts(7, 0);
        for (cnts[0] = 0; cnts[0] < 5; ++cnts[0]) {
            for (cnts[1] = 0; cnts[1] < 5; ++cnts[1]) {
                for (cnts[2] = 0; cnts[2] < 5; ++cnts[2]) {
                    for (cnts[3] = 0; cnts[3] < 5; ++cnts[3]) {
                        for (cnts[4] = 0; cnts[4] < 5; ++cnts[4]) {
                            for (cnts[5] = 0; cnts[5] < 5; ++cnts[5]) {
                                for (cnts[6] = 0; cnts[6] < 5; ++cnts[6]) {
//                                    if (cnts[0] == 1 && cnts[1] == 2 && cnts[4] == 1) {
//                                        cout << "AHHHHHHHHHHHHHHHHh" << "\n";
//                                    }
                                    for (int k = 0; k < (1 << 7) - 1; ++k) {
//                                        vi cnts = {c0, c1, c2, c3, c4, c5, c6};
                                        int total_rem = rem;
                                        for (int i = 0; i < 7; ++i) {
                                            total_rem += 4 - cnts[i];
                                        }
//                                        + 28 - cnts0 - c1 - c2 - c3 - c4 - c5 - c6;
                                        int base_value =
                                                cnts[0] + cnts[1] * p[1] + cnts[2] * p[2] + cnts[3] * p[3]
                                                + cnts[4] * p[4] + cnts[5] * p[5] + cnts[6] * p[6];
//                                        cout << base_value << endl;
//                                        cout << c0 << " " << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5
//                                             << " " << c6 << "\n";
//                                        assert(base_value < 80000);
//                                        continue;
//                                        if (cnts[0] == 1 && cnts[1] == 2 && cnts[4] == 1) {
//                                            cout << base_value << "\n";
//                                        }
//                                        if (base_value == 636) {
//                                            cout << "aahhhhhhhhhhh" << "\n";
//                                        }
                                        double cur = dp[rem][k][base_value];
//                                        continue;
                                        if (cur == 0) {
                                            continue;
                                        }
//                                        cout << "Hi" << "\n";
//                                        double first_sum = 0;

                                        // take one of first 7
                                        for (int l = 0; l < 7; ++l) {
//                                            first_sum += cnts[l];
                                            if (cnts[l] == 4) {
                                                continue;
                                            }
                                            double prob = (double) (4 - cnts[l]) / total_rem;
                                            int new_flip = k, new_cnts = base_value + p[l];
                                            int cur_card = l;

                                            while (cur_card < 7 && !(new_flip & (1 << cur_card))) {
                                                new_flip += 1 << cur_card;
                                                cur_card = orig[cur_card];
                                            }
                                            dp[rem][new_flip][new_cnts] += prob * (cur);
                                        }
                                        // do not take one of first 7
                                        if (rem > 0) {
                                            dp[rem - 1][k][base_value] += rem * (cur) / total_rem;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    long double sol = 0;
    for (int i = 0; i <= 24; ++i) {
        for (int j = 0; j < 78125; ++j) {
//            for (int k = 0; k < (1 << 7); ++k) {
//                if (dp[i][k][j] > 0) {
//                    cout << i << " " << k << " " << j << " " << dp[i][k][j] << "\n";
//                }
//            }

            int rem = i;
            vector<int> cur_cnt = cnt(j);
            for (int k = 0; k < 7; ++k) {
                rem += 4 - cur_cnt[k];
            }
            sol += (long double) (45 - rem) * dp[i][(1 << 7) - 1][j];
        }
    }
    cout << fixed << setprecision(18) << sol << "\n";
}



