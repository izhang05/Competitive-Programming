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
//        cout << 1 << "\n";
        out << 1 << "\n";
        int n = rnd(1, 2e5);
//        cout << n << "\n";
        out << n << "\n";
        for (int i = 0; i < n; ++i) {
            int a = rnd(0, 15);
//            cout << a << " \n"[i == n - 1];
            out << a << " \n"[i == n - 1];
        }

        out.close();
        system("./f2 < in.txt > out1.txt");
        system("./f2_correct < in.txt > out2.txt");

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