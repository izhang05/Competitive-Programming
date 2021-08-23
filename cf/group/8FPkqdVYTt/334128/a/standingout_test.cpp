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
        int n = rnd(1, 2);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 0; i < n; ++i) {
            int m = rnd(1, 5);
            for (int j = 0; j < m; ++j) {
                char c = rnd('a', 'd');
                cout << c;
                out << c;
            }
            cout << "\n";
            out << "\n";
        }
        out.close();
        system("./standingout < in.txt > out1.txt");
        system("./standingout_brute < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        cout << "\n";
        long long a, b;
        for (int i = 0; i < n; ++i) {
            in1 >> a;
            in2 >> b;
            cout << a << " " << b << "\n";
            if (a != b) {
                bad = true;
            }
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