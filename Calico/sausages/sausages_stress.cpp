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

        int t = 1;
        cout << t << "\n";
        out << t << "\n";
        int n = rnd(1, 5), k = rnd(1, 5);
        cout << n << " " << k << "\n";
        out << n << " " << k << "\n";
        vector<int> l(n), h(n);
        for (int i = 0; i < n; ++i) {
            int cur_l = rnd(1, 7), cur_h = rnd(cur_l + 1, 10);
            l[i] = cur_l, h[i] = cur_h;
        }
        for (int i = 0; i < n; ++i) {
            cout << h[i] << " \n"[i == n - 1];
            out << h[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; ++i) {
            cout << l[i] << " \n"[i == n - 1];
            out << l[i] << " \n"[i == n - 1];
        }
        out.close();
        system("./a < in.txt > out1.txt");
        system("./brute < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        string a, b;
        getline(in1, a);
        getline(in2, b);
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
    cout << "Good" << "\n";
}