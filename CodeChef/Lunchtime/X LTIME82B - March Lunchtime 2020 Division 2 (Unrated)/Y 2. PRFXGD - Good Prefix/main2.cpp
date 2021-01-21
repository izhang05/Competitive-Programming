#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    int k, x, solution;
    while (t--) {
        unordered_map <char, int> frequency;
        solution = 0;
        cin >> s;
        cin >> k >> x; // k = chars that can be deleted, x = number of occurrences of character
        for (char i : s) {
            if (!frequency.count(i)) { // i not in frequency
                frequency[i] = 1;
                ++solution;
            } else if (frequency[i] < x) {
                ++frequency[i];
                ++solution;
            } else {
                if (k == 0) {
                    break;
                } else {
                    --k;
                }
            }
        }
        cout << solution << "\n";
    }
    return 0;
}