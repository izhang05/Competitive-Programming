/* Author: izhang
 * Time: 10-11-2025 13:55:32
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

bool ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    bool res;
    cin >> res;
    return res;
}

void sol(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

void test_case() {
    if (ask(2, 2)) {
        if (ask(2, 1)) {
            if (ask(1, 1)) {
                sol(1, 1);
            } else {
                sol(2, 1);
            }
        } else {
            if (ask(1, 3)) {
                sol(1, 2);
            } else {
                sol(2, 2);
            }
        }
    } else if (ask(2, 4)) {
        if (ask(2, 3)) {
            if (ask(1, 3)) {
                sol(1, 3);
            } else {
                sol(2, 3);
            }
        } else {
            if (ask(1, 5)) {
                sol(1, 4);
            } else {
                sol(2, 4);
            }
        }
    } else if (ask(4, 2)) {
        if (ask(4, 1)) {
            if (ask(3, 1)) {
                sol(3, 1);
            } else {
                sol(4, 1);
            }
        } else {
            if (ask(3, 3)) {
                sol(3, 2);
            } else {
                sol(4, 2);
            }
        }
    } else {
        if (ask(4, 3)) {
            if (ask(3, 3)) {
                sol(3, 3);
            } else {
                sol(4, 3);
            }
        } else {
            if (ask(3, 5)) {
                sol(3, 4);
            } else {
                sol(4, 4);
            }
        }
    }
}

int main() {

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
