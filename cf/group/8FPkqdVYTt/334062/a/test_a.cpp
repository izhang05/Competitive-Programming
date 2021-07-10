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
        ofstream out("mincross.in");
        int n = rnd(200, 400);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 0; i < 2; ++i) {
            vector<int> nums(n);
            for (int j = 0; j < n; ++j) {
                nums[j] = j + 1;
            }
            shuffle(nums.begin(), nums.end(), rng);
            for (auto &j : nums) {
                cout << j << "\n";
                out << j << "\n";
            }
        }
        out.close();
        system("./334062a > out1.txt");
        system("./334062brute_a > out2.txt");

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
    cout << "Yay" << "\n";
}