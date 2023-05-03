#include <array>
#include <iostream>

int main() {
    int solution = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            solution += i;
        }
    }
    std::cout << solution << std::endl;
    return 0;
}
