#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 1;
        string sol;
        sol.push_back(s[0]);
        for (int count = 1; count < n; ++count) {
//            cout << sol << "\n";
//            cout << sol.back() << " " << s[i] << "\n";
            if ((sol.back() == '1' || sol.back() == '2') && s[i] == '0') {
                if (s[i + 1] == '0') {
//                    cout << sol << "\n";
                    sol.pop_back();
//                    cout << sol << "\n";
                    sol.push_back('2');
//                    cout << sol << "\n";
//                    cout << "\n";
                } else {
                    while (!sol.empty() && (sol[sol.size() - 1] == '1' || sol[sol.size() - 1] == '2')) {
                        sol.pop_back();
                    }
                    sol.push_back('2');
                }
            } else {
                sol += s[i];
            }
            ++i;
        }
        string solu;
        for (char i : sol) {
            if (i != '2') {
                solu.push_back(i);
            } else {
                solu.push_back('0');
            }
        }
        cout << solu << "\n";
    }
    return 0;
}
