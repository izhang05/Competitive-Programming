#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, minimum_capacity;
    long long solution;
    cin >> t;
    while (t--) {
        solution = 0;
        minimum_capacity = 1E9;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int capacity;
            cin >> capacity;
            minimum_capacity = min(minimum_capacity, capacity);
            solution += minimum_capacity;
        }
        cout << solution << "\n";
    }
    return 0;
}
