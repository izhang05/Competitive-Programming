#include <iostream>
#include <cmath>

using std::cout;


int find_solution() {
    for (int a = 0; a < 500; ++a) {
        for (int b = 999 - a; a + b > 500; --b) {
            if (pow(a, 2) + pow(b, 2) == pow(1000 - a - b, 2)) {
                return a * b * (1000 - a - b);
            }
        }
    }
}

int main() {
    cout << find_solution() << "\n";

    return 0;
}