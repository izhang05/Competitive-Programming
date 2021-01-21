#include <iostream>
#include <stack>

using namespace std;

int main() {
//    freopen("4.in", "r", stdin);
//    freopen("solution.out", "w", stdout);
    int n;
    cin >> n;
    stack<int> nesting;
    pair<int, int> max_depth (0, 0); // first is depth, second is location
    pair<int, int> max_length (0, 0);  // first is length, second is location
    int current_length[3] = {1, 1, 1};  // first is depth, second is location, third is length
    for (int i = 0; i < n; ++i) {
        int bracket;
        cin >> bracket;
        if (!(bracket - 1)) { // is "("
            nesting.push(0);
            if (nesting.size() > max_depth.first) {
                max_depth.first = nesting.size();
                max_depth.second = i + 1;
            }
            ++current_length[2];
        } else {
            nesting.pop();
            if (nesting.size() + 1 <= current_length[0]) {
                if (current_length[2] > max_length.first) {
                    max_length.first = current_length[2];
                    max_length.second = current_length[1];
                }
                current_length[0] = (int) nesting.size() + 1;
                current_length[1] = i + 2;
                current_length[2] = 1;
            } else {
                ++current_length[2];
            }
        }
    }
    cout << max_depth.first << " " << max_depth.second << " " << max_length.first << " " << max_length.second;
    return 0;
}
