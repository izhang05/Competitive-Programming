///*
//ID: izhang01
//TASK: odometer
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("odometer.in", "r", stdin);
//    freopen("odometer.out", "w", stdout);
//}
//
//bool interest(long long n) {
//    map<long long, long long> occur;
//    vector<int> nums;
//    occur[n % 10] = 1;
//    nums.push_back(n % 10);
//    n /= 10;
//    while (n) {
//        long long digit = n % 10;
//        if (occur.find(digit) == occur.end()) {
//            if (occur.size() >= 2) {
//                return false;
//            }
//            occur[digit] = 1;
//            nums.push_back(digit);
//        } else {
//            ++occur[digit];
//            if (nums.size() > 1 && occur[nums[0]] > 1 && occur[nums[1]] > 1) {
//                return false;
//            }
//        }
//        n /= 10;
//    }
//    return nums.size() == 2;
//}
//
//
//int main() {
//    setIO();
//    long long x, y;
//    cin >> x >> y;
//    x = 100000, y = 999999;
//    int sol = 0;
//    for (long long i = x; i < y + 1; ++i) {
//        if (interest(i)) {
//            ++sol;
//            cout << i << "\n";
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}

/*
ID: izhang01
TASK: odometer
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
}

const int maxn = 16;

int main() {
    setIO();
    long long x, y;
    cin >> x >> y;
    int sol = 0;
    for (int len = 3; len < log10(y) + 1; ++len) {
        for (int i = 1; i < 10; ++i) {
            long long num = 0;
            for (int j = 0; j < len; ++j) {
                num += i * (long long) pow(10, j);
            }
            for (int j = 0; j < 10; ++j) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < len; ++k) {
                    if (j == 0 && k == len - 1) {
                        break;
                    }
                    num -= i * (long long) pow(10, k);
                    num += j * (long long) pow(10, k);
//                    cout << num << "\n";
                    if (x <= num && y >= num) {
                        ++sol;
                    }
                    num -= j * (long long) pow(10, k);
                    num += i * (long long) pow(10, k);
                }
            }
        }
        for (int i = 1; i < 10; ++i) {
            long long num = i * (long long) pow(10, len - 1);
            if (x <= num && y >= num) {
                ++sol;
            }
//            cout << num << "\n";
        }
    }
    if (y == (long long) 1e16) {
        ++sol;
    }
    cout << sol << "\n";
    return 0;
}
