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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[mxn][2];

void test_case() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<int> cur(k);
        for (int j = 0; j < k; ++j) {
            if (s[j] == 'F') {
                cur[j] = 0;
            } else if (s[j] == 'T') {
                cur[j] = 1;
            } else {
                cur[j] = 2;
            }
        }
        for (int j = 0; j < k; ++j) {
            if (cur[j] != 2) {
                for (int l = 0; l < k; ++l) {
                    if (j == l || cur[l] == 2) {
                        continue;
                    }
                    adj[j][cur[j]].emplace_back(l, cur[l] ^ 1);
                }
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout << i << " " << j << ":\n";
//            for (auto &l: adj[i][j]) {
//                cout << l.first << " " << l.second << "\n";
//            }
//        }
//    }
    vector<int> sol(k, -1);
    for (int i = 0; i < k; ++i) {
        if (sol[i] != -1) {
            continue;
        }
        for (int j = 0; j < 2; ++j) {
            bool good = true;
            vector<int> cur(k, -1);
            cur[i] = j;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            while (!q.empty()) {
                pair<int, int> cur_q = q.front();
                q.pop();
                for (auto &l: adj[cur_q.first][cur_q.second]) {
                    if (cur[l.first] == -1) {
                        q.push(l);
                        cur[l.first] = l.second;
                    } else {
                        if (cur[l.first] != l.second) {
                            good = false;
                            break;
                        }
                    }
                }
                if (!good) {
                    break;
                }
            }
            for (int l = 0; l < k; ++l) {
                if (cur[l] != -1 && sol[l] != -1 && cur[l] != sol[l]) {
                    good = false;
                }
            }
            if (good) {
                for (int l = 0; l < k; ++l) {
                    if (cur[l] != -1) {
                        sol[l] = cur[l];
                    }
                }
                break;
            } else {
                if (j == 1) {
                    cout << -1 << "\n";
                    return;
                }
            }
        }
//        dbg() << sol;
//        dbg() << cur;
    }
    for (auto &i: sol) {
        cout << (i ? "T" : "F");
    }
    cout << "\n";

}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
