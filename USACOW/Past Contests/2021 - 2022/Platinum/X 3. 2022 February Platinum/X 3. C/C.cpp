#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out1.txt", "w", stdout);
    freopen("out1.txt", "w", stderr);
#endif
}
const int MOD = 1e9 + 7;
struct modnum {
    int v;
    long long mult = 0;
    modnum &operator+=(const modnum &o) {
        v += o.v;
        mult += o.mult;
        if (v >= MOD) {
            ++mult;
            v -= MOD;
        }
        return *this;
    }
    modnum &operator-=(const modnum &o) {
        v -= o.v;
        mult -= o.mult;
        if (v < 0) {
            --mult;
            v += MOD;
        }
        return *this;
    }
    modnum &operator*=(const modnum &o) {
        v = int((long long) (v) * (long long) (o.v) % MOD);
        return *this;
    }
    modnum &operator+=(int o) {
        v += o;
        v = (v >= MOD) ? v - MOD : v;
        return *this;
    }
    modnum &operator-=(int o) {
        v -= o;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum &operator*=(int o) {
        v = int((long long) (v) * (long long) (o) % MOD);
        return *this;
    }
    friend modnum operator+(const modnum &a, const modnum &b) {
        return modnum(a) += b;
    }
    friend modnum operator-(const modnum &a, const modnum &b) {
        return modnum(a) -= b;
    }
    friend modnum operator*(const modnum &a, const modnum &b) {
        return modnum(a) *= b;
    }
    friend modnum operator+(const modnum &a, int &b) {
        return modnum(a) += b;
    }
    friend modnum operator-(const modnum &a, int &b) {
        return modnum(a) -= b;
    }
    friend modnum operator*(const modnum &a, int &b) {
        return modnum(a) *= b;
    }
    bool operator>(const modnum &o) const {
        return mult == o.mult ? v > o.v : mult > o.mult;
    }
};

bool valid(char a, char b) {
    string s;
    s += a, s += b;
    sort(s.begin(), s.end());
    return (s == "12" || s == "23" || s == "45" || s == "56" || s == "78" || s == "89" || s == "14" || s == "47" || s == "25" || s == "58" || s == "36" || s == "69");
}
bool valid(char a, char b, char c, char d) {
    string s;
    s += a, s += b, s += c, s += d;
    sort(s.begin(), s.end());
    return (s == "1245" || s == "2356" || s == "4578" || s == "5689");
}
namespace a {
    const int maxn = 1e5 + 5;
    modnum dp[maxn];
    void solve1(const string &s) {
        int n = int(s.size());
        for (int i = 0; i <= n; ++i) {
            dp[i].v = 0;
        }
        dp[0].v = dp[1].v = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (valid(s[i - 2], s[i - 1])) {
                dp[i] += dp[i - 2];
            }
        }
        cout << dp[n].v << "\n";
    }
} // namespace a

namespace b {
    const int maxn = 1e3 + 5;
    modnum dp[maxn][10][10][10][10];
    modnum sum[maxn];
    void solve2(const string &s) {
        int n = int(s.size());
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 10; ++l) {
                        for (int m = 0; m < 10; ++m) {
                            dp[i][j][k][l][m].v = 0;
                        }
                    }
                }
            }
            sum[i].v = 0;
        }
        dp[0][0][0][0][0].v = dp[1][0][0][0][s[0] - '0'].v = 1;
        sum[0].v = sum[1].v = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 10; ++l) {
                        for (int m = 0; m < 10; ++m) {
                            dp[i][k][l][m][s[i - 1] - '0'] += dp[i - 1][j][k][l][m];
                            //                            if (dp[i][k][l][m][s[i - 1] - '0'].v != 0) {
                            //                                cout << i << " " << k << " " << l << " " << m << " " << s[i - 1] - '0' << " " << dp[i][k][l][m][s[i - 1] - '0'].v << "\n";
                            //                            }
                        }
                    }
                }
            }
            if (valid(s[i - 2], s[i - 1])) {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 10; ++k) {
                        for (int l = 0; l < 10; ++l) {
                            for (int m = 0; m < 10; ++m) {
                                dp[i][l][m][s[i - 1] - '0'][s[i - 2] - '0'] += dp[i - 2][j][k][l][m];
                            }
                        }
                    }
                }
            }
            if (i >= 4 && valid(s[i - 4], s[i - 3], s[i - 2], s[i - 1])) {
                string cur;
                cur += s[i - 4], cur += s[i - 3], cur += s[i - 2], cur += s[i - 1];
                sort(cur.begin(), cur.end());
                do {
                    modnum &val = dp[i][cur[0] - '0'][cur[1] - '0'][cur[2] - '0'][cur[3] - '0'];
                    if (sum[i - 4] > val) {
                        val = sum[i - 4];
                    }
                } while (next_permutation(cur.begin(), cur.end()));
            }
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 10; ++l) {
                        for (int m = 0; m < 10; ++m) {
                            sum[i] += dp[i][j][k][l][m];
                        }
                    }
                }
            }
        }
        //        for (int i = 0; i < 10; ++i) {
        //            for (int j = 0; j < 10; ++j) {
        //                for (int k = 0; k < 10; ++k) {
        //                    for (int l = 0; l < 10; ++l) {
        //                        if (dp[n][i][j][k][l].v) {
        //                            cout << i << " " << j << " " << k << " " << l << " " << dp[n][i][j][k][l].v << "\n";
        //                        }
        //                    }
        //                }
        //            }
        //        }
        cout << sum[n].v << "\n";
    }
} // namespace b


void brute(const string &s) {
    int n = int(s.size());
    vector<set<string>> good(n + 1);
    good[0].insert("");
    for (int i = 1; i <= n; ++i) {
        for (auto &j : good[i - 1]) {
            good[i].insert(j + s[i - 1]);
        }
        if (i >= 2) {
            if (valid(s[i - 2], s[i - 1])) {
                for (auto &j : good[i - 2]) {
                    good[i].insert(j + s[i - 2] + s[i - 1]);
                    good[i].insert(j + s[i - 1] + s[i - 2]);
                }
            } else {
                for (auto &j : good[i - 2]) {
                    good[i].insert(j + s[i - 2] + s[i - 1]);
                }
            }
        }
        if (i >= 4) {
            if (valid(s[i - 4], s[i - 3], s[i - 2], s[i - 1])) {
                string cur;
                cur += s[i - 4], cur += s[i - 3], cur += s[i - 2], cur += s[i - 1];
                sort(cur.begin(), cur.end());
                do {
                    for (auto &j : good[i - 4]) {
                        good[i].insert(j + cur);
                    }
                } while (next_permutation(cur.begin(), cur.end()));
            } else {
                for (auto &j : good[i - 4]) {
                    good[i].insert(j + s[i - 4] + s[i - 3] + s[i - 2] + s[i - 1]);
                }
            }
        }
    }
    cout << good[n].size() << "\n";
}
int main() {
    setIO("4");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        string s;
        cin >> s;
        if (s.size() <= 0) {
            brute(s);
        } else if (s.size() <= int(1e3)) {
            b::solve2(s);
        } else {
            a::solve1(s);
        }
    }
    return 0;
}
