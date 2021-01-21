#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t, n, k, num;
    cin >> t;
    vector<int> solution;
    while (t--) {
        solution.clear();
        cin >> n >> k;
        set<int> distinct_nums;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> num;
            nums[i] = num;
            distinct_nums.insert(num);
        }
        if (distinct_nums.size() <= k) {
            cout << n * k << "\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < k; ++j) {
                    cout << *std::next(distinct_nums.begin(), j % distinct_nums.size()) << " ";
                }
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}