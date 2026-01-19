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
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long ask(long long x, long long y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    long long ans;
    cin >> ans;
    return ans;
}

void test_case() {
    int n;
    cin >> n;
    int i = 0;
    vector<long long> sol(n);
    for (; i + 2 < n; i += 3) {
        long long a = ask(i + 1, i + 2), b = ask(i + 2, i + 3);
        long long g = gcd(a, b);
        sol[i] = a / g, sol[i + 1] = g, sol[i + 2] = b / g;
    }
    for (; i < n; ++i) {
        long long a = ask(1, i + 1);
        sol[i] = a / sol[0];
    }
    cout << "!";
    for (int j = 0; j < n; ++j) {
        cout << " " << sol[j];
    }
    cout << endl;
    cout.flush();
}

int main() {

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
