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
        ofstream out("snakes.in");
        int n = 4, k = rnd(0, n - 1);
        cout << n << " " << k << "\n";
        out << n << " " << k << "\n";
        for (int i = 0; i < n; ++i) {
            int a = rnd(1, 5);
            cout << a << " \n"[i == n - 1];
            out << a << " \n"[i == n - 1];
        }
        out.close();
        system("./snakes");
        system("./sophia_snakes");

        ifstream in1("snakes.out"), in2("snakes1.out");
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