#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> m >> k;
    int t, a, b;
    vector<pair<int, int> > both, alice, bob, none;
    for (int i = 0; i < n; ++i) {
        cin >> t >> a >> b;
        if (a & b) {
            both.emplace_back(t, i);
        } else if (a) {
            alice.emplace_back(t, i);
        } else if (b) {
            bob.emplace_back(t, i);
        } else {
            none.emplace_back(t, i);
        }
    }
    if (both.size() + alice.size() < k || both.size() + bob.size() < k) {
        cout << -1 << "\n";
        return 0;
    }
    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    sort(none.begin(), none.end());
    set<int> index;
    long long bo_ind = 0, al_ind = 0, b_ind = 0, read = 0, m_read = 0, sol = 0;
    while (read < k) {
        if (m_read + 1 == m) {
            if (bo_ind >= both.size()) {
                cout << -1 << "\n";
                return 0;
            }
            sol += both[bo_ind].first;
            index.insert(both[bo_ind].second);
            ++m_read;
            ++bo_ind;
        } else if (m_read >= m) {
            if (bo_ind >= both.size()) {
                cout << -1 << "\n";
                return 0;
            }
            --al_ind;
            --b_ind;
            sol -= alice[al_ind].first + bob[b_ind].first;
            index.erase(alice[al_ind].second);
            index.erase(bob[b_ind].second);
            sol += both[bo_ind].first;
            index.insert(both[bo_ind].second);
            --m_read;
            ++bo_ind;
        } else if (bo_ind < both.size() && al_ind < alice.size() && b_ind < bob.size()) {
            if (both[bo_ind].first < alice[al_ind].first + bob[b_ind].first) {
                sol += both[bo_ind].first;
                index.insert(both[bo_ind].second);
                ++m_read;
                ++bo_ind;
            } else {
                sol += alice[al_ind].first + bob[b_ind].first;
                index.insert(alice[al_ind].second);
                index.insert(bob[b_ind].second);
                m_read += 2;
                ++al_ind;
                ++b_ind;
            }
        } else if (bo_ind < both.size()) {
            sol += both[bo_ind].first;
            index.insert(both[bo_ind].second);
            ++m_read;
            ++bo_ind;
        } else {
            sol += alice[al_ind].first + bob[b_ind].first;
            index.insert(alice[al_ind].second);
            index.insert(bob[b_ind].second);
            m_read += 2;
            ++al_ind;
            ++b_ind;
        }
        ++read;
    }
    both.emplace_back(1e9, 0);
    alice.emplace_back(1e9, 0);
    bob.emplace_back(1e9, 0);
    none.emplace_back(1e9, 0);
    int no_ind = 0;
    while (m_read < m) {
        if (al_ind >= alice.size() - 1 && b_ind >= bob.size() - 1 && bo_ind >= both.size() - 1 &&
            no_ind >= none.size() - 1) {
            cout << -1 << "\n";
            return 0;
        }
        int minimum = min({alice[al_ind].first, bob[b_ind].first, both[bo_ind].first, none[no_ind].first});
        if (alice[al_ind].first == minimum) {
            index.insert(alice[al_ind].second);
            ++al_ind;
        } else if (bob[b_ind].first == minimum) {
            index.insert(bob[b_ind].second);
            ++b_ind;
        } else if (both[bo_ind].first == minimum) {
            index.insert(both[bo_ind].second);
            ++bo_ind;
        } else {
            index.insert(none[no_ind].second);
            ++no_ind;
        }
        ++m_read;
        sol += minimum;
    }
    cout << sol << "\n";
    for (int i : index) {
        cout << i + 1 << " ";
    }
    return 0;
}
