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
    int m, I, t;
    cin >> m >> I >> t;
    bool swapped = false;
    if (m < t) {
        swapped = true;
        swap(m, t);
    }
    // m >= t
    if (I < abs(m - t) - 1 || I > m + t) {
        cout << "NO" << "\n";
        return;
    }


    string sol;
    int diff = m + t - I;
    for (int j = 0; j < m; ++j) {
        if (diff >= 3) {
            sol += 'M';
            sol += 'T';
            diff -= 2;
            --t;
        } else {
            for (; j < m; ++j) {
                sol += 'M';
            }
            for (int k = 0; k < t; ++k) {
                sol += 'T';
            }
            break;
        }
    }
    string final_sol;
    final_sol = sol[0];

    int ones_used = 0;

    int n = (int) sol.size();
    for (int j = 1; j < n; ++j) {
        if (sol[j] == sol[j - 1]) {
            ++ones_used;
            final_sol += 'I';
        }
        final_sol += sol[j];
    }

    if (I - ones_used == 2) {
        final_sol = "I" + final_sol + "I";
    } else if (I - ones_used == 1) {
        final_sol = final_sol + "I";
    }
    if (swapped) {
        for (auto &i: final_sol) {
            if (i == 'M') {
                i = 'T';
            } else if (i == 'T') {
                i = 'M';
            }
        }

    }
    cout << "YES" << "\n";
    cout << final_sol << "\n";
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
