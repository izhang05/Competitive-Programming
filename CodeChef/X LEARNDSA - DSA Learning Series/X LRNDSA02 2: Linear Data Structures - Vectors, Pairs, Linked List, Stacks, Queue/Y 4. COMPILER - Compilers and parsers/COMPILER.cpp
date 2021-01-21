#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, freq_greater, freq_lesser, solution;
    bool valid;
    string expression;
    cin >> t;
    while (t--) {
        solution = 0;
        valid = true;
        freq_greater = 0, freq_lesser = 0;
        cin >> expression;
        for (int i = 0; i < expression.length(); ++i) {
            if (expression[i] == '>') {
                ++freq_greater;
            } else {
                ++freq_lesser;
            }
            if (freq_greater > freq_lesser) {
                cout << i << "\n";
                valid = false;
                break;
            }
            if (freq_greater == freq_lesser) {
                solution = i + 1;
            }
        }
        if (valid) {
            cout << solution << "\n";
        }
    }
    return 0;
}