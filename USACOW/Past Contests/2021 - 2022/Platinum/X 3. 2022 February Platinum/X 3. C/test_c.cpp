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
        cout << 1 << "\n";
        out << 1 << "\n";
        int n = rnd(4, 4);
        for (int i = 0; i < n; ++i) {
            char c = rnd('1', '9');
            cout << c;
            out << c;
        }
        cout << "\n";
        out << "\n";

        out.close();
        system("./C < in.txt > out1.txt");
        system("./brute_C < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        cout << a << " " << b << "\n";
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
    cout << "Good"
         << "\n";
}
