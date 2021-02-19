#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<char> v;
    string s;
    int j = 0;
    cin >> s;
    int n = s.length() / 2 + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != '+') {
            v.push_back(s[i]);
            j++;
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < j; i++) {
        cout << v[i] << '+';
    }
}