#include <iostream>
#include <cmath>

using std::cout;

long square_sum() {
    long solution = 0;
    for (int i = 1; i < 101; ++i) {
        solution += pow(i, 2);
    }
    return solution;
}

int main() {
    cout << long (pow(5050, 2)) - square_sum() << "\n";
    return 0;
}