// c++ solution still overflows no matter how many times I mod in between.
// solved with python.

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//const int MOD = 1000000007;
//
//int main() {
//    freopen("1.in", "r", stdin);
//    freopen("solution.out", "w", stdout);
//    int t, n, k;
//    unsigned long long solution;
//    cin >> t;
//    while (t--) {
//        cin >> n >> k;
//        if (n == 0) {
//            solution = ((k - 1) * k) % MOD;
//        } else {
//            solution = (unsigned long long) (pow(n, 2)) % MOD;
//            cout << solution << "\n";
//            solution += ((unsigned long long) (((2 * n) % MOD) * (k / 2) % MOD)) % MOD;
//            solution %= MOD;
//            cout << solution << "\n";
//            solution += (((k - 1) / 2) % MOD * ((k - 1) / 2 + 1) % MOD) % MOD;
//            cout << (((k - 1) / 2) * ((k - 1) / 2 + 1)) << "\n";
//            solution %= MOD;
//        }
//        cout << solution << "\n";
//    }
//    return 0;
//}


//import sys
//
//readLine = lambda: sys.stdin.readline()
//readInt = lambda: int(sys.stdin.readline())
//readInts = lambda: [int(x) for x in sys.stdin.readline().split(" ")]
//
//MOD = 1000000007
//for _ in range(readInt()):
//    n, k = readInts()
//    print(((k - 1) * k) % MOD if n == 0 else (n ** 2 + 2 * n * (k // 2) + ((k - 1) // 2) * ((k - 1) // 2 + 1)) % MOD)
//    # if n == 0:
//    #     solution = ((k - 1) * k) % MOD
//    # else:
//    #     solution = (n ** 2 + 2 * n * (k // 2) + ((k - 1) // 2) * ((k - 1) // 2 + 1)) % MOD
//    # print(solution)

