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
    int trials = 200;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");

        int n = rnd(4, 8);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 2; i <= n; ++i) {
            int p = rnd(1, i - 1);
            cout << p << " \n"[i == n];
            out << p << " \n"[i == n];
        }
        out.close();
        system("./subtree_activation < in.txt > out1.txt");
        system("./subtree_activation_brute < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}