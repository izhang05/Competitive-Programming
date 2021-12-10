#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

// 1, 4, 7, 8
// a = 7 - 1
// g = 9 - 4 - a
// e = 8 - 4 - a - g
// b = 0 - 1 - a - g - e
// d = 4 - 1 - b
// f = 5 - a - b - d - g
// c = 1 - f

string sub(string a, string b) {
    string res = a;
    for (auto &i: b) {
        bool found = false;
        for (int j = 0; j < int(res.size()); ++j) {
            if (res[j] == i) {
                found = true;
                res.erase(j, 1);
                break;
            }
        }
        if (!found) {
            return "-1";
        }
    }
    return res;
}


void solve() {
    map<string, int> digit;
    digit["acbcefg"] = 0;
    digit["cf"] = 1;
    digit["acdeg"] = 2;
    digit["acdfg"] = 3;
    digit["bcdf"] = 4;
    digit["abdfg"] = 5;
    digit["abdefg"] = 6;
    digit["acf"] = 7;
    digit["abcdefg"] = 8;
    digit["abcdfg"] = 9;
    int n = 200, sol = 0;
    for (int i = 0; i < n; ++i) {
        map<string, string> val;
        string s;
        vector<string> inp(10);
        for (int j = 0; j < 10; ++j) {
            cin >> inp[j];
            sort(inp[j].begin(), inp[j].end());
        }
        sort(inp.begin(), inp.end(), [](auto left, auto right) {
            return left.size() < right.size();
        });
        string a = sub(inp[1], inp[0]);
        val[a] = "a";
        string g;
        for (int j = 0; j < 10; ++j) {
            if (inp[j].size() == 6) {
                vector<string> subs{inp[2], a};
                bool found = true;
                string cur = inp[j];
                for (int k = 0; k < 2; ++k) {
                    if (sub(cur, subs[k]) == "-1") {
                        found = false;
                        break;
                    } else {
                        cur = sub(cur, subs[k]);
                    }
                }
                if (found) {
                    g = cur;
                    break;
                }
            }
        }
        val[g] = "g";

        string e = inp[9];
        vector<string> subs{inp[2], a, g};
        for (auto &j: subs) {
            e = sub(e, j);
        }
        val[e] = "e";

        string b;
        for (int j = 0; j < 10; ++j) {
            if (inp[j].size() == 6) {
                vector<string> subs{inp[0], a, g, e};
                string cur = inp[j];
                bool found = true;
                for (int k = 0; k < 4; ++k) {
                    if (sub(cur, subs[k]) == "-1") {
                        found = false;
                        break;
                    } else {
                        cur = sub(cur, subs[k]);
                    }
                }
                if (found) {
                    b = cur;
                    break;
                }
            }
        }
        val[b] = "b";

        string d = sub(sub(inp[2], inp[0]), b);
        val[d] = "d";
        string f;
        for (int j = 0; j < 10; ++j) {
            if (inp[j].size() == 5) {
                vector<string> subs{a, b, d, g};
                bool found = true;
                string cur = inp[j];
                for (int k = 0; k < 4; ++k) {
                    if (sub(cur, subs[k]) == "-1") {
                        found = false;
                        break;
                    } else {
                        cur = sub(cur, subs[k]);
                    }
                }
                if (found) {
                    f = cur;
                    break;
                }
            }
        }
        val[f] = "f";
        string c = sub(inp[0], f);
        val[c] = "c";

        cin >> s;
        int cur_sol = 0;
        for (int j = 0; j < 4; ++j) {
            cin >> s;
            string cur;
            for (auto &k: s) {
                cur += val[string(1, k)];
            }
            sort(cur.begin(), cur.end());

            cout << s << " " << cur << "\n";
            cur_sol *= 10;
            cur_sol += digit[cur];
        }
        sol += cur_sol;
        cout << cur_sol << "\n";
    }
    cout << sol << "\n";
}

int main() {
    setIO("8");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
