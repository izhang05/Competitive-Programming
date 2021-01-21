#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int i) {
    if (i == 2) {
        return true;
    }
    if (i == 1 || i % 2 == 0) {
        return false;
    }
    for (int j = 3; j < int(sqrt(i)) + 2; j += 2) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long solution = 0;
    for (int i = 2; i < 2000000; ++i) {
        if (isPrime(i)) {
            solution += i;
        }
    }
    cout << solution << "\n";
    return 0;
}
