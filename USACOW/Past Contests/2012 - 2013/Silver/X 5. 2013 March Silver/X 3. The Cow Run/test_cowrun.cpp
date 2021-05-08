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
        ofstream out("cowrun.in");
        int n = rnd(5, 5);
        out << n << "\n";
        cout << n << "\n";
        vector<int> avail(5000);
        for (int i = 0; i < 5000; ++i) {
            avail[i] = i - 2500;
        }
        for (int i = 0; i < n; ++i) {
            int ind = rnd(0, int(avail.size()) - 1);
            out << avail[ind] << "\n";
            cout << avail[ind] << "\n";
            avail.erase(avail.begin() + ind);
        }
        out.close();
        system("./cowrun > out1.txt");
        system("./brute_cowrun > out2.txt");

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
//8
//10
//-5
//7
//2
//-5
//-2
//7
//2
