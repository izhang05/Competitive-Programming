/*
ID: izhang01
TASK: boards
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
}
//#define DEBUG

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif


#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
