#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

vector<int> digits(int x) {
    return {x / 10, x % 10};
}

int h, m;

void add_hour(int &x) {
    if (x + 1 == h) {
        x = 0;
    } else {
        ++x;
    }
}

void add_minute(int &x, int &y) {
    if (x + 1 == m) {
        x = 0;
        add_hour(y);
    } else {
        ++x;
    }
}

set<int> good{0, 1, 2, 5, 8};
map<int, int> reflection{{0, 0},
                         {1, 1},
                         {2, 5},
                         {5, 2},
                         {8, 8}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        cin >> h >> m;
        string s;
        cin >> s;
        int a = 10 * (s[0] - '0') + s[1] - '0', b = 10 * (s[3] - '0') + s[4] - '0';
        while (true) {
            vector<int> cur = digits(b);
            bool found = true;
            for (int i = 0; i < 2; ++i) {
                if (good.find(cur[i]) == good.end()) {
                    found = false;
                    break;
                }
            }
            bool sol = false;
            if (found) {
                int next = 10 * reflection[cur[1]] + reflection[cur[0]];
                if (next < h) {
                    bool found2 = true;
                    vector<int> cur2 = digits(a);
                    for (int i = 0; i < 2; ++i) {
                        if (good.find(cur2[i]) == good.end()) {
                            found2 = false;
                            break;
                        }
                    }
                    if (found2) {
                        int next2 = 10 * reflection[cur2[1]] + reflection[cur2[0]];
                        if (next2 < m) {
                            sol = true;
                        }
                    }
                } else {
                    add_minute(b, a);
                }
            } else {
                add_minute(b, a);
            }
            if (sol) {
                break;
            } else {
                add_minute(b, a);
            }
        }
        cout << a / 10 << a % 10 << ":" << b / 10 << b % 10 << "\n";
    }
    return 0;
}
