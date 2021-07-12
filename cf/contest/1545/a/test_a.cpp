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
        int t = rnd(1, 5);
        cout << t << "\n";
        out << t << "\n";
        for (int _ = 0; _ < t; ++_) {
            int n = rnd(1, 10);
            cout << n << "\n";
            out << n << "\n";
            for (int i = 0; i < n; ++i) {
                int a = rnd(1, 5);
                cout << a << " \n"[i == n - 1];
                out << a << " \n"[i == n - 1];
            }
        }
        out.close();
        system("./a < in.txt > out1.txt");
        system("./1545brute_a < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        string a, b;
        while (t--) {
            in1 >> a;
            in2 >> b;
            if (a != b) {
                bad = true;
            }
            cout << a << " " << b << "\n";
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