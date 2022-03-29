#include <bits/stdc++.h>

using namespace std;

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
const int MOD = 1e9 + 7;
struct modnum {
    int v;
    modnum &operator+=(const modnum &o) {
        v += o.v;
        v = (v >= MOD) ? v - MOD : v;
        return *this;
    }
    modnum &operator-=(const modnum &o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
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
};
const int inf = 0x3f3f3f3f, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;


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

int cnt[10][10][10][10];
void test_case() {
    string s;
    cin >> s;
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
    for (auto &i : good[n]) {
        ++cnt[i[2] - '0'][i[3] - '0'][i[4] - '0'][i[5] - '0'];
        //        cout << i << "\n";
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int l = 0; l < 10; ++l) {
                    if (cnt[i][j][k][l]) {
                        cout << i << " " << j << " " << k << " " << l << " " << cnt[i][j][k][l] << "\n";
                    }
                }
            }
        }
    }
    cout << (good[n].size()) % MOD << "\n";
}
int main() {
    setIO("4");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
