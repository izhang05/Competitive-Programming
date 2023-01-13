#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e8;
const long long limit = 1e10;

bool prime[maxn];

int main() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxn; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }
    long long cnt = 0;
    for (long long i = 0; i < maxn; ++i) {
        if (prime[i]) {
            ++cnt;
            long long cur;
            if (cnt % 2 == 1) {
                cur = (2 * cnt * i) % (i * i);
            } else {
                cur = 2 % (i * i);
            }
            if (cur > limit) {
                cout << cnt << "\n";
                break;
            }
        }
    }
    return 0;
}
