#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    //    cout << 1 << "\n";
    ofstream out("in3.txt");
    out << 1 << "\n";
    int n = 1e6;
//    cout << n << " " << 578148 << " " << 63 << "\n";
    out << n << " " << 578148 << " " << 63 << "\n";
    for (int i = 0; i < n; ++i) {
//        cout << rnd(1, 1e9) << " \n"[i == n - 1];
        out << rnd(1, 1e9) << " \n"[i == n - 1];
    }
//    cout << 1 << " " << 2 << "\n";
    out << 1 << " " << 2 << "\n";

    out.close();
}