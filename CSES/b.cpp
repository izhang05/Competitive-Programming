
// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * inputStr, represents the given string for the puzzle
 */
void funcSubstring(string inputStr) {
    int n = inputStr.size();
    inputStr = "$" + inputStr + "/";
    string sol;
    int mx_len = 0;
    for (int i = 1; i <= n; ++i) {
        // odd case
        int l = i, r = i;
        while (inputStr[l] == inputStr[r]) {
            --l, ++r;
        }
        ++l, --r;
        int cur_len = r - l + 1;
        if (cur_len >= mx_len) {
            string cur;
            for (int j = l; j <= r; ++j) {
                cur += inputStr[j];
            }
            if (cur_len > mx_len || cur < sol) {
                sol = cur;
            }
            mx_len = cur_len;
        }
        // even case
        l = i - 1, r = i;
        while (inputStr[l] == inputStr[r]) {
            --l, ++r;
        }
        ++l, --r;
        cur_len = r - l + 1;
        if (cur_len >= mx_len) {
            string cur;
            for (int j = l; j <= r; ++j) {
                cur += inputStr[j];
            }
            if (cur_len > mx_len || cur < sol) {
                sol = cur;
            }
            mx_len = cur_len;
        }
    }
    if (mx_len <= 1) {
        cout << "None\n";
    } else {
        cout << sol << "\n";
    }
}

int main() {

    //input for inputStr
    string inputStr;
    getline(cin, inputStr);

    funcSubstring(inputStr);

    return 0;
}