#include <iostream>
#include <cmath>

using std::cout;
using std::sqrt;

long largest_factor(long num) {
    long solution;
    while (num % 2 == 0) {
        solution = 2;
        num /= 2;
    }
    long stop = sqrt(num) + 1;
    for (int i = 3; i < stop; i += 2) {
        if (num % i == 0) {
            num /= i;
            solution = i;
            if (num == 1) {
                break;
            }
        }
    }
    return solution;
}

int main() {
    cout << largest_factor(600851475143) << "\n";
    return 0;
}