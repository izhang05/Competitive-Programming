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
    int trials = 10000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");

        int t = 1, k = 0;
        cout << t << "\n";
        out << t << "\n";
        int n = rnd(1, 11);
        cout << n << " " << k << "\n";
        out << n << " " << k << "\n";
        vector<char> pos{'R', 'G', 'W', 'W', 'W', 'W', 'W'};
        for (int i = 0; i < n; ++i) {
            char s = pos[rnd(0, 6)];
            cout << s;
            out << s;
        }
        cout << "\n";
        out << "\n";

        out.close();
        system("./2c < in.txt > out1.txt");
        system("./2c_brute < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good" << "\n";
}
//17 0
//WWWRWWWWWGGWGWWWW