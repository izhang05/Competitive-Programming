/*
ID: izhang01
TASK: exercise
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
}
const int maxn = 1e4 + 5;
int mod;
vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b) % mod;
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b) * b) % mod;
}

long long sum_factors(long long a) {
    long long res = 0;
    long long cur = 1;
    while (a % 2 == 0) {
        cur *= 2;
        a /= 2;
    }
    if (cur != 1) {
        res += cur;
    }
    for (long long i = 3; i * i <= a; i += 2) {
        cur = 1;
        while (a % i == 0) {
            cur *= i;
            a /= i;
        }
        if (cur != 1) {
            res += cur;
        }
    }
    if (a == 1) {
        --a;
    }
    return res + a;
}

int main() {
    setIO();
    int n;
    cin >> n >> mod;
    int sol = 0;
    for (int i = 0; i < 1e5; ++i) {
        if (sum_factors(i) <= n) {
            //            cout << i << " " << sum_factors(i) << "\n";
            (sol += i) %= mod;
        }
    }
    cout << sol << "\n";
    return 0;
}
