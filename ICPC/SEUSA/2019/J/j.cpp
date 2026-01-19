#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++nums[a[i]];
    }
    vector<int> sol;

    vector<int> cur;
    for (int i = 0; i < n; ++i) {
        if (nums.find(a[i]) == nums.end()) {
            continue;
        }
        auto it = lower_bound(cur.begin(), cur.end(), a[i]);
        int ind = it - cur.begin();
        if (it == cur.end() || *it != a[i]) {
            while ((int) cur.size() > ind) {
                cur.pop_back();
            }
            cur.push_back(a[i]);
        }
        --nums[a[i]];
        if (nums[a[i]] == 0) {
            int end = -1;
            for (int l = 0; l < int(cur.size()); ++l) {
                int j = cur[l];
                sol.push_back(j);
                nums.erase(j);
                if (j == a[i]) {
                    end = l;
                    break;
                }
            }
            vector<int> new_cur;
            for (int j = end + 1; j < int(cur.size()); ++j) {
                new_cur.push_back(cur[j]);
            }
            swap(cur, new_cur);
            nums.erase(a[i]);
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << sol[i] + 1 << " \n"[i == n - 1];
    }

}
