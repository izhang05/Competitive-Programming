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
        int n;
        n = rnd(5, 5);
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        cout << n << "\n";
        out << n << "\n";
        shuffle(nums.begin(), nums.end(), rng);
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " \n"[i == n - 1];
            out << nums[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; ++i) {
            char c = rnd(0, 1) ? 'U' : 'D';
            cout << c;
            out << c;
        }
        cout << "\n";
        out << "\n";

        out.close();
        system("./C < in.txt > out1.txt");
        //        system("./brute < in.txt > out2.txt");

        //        ifstream in1("out1.txt"), in2("out2.txt");
        //        bool bad = false;
        //
        //        long long a, b;
        //        in1 >> a;
        //        in2 >> b;
        //        cout << a << " " << b << "\n";
        //        if (a != b) {
        //            bad = true;
        //        }
        //
        //        in1.close();
        //        in2.close();
        //        if (bad) {
        //            cout << "bad\n";
        //            return 0;
        //        }
    }
    cout << "Good"
         << "\n";
}