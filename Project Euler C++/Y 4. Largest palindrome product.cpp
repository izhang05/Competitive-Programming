#include <iostream>
#include <cmath>

using std::cout;
using std::pow;

bool is_palindrome(int num) {
    int size = trunc(log10(num)) + 1;
    while (size > 1) {
        if (num % 10 != num / int(pow(10, size - 1))) {
            return false;
        }
        num %= int(pow(10, size - 1));
        num /= 10;
        size -= 2;
    }
    for (int i = 0; i < (size + 1) / 2; ++i) {
        if (num % int(pow(10, i + 1)) != num / int(pow(10, size - i - 1))) {
            return false;
        }
    }
    return true;
}

int main() {
    int solution = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = i; j < 1000; ++j) {
            int num = i * j;
            if (num > solution && is_palindrome(num)) {
                solution = num;
            }
        }
    }
    cout << solution << "\n";
    return 0;
}

