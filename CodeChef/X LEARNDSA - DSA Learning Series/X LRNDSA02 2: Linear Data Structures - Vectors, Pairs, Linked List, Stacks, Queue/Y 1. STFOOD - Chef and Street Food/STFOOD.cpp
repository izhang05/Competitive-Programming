#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long solution = 0;
        cin >> n;
        int stores[n];
        int price[n];
        int people[n];
        for (int i = 0; i < n; ++i) {
            cin >> stores[i] >> people[i] >> price[i];
        }

        for (int i = 0; i < n; ++i) {
            long long profit = (people[i] / (stores[i] + 1)) * price[i];
            solution = max(solution, profit);
        }
        cout << solution << "\n";
    }
    return 0;
}
