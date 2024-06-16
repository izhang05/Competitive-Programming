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
    cout << read_file(file1)[0] << " " << read_file(file2)[0] << "\n";
    return read_file(file1) == read_file(file2);
}

int main() {
    srand(time(nullptr));
    int trials = 1000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int t = 1;
        cout << t << "\n";
        out << t << "\n";
        int n = rnd(2, 100);
        for (int i = 0; i < n; ++i) {
            if (rnd(0, 3) == 0) {
                cout << 'b';
                out << 'b';
            } else {
                cout << 'a';
                out << 'a';
            }
        }
        cout << "\n";
        out << "\n";

        out.close();
        system("./d < in.txt > out1.txt");
        system("./brute_brute_d < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}
