#include <iostream>


using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int skills[n];
        for (int i = 0; i < n; ++i) {
            int skill;
            cin >> skill;
            skills[i] = skill;
        }
        sort(skills, skills + n);

    }
    return 0;
}
