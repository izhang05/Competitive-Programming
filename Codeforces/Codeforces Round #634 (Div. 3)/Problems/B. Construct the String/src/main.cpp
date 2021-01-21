#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string solution;
        for (int i = 97; i < 97 + b; ++i) {
            solution += char(i);
        }
        for (int i = 0; i < a - b; ++i) {
            solution += char(97 + b - 1);
        }
        for (int i = 0; i < n - a; ++i) {
            solution += solution[i];
        }
        cout << solution << "\n";
    }
    return 0;
}