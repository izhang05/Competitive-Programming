#include <iostream>
#include <cmath>

using std::cout;

int main() {
    int num_primes = 1;
    int i = 3;
    int solution = 0;
    while (num_primes < 10001) {
        if (i % 2 != 0) {
            bool factor_found = false;
            for (int j = 3; j < sqrt(i) + 1; j += 2) {
                if (i % j == 0) {
                    factor_found = true;
                    break;
                }
            }
            if (!factor_found) {
                ++num_primes;
                solution = i;
                cout << num_primes << "\n";
                cout << solution << "\n";
                cout << "" << "\n";
            }
        }
        i += 2;
    }
    cout << solution << "\n";
    return 0;
}