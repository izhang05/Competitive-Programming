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

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num_odd = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'O') {
            ++num_odd;
        }
    }
    if (num_odd % 2 != n % 2) {
        cout << "NO" << "\n";
        return;
    }
    vector<pair<int, int>> sol;
    vector<int> even, odd;
    for (int i = 1; i <= 2 * n; i += 2) {
        odd.push_back(i);
    }
    for (int i = 2; i <= 2 * n; i += 2) {
        even.push_back(i);
    }
    reverse(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    for (int i = 0; i < n; ++i) {
        dbg() << even << " " << odd;
        if (s[i] == 'O') {
            if (even.empty() || odd.empty()) {
                cout << "NO" << "\n";
                return;
            }
            sol.emplace_back(even.back(), odd.back());
            even.pop_back();
            odd.pop_back();
            --num_odd;
        } else {
            if (even.size() < 2 && (odd.size() < 2 || (int) odd.size() - 2 < num_odd)) {
                cout << "NO" << "\n";
                return;
            }
            int cur = inf;
            if (even.size() >= 2) {
                cur = even.back() + even[even.size() - 2];
            }
            if (odd.size() >= 2 && (int) odd.size() - 2 >= num_odd && odd.back() + odd[even.size() - 2] < cur) {
                sol.emplace_back(odd.back(), odd[odd.size() - 2]);
                odd.pop_back();
                odd.pop_back();
            } else {
                sol.emplace_back(even.back(), even[even.size() - 2]);
                even.pop_back();
                even.pop_back();
            }
        }
    }
    dbg() << sol;

    for (int i = 0; i < n - 1; ++i) {
        if (sol[i].first + sol[i].second > sol[i + 1].first + sol[i + 1].second) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    for (auto &i: sol) {
        cout << i.first << " " << i.second << "\n";
    }
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
