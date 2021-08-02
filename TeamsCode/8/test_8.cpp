#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    //20000
    for (int i = 493900; i <= 5e5; ++i) {
        ofstream out("in.txt");
        out << 1 << "\n";
        out << i << "\n";
        cout << 1 << "\n";
        cout << i << endl;
        out.close();
        system("./8 < in.txt > out1.txt");
        system("./correct_8 < in.txt > out2.txt");

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
        cout << a << " " << b << endl;
        if (bad) {
            cout << "bad\n";
            cout << i << " " << a << " " << b << endl;
            ofstream out_bad("bad.txt");
            out_bad << i << " " << a << " " << b << endl;
            out_bad.close();
        }
    }
    cout << "Good" << "\n";
}