#include <bits/stdc++.h>

using namespace std;

bool sq(__int128 num) {
    auto rt = (__int128) round(sqrt(num));
    return rt * rt == num;
}

int main() {

    for (__int128 i = 1e12 + 1;; ++i) {
        __int128 cur = 1 + 2 * i * i - 2 * i;
        if (sq(cur)) {
            __int128 num = (__int128) round(sqrt(cur));
            if (num % 2 == 1) {
                cout << (long long) ((1 + num) / 2) << "\n";
                break;
            }
        }
    }
    return 0;
}
