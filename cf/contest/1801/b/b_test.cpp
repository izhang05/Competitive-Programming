#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

bool equal(string file1, string file2) {
    auto read_file = [&](string f) {
        vector<string> words;
        ifstream in(f);
        string token;
        while (in >> token) words.push_back(token);
        return words;
    };
    return read_file(file1) == read_file(file2);
}

int main() {
    srand(time(nullptr));
    int trials = 1000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");

        cout << 1 << "\n";
        out << 1 << "\n";
        int n = rnd(2, 15);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 0; i < n; ++i) {
            int a = rnd(1e8, 1e9), b = rnd(1e5, 1e9);
            cout << a << " " << b << "\n";
            out << a << " " << b << "\n";
        }
        out.close();
        system("./b < in.txt > out1.txt");
        system("./b_brute < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}