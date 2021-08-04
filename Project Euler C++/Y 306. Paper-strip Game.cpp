#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int grundy[maxn];

int main() {
//    int n = 1e4;
//    int sol = 0;
////    cout << 1 << " " << 0 << "\n";
//    cout << 0 << " ";
//    for (int i = 2; i <= n; ++i) {
//        set<int> nums;
//        for (int j = 0; j <= i - 2 - j; ++j) {
//            nums.insert(grundy[j] ^ grundy[i - 2 - j]);
//        }
//        int pre = -1;
//        grundy[i] = -1;
//        for (auto &j : nums) {
//            if (j != pre + 1) {
//                grundy[i] = pre + 1;
//                break;
//            }
//            pre = j;
//        }
//        if (grundy[i] == -1) {
//            grundy[i] = pre + 1;
//        }
////        cout << i << " " << grundy[i] << "\n";
//        cout << grundy[i] << " ";
//        if (i % 34 == 0) {
//            cout << "\n";
//        }
//        if (grundy[i]) {
//            ++sol;
//        }
//    }
//    cout << "\n";
//    cout << sol << "\n";

    //grundy numbers are cyclic with period 34

    int n = 1e6;

    int sol = 29 * (n / 34) - 2;
    n -= 34 * (n / 34);
    vector<int> indices;
    for (int i = 1; i <= 34; ++i) {
        indices.push_back(i);
    }
    vector<int> bad{4, 8, 20, 24, 28};
    for (auto &i : bad) {
        indices.erase(find(indices.begin(), indices.end(), i));
    }

    for (auto &i : indices) {
        if (n > i) {
            ++sol;
        }
    }
    cout << sol << "\n";

    return 0;
}

//3 3 5 5 3 3 5 3 3 11 3 3 9
