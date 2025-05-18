/* Author: izhang
 * Time: 05-17-2025 21:09:10
**/
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

bool add(long long y) {
    cout << "add " << y << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

bool mul(long long y) {
    cout << "mul " << y << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

bool div(long long y) {
    cout << "div " << y << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

void digit() {
    cout << "digit" << "\n";
    fflush(stdout);
    int res;
    cin >> res;
}

void ans() {
    cout << "!" << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
}


void test_case() {
    long long n;
    cin >> n;
    digit();
    digit();
    add(-8);
    add(-4);
    add(-2);
    add(-1);
    add(n - 1);
    ans();
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
