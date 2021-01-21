#include <bits/stdc++.h>

using namespace std;

int n;
multiset<int> nums;


int mex() {
    int pre = *nums.begin();
    if (pre != 0) {
        return 0;
    }
    for (int i : nums) {
        if (i != pre && i != pre + 1) {
            return pre + 1;
        }
        pre = i;
    }
    return pre + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        nums.clear();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            nums.insert(a[i]);
        }
        cout << 2 * n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << " ";
            int num = mex();
            nums.insert(num);
            nums.erase(nums.lower_bound(a[i]));
            a[i] = num;
//            for (int j : a) {
//                cout << j << " ";
//            }
//            cout << "\n";
        }
//        for (int i : a) {
//            cout << i << " ";
//        }
//        cout << "\n";
        int index = max(0, mex() - 1);
        if (index == n - 1) {


            int num;
//        if (a[n - 1] == n - 1) {
//            for (int i = n; i > 0; --i) {
//                cout << i << " ";
//            }
//            cout << endl;
//            continue;
//        }
            for (int i = 1; i < n; ++i) {
                cout << index + 1 << " ";
                num = a[index];
                a[index] = index + 1;
//            if (num == index) {
//                --index;
//            } else {
                index = max(num - 1, 0);
//            }
            }
            cout << index + 1;
        } else {
            int num;
            for (int i = 1; i < n; ++i) {
                cout << index + 1 << " ";
                num = a[index];
                a[index] = index + 1;
//            if (num == index) {
//                --index;
//            } else {
                index = num;
//            }
            }
        }
        cout << endl;
    }
    return 0;
}
