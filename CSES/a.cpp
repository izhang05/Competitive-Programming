#include <bits/stdc++.h>
using namespace std;
string rearrangedString(string s) {
    map<char, int> a;
    for (char i : s) {
        if ((i >= '0' && i <= '9') || (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) {
            ++a[i];
        }
    }
    map<int, vector<char>, greater<int>> b;
    for (auto i : a) {
        b[i.second].push_back(i.first);
    }
    string res;
    int count = 0;
    for (auto i : b) {
        res += to_string(i.first);
        if (count % 2 == 1) {
            reverse(i.second.begin(), i.second.end());
        }
        ++count;
        for (char j : i.second) {
            res.push_back(j);
        }
        if (i.first != 1) {
            res.push_back(',');
        }
    }
    return res;
}
int main() {
    cout << rearrangedString("This is an Example of Sorting an interesting string") << "\n";
    return 0;
}
