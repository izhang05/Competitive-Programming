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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> s;
int n;

bool eq(int p, vector<int> &cur) {
    int m = int(cur.size());
    if (m + p > n) {
        return false;
    }
    for (int i = 0; i < m; ++i) {
        if (s[p + i] != cur[i]) {
            return false;
        }
    }
    return true;
}


void test_case() {
    string _;
    cin >> _;
    n = int(_.size());
    s.clear();
    for (int i = 0; i < n; ++i) {
        s.push_back(_[i] - '0');
    }
    vector<int> sol;
    for (int i = 1; i <= min(n, 5); ++i) {
        if (s[0] == 0) {
            break;
        }
        int num = 0;
        for (int k = 0; k < i; ++k) {
            num *= 10;
            num += s[k];
        }
        int p = 0, a = num;
        bool good = true;
        while (p < n) {
            vector<int> num_v;
            int cur = num;
            while (cur) {
                num_v.push_back(cur % 10);
                cur /= 10;
            }
            reverse(num_v.begin(), num_v.end());
            if (eq(p, num_v)) {
                p += (int) num_v.size();
            } else {
                good = false;
                break;
            }
            ++num;
        }
        if (good) {
            if (a - 1 != 0) {
                sol.push_back(a - 1);
            }
            if (num <= 99999) {
                sol.push_back(num);
            }
        }
    }
    for (int i = 1; i <= min(n, 5); ++i) {
        if (s[0] == 0) {
            break;
        }
        int num = 0;
        for (int k = 0; k < i; ++k) {
            num *= 10;
            num += s[k];
        }
        int p = 0, a = num;
        int rem = -1;
        bool good = true;
        while (p < n) {
            vector<int> num_v;
            int cur = num;
            while (cur) {
                num_v.push_back(cur % 10);
                cur /= 10;
            }
            reverse(num_v.begin(), num_v.end());
            if (eq(p, num_v)) {
                p += (int) num_v.size();
            } else {
                if (rem == -1) {
                    rem = num;
                } else if (rem != -1) {
                    good = false;
                    break;
                }
            }
            ++num;
        }
        if (good && rem != -1 && num - 1 <= 99999) {
            sol.push_back(rem);
        }
    }

    sort(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for (auto &i: sol) {
        cout << i << " ";
    }
    cout << "\n";

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
