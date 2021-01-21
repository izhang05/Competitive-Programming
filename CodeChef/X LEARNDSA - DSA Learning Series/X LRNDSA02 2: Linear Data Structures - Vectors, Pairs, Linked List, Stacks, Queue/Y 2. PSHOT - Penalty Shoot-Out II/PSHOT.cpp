#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, n, A, B;
    bool determined;
    string results;
    cin >> t;
    while (t--) {
        A = 0, B = 0, determined = false;
        cin >> n;
        cin >> results;
        for (int i = 0; i < n; ++i) {
            if (results[2 * i] == '1') {
                ++A;
            }
            if (n - i + B < A || n - i + A - 1 < B) {
                cout << 2 * i + 1 << "\n";
                determined = true;
                break;
            }
            if (results[2 * i + 1] == '1') {
                ++B;
            }
            if (n - i + B - 1 < A || n - i + A - 1 < B) {
                cout << 2 * i + 2 << "\n";
                determined = true;
                break;
            }
        }
        if (!determined) {
            cout << 2 * n << "\n";
        }
    }
    return 0;
}
