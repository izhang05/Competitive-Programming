#include <iostream>
#include <string>

using namespace std;


string L(string str) {
    char last = str[0];
    str.erase(0, 1);
    str += last;
    return str;
}


string R(string str) {
    char first = str[str.length() - 1];
    str.erase(str.length() - 1);
    str = first + str;
    return str;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        if (L(s) == R(s)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
