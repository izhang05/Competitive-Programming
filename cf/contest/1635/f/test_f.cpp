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
        int n = rnd(2, 10), q = rnd(1, 10);
        cout << n << " " << q << "\n";
        out << n << " " << q << "\n";
        int pre = rnd(-50, 50);
        for (int i = 0; i < n; ++i) {
            pre += rnd(1, 5);
            int w = rnd(1, 5);
            cout << pre << " " << w << "\n";
            out << pre << " " << w << "\n";
        }
        for (int i = 0; i < q; ++i) {
            int l = rnd(1, n - 1), r = rnd(l + 1, n);
            cout << l << " " << r << "\n";
            out << l << " " << r << "\n";
        }

        out.close();
        system("./f < in.txt > out1.txt");
        system("./correct_f < in.txt > out2.txt");

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