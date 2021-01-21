#include <iostream>

using std::cout;

int main() {
    int first = 1;
    int second = 2;
    int solution = 2;

    int max_value = 4000000;
    while (true) {
        if (first > second) {
            second += first;
            if (second > max_value) {
                break;
            }
            if (second % 2 == 0) {
                solution += second;
            }
        } else {
            first += second;
            if (first > max_value) {
                break;
            }
            if (first % 2 == 0) {
                solution += first;
            }
        }
    }
    cout << solution << "\n";
}