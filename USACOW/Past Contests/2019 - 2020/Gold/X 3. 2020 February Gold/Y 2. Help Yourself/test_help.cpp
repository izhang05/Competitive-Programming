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
        int n = rnd(3, 3);
        out << n << "\n";
        vector<int> nums;
        for (int i = 1; i < 7; ++i) {
            nums.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int l = rnd(0, nums.size() - 2);
            out << nums[l] << " ";
            nums.erase(nums.begin() + l);
            int r = rnd(l, nums.size() - 1);
            out << nums[r] << "\n";
            nums.erase(nums.begin() + r);
        }
        out.close();
        system("./help_gold < in.txt > out1.txt");
        system("./brute_help < in.txt > out2.txt");

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