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
        int n = rnd(3, 7);
        cout << n << "\n";
        out << n << "\n";
        vector<int> a_ar(n), b_ar(n);
        for (int i = 0; i < n; ++i) {
            a_ar[i] = b_ar[i] = i + 1;
        }
        shuffle(a_ar.begin(), a_ar.end(), rng);
        shuffle(b_ar.begin(), b_ar.end(), rng);
        for (int i = 0; i < n; ++i) {
            cout << a_ar[i] << " \n"[i == n - 1];
            out << a_ar[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; ++i) {
            cout << b_ar[i] << " \n"[i == n - 1];
            out << b_ar[i] << " \n"[i == n - 1];
        }
        out.close();
        system("./photoshoot < in.txt > out1.txt");
        system("./brute_photoshoot < in.txt > out2.txt");

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