#include <iostream>
#include <cmath>

using namespace std;

const long long mod = 1e9 + 7;

long long pow_mod(long long num, long long pow) {
    long long solution = 1;
    for (int i = 0; i < pow; ++i) {
        solution *= num;
        solution %= mod;
    }
    return solution % mod;
}


int main() {
    int n;
    cin >> n;
    long long solution = 0;
    solution = (pow_mod(3, 3 * n) - pow_mod(7, n) + mod) %
               mod;  // total permutations - permutations where triangles sum to 6(permutations of (1, 2, 3) and (2, 2, 2))
    cout << solution << "\n";
    return 0;
}