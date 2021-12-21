#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[25][10][10][25][25][2];


int main() {
    setIO("1");
    long long a = 0, b = 0;
    dp[0][3][5][0][0][0] = 1;
    vector<int> ways{0, 0, 0, 1, 3, 6, 7, 6, 3, 1};
    for (int i = 0; i < 25; ++i) {
        for (int a_p = 0; a_p < 10; ++a_p) {
            for (int b_p = 0; b_p < 10; ++b_p) {
                for (int a_s = 0; a_s < 21; ++a_s) {
                    for (int b_s = 0; b_s < 21; ++b_s) {
                        for (int turn = 0; turn < 2; ++turn) {
                            long long cur = dp[i][a_p][b_p][a_s][b_s][turn];
                            if (!cur) {
                                continue;
                            }
                            for (int roll = 3; roll < 10; ++roll) {
                                if (turn == 0) {
                                    int new_pos = (a_p + roll) % 10, new_score = a_s + new_pos + 1;
                                    if (new_score >= 21) {
                                        a += cur * ways[roll];
                                    } else {
                                        dp[i + 1][new_pos][b_p][new_score][b_s][turn ^ 1] += cur * ways[roll];
                                    }
                                } else {
                                    int new_pos = (b_p + roll) % 10, new_score = b_s + new_pos + 1;
                                    if (new_score >= 21) {
                                        b += cur * ways[roll];
                                    } else {
                                        dp[i + 1][a_p][new_pos][a_s][new_score][turn ^ 1] += cur * ways[roll];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << max(a, b) << "\n";
    return 0;
}
