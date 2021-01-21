#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, k; // n = length of string, k = numbers of strings to split to
    char smallest;
    string s;
    cin >> t;
    vector<char> str;
    bool flag;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        str.resize(n);
        for (int i = 0; i < n; ++i) {
            str[i] = s[i];
        }
        sort(str.begin(), str.end());
        if (k == n) {
            cout << str[n - 1] << "\n";
            continue;
        }
        if (k == n - 1) {
            cout << str[n - 2] << "\n";
            continue;
        }

        smallest = str[0];
        flag = true;
        for (int i = 1; i < k; ++i) {
            if (str[i] != smallest) {
                cout << str[i] << "\n";
                flag = false;
                break;
            }
        }
        char next = str[k];
        bool flag1 = true;
        if (flag) {
            for (int i = k + 1; i < n; ++i) {
                if (str[i] != next) {
                    flag1 = false;
                    cout << str[0];
                    for (int j = k; j < n; ++j) {
                        cout << str[j];
                    }
                    cout << "\n";
                    break;
                }
            }
            if (flag1) {
                cout << str[0];
                for (int i = 0; i < ceil((double) (n - k) / k); ++i) {
                    cout << str[k];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}