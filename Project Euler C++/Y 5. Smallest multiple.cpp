#include <iostream>
#include <cmath>

using std::cout;


long gcd(long x, long y) {
    while (y != 0) {
        long temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

long lcm(long x, long y) {
    return (x * y) / gcd(x, y);
}

int main() {
    long solution = 1;
    for (int i = 1; i < 21; ++i) {
        solution = lcm(solution, i);
    }
    cout << solution << "\n";
    return 0;
}