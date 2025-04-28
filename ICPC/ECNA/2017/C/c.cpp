#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string s, a, b;

    cin >> s;

    a = s.substr(0, s.size() / 2);
    b = s.substr(s.size() / 2, s.size() / 2);

    int val = 0;

    for(auto c : a) val += c - 'A';

    for(auto &c : a) c = 'A' + ((int)(c - 'A') + val) % 26;

    val = 0;

    for(auto c : b) val += c - 'A';

    for(auto &c : b) c = 'A' + ((int)(c - 'A') + val) % 26;

    for(int i = 0; i < a.size(); i++) a[i] = 'A' + ((int)(a[i] - 'A') + (int)(b[i] - 'A')) % 26;

    cout << a;
}