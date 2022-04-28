#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    int trials = 2000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");

        int n = 3;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                int a = rnd(-1000, 1000);
                cout << a << " \n"[j == 3];
                out << a << " \n"[j == 3];
            }
        }
        out.close();
        system("./gauss_jordan < in.txt > out1.txt");

        ifstream in1("out1.txt");
        bool bad = false;
        for (int i = 0; i < 3; ++i) {

            long double a, b;
            in1 >> a >> b;
            cout << a << " " << b << "\n";
            if (abs(a - b) > 1e-6) {
                bad = true;
            }
        }

        in1.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good" << "\n";
}