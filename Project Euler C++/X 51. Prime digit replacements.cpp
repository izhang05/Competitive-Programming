#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6;
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
    int sol = 1e9;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                vector<int> rem;
                for (int l = 0; l < 6; ++l) {
                    if (i != l && j != l && k != l) {
                        rem.push_back(l);
                    }
                }
                int cnt = 0;
                for (auto &l: rem) {


                    for (int m = 0; m < 10; ++m) {
                        vector<int> num(6);
                        num[i] = num[j] = num[k] = m;
                    }
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
