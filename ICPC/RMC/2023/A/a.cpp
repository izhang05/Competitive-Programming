#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> vec;

    string str;

    for (int i = 0; i < n; i++) {
        cin >> str;

        if (str == "Present!") vec.pop_back();
        else vec.push_back(str);
    }

    for (auto str: vec) cout << str << "\n";

    if (vec.empty()) cout << "No Absences";
}
