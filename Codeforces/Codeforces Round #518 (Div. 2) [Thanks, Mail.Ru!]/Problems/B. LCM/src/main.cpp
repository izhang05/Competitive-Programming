#include <bits/stdc++.h>

using namespace std;

//unordered_map<long long, long long> factor(long long n) {
//    unordered_map<long long, long long> solution;
//    long long  original_n = n;
//    if (n % 2 == 0) {
//        solution[2] = 1;
//        n /= 2;
//    }
//    while (n % 2 == 0) {
//        ++solution[2];
//        n /= 2;
//    }
////    cout << n << endl;
////    cout << solution[2] << endl;
//    if (n % 3 == 0) {
//        solution[3] = 1;
//        n /= 3;
//        while (n % 3 == 0) {
//            ++solution[3];
//            n /= 3;
//            //                cout << i << "\n";
//            //                cout << n << "\n";
//        }
//    }
//    int inc = 0;
//    for (int i = 5; n > 1 && i * i <= original_n; i += 2) {
//        if (n % i == 0) {
//            solution[i] = 1;
//            n /= i;
//            while (n % i == 0) {
//                ++solution[i];
//                n /= i;
////                cout << i << "\n";
////                cout << n << "\n";
//            }
//        }
//        i += inc;
//        inc = 2 - inc;
//    }
//    if (n > 1) {
//        solution[n] = 1;
//    }
//    return solution;
//}

int num_divisors(long long n) {
    int solution = 0;
    bool square = false;
    for (long long  i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ++solution;
        }
        if (i * i == n) {
            square = true;
        }
    }
    solution *= 2;
    if (square) {
        --solution;
    }
    return solution;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long b;
    cin >> b;
    cout << num_divisors(b) << "\n";
    return 0;
}