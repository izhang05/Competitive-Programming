/*
ID: izhang01
TASK: rental
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
}


vector<pair<int, int> > stores;
vector<int> cows;
vector<int> rent;
vector<long long> rent_pre;
vector<long long> cows_pre;
vector<long long> stores_pre;
set<int> stores_milk;
map<int, int> stores_index;

long long find_milk(int n) {
    assert(n < rent_pre.size());
    long long sol = rent_pre[n];
    assert(cows.size() - n < cows_pre.size());
    long long avail = cows_pre[cows.size() - n];
    assert(min(avail, (long long) stores_pre.size() - 1) < stores_pre.size());
    auto it = stores_milk.upper_bound(avail);
    --it;
    int upper = *it;
//    cout << avail << " " << upper << "\n";
    sol += stores_pre[stores_index[upper]] + (avail - upper) * stores[stores_index[upper]].second;
//    sol += stores_pre[min(avail, (long long) stores_pre.size() - 1)];
//    for (pair<int, int> i : stores) {
//        int buy = min(avail, (long long) i.first);
//        sol += buy * i.second;
//        avail -= buy;
//        if (!avail) {
//            break;
//        }
//    }
    return sol;
}


int main() {
    setIO();
    int n, m, r;
    cin >> n >> m >> r;
    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    cows_pre.resize(n + 1);
    cows_pre[0] = 0;
    for (int i = 0; i < n; ++i) {
        cows_pre[i + 1] = cows_pre[i] + cows[n - i - 1];
    }

    stores.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> stores[i].first >> stores[i].second;
    }
    sort(stores.begin(), stores.end(), [](pair<int, int> i, pair<int, int> j) {
        return i.second > j.second;
    });

    long long pre = 0;
    int milk = 0;
    stores_milk.insert(0);
    int ind = 1;
    stores_index[0] = milk;
    for (pair<int, int> i : stores) {
        stores_pre.push_back(pre);
        milk += i.first;
        stores_milk.insert(milk);
        stores_index[milk] = ind;
        ++ind;
        pre += i.first * i.second;
    }
    stores_pre.push_back(pre);

    rent.resize(r);
    for (int i = 0; i < n; ++i) {
        cin >> rent[i];
    }
    sort(rent.begin(), rent.end(), greater<int>());
    rent_pre.resize(r + 1);
    rent_pre[0] = 0;
    for (int i = 0; i < r; ++i) {
        rent_pre[i + 1] = rent_pre[i] + rent[i];
    }

    long long sol = 0;
    for (int i = 0; i < min(n + 1, r + 1); ++i) {
        sol = max(sol, find_milk(i));
//        cout << i << " " << sol << "\n";
    }
//    for (auto i : stores_index) {
//        cout << i.first << " " << i.second << " " << stores_pre[i.second] << "\n";
//    }
//    for (int i : stores_milk) {
//        cout << i << "\n";
//    }
    cout << sol << "\n";
    return 0;
}