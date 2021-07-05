#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    int trials = 200;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int n = rnd(3, 5);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 0; i < n; ++i) {
            if (rnd(0, 1)) {
                cout << '+' << " ";
                out << '+' << " ";
                int c = rnd(1, 10);
                cout << c << "\n";
                out << c << "\n";
            } else {
                cout << '-' << "\n";
                out << '-' << "\n";
            }
        }

        out.close();
        system("./d < in.txt > out1.txt");
        system("./brute_d < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        if (a != b) {
            bad = true;
        }

        in1.close();
        in2.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
}