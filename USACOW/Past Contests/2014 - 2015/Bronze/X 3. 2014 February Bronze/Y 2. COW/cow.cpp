///*
//ID: izhang01
//TASK: cow
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    freopen("cow.in", "r", stdin);
//    freopen("cow.out", "w", stdout);
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    long long sol = 0;
//    long long num_o = 0, num_w = 0, current_w = 0;
//    for (int i = (int) s.size() - 1; i >= 0; --i) {
//        if (s[i] == 'O') {
//            ++num_o;
//            current_w = num_w;
//        } else if (s[i] == 'W') {
//            ++num_w;
//        } else {
//            sol += num_o * current_w;
//        }
////        cout << i << " " << num_o << " " << num_w << " " << current_w << "\n";
//    }
//    cout << sol << "\n";
//    return 0;
//}
/*
ID: izhang01
TASK: cow
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long sol = 0, to_add = 0;
    long long num_w = 0;
    for (int i = (int) s.size() - 1; i >= 0; --i) {
        if (s[i] == 'O') {
            to_add += num_w;
        } else if (s[i] == 'W') {
            ++num_w;
        } else {
            sol += to_add;
        }
    }
    cout << sol << "\n";
    return 0;
}
