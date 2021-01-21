#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> food(n);
        unordered_map<int, int> amounts;
        for (int i = 0; i < n; ++i) {
            cin >> food[i];
        }
        int previous = food[0];
        amounts[previous] = 1;
        for (int i = 1; i < n; ++i) {
            int food_type = food[i];
            if (food_type != previous) {
                if (amounts.count(food_type) != 0) {
                    ++amounts[food_type];
                } else {
                    amounts[food_type] = 1;
                }
                previous = food_type;
            } else {
                previous = 0;
            }
        }
        pair<int, int> solution(0, 0);
        for (int i = 1; i < amounts.size() + 1; ++i) {
            if (amounts[i] > solution.first) {
                solution.first = amounts[i];
                solution.second = i;
            }
        }
        cout << solution.second << "\n";
    }
    return 0;
}