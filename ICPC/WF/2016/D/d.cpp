#include <bits/stdc++.h>

using namespace std;

const vector<vector<vector<char>>> digits = {
        {
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', '.', '.', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
        },
        {
                {'.', '.', '.', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', '.'},
                {'X', '.', '.', '.'},
                {'.', 'X', 'X', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
        },
        {
                {'.', '.', '.', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', '.'},
                {'X', '.', '.', '.'},
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', '.'},
                {'X', '.', '.', '.'},
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
        },
        {
                {'.', 'X', 'X', '.'},
                {'X', '.', '.', 'X'},
                {'X', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
                {'.', '.', '.', 'X'},
                {'.', '.', '.', 'X'},
                {'.', 'X', 'X', '.'},
        },
};

vector<vector<char>> get_time(int hour, int minute){
    vector<vector<char>> time(7, vector(21, '.'));

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            if(hour >= 10) time[i][j] = digits[hour / 10][i][j];

            time[i][j + 5] = digits[hour % 10][i][j];

            time[i][j + 12] = digits[minute / 10][i][j];

            time[i][j + 17] = digits[minute % 10][i][j];
        }
    }

    time[2][10] = time[4][10] = 'X';

    return time;
}

void debug(vector<vector<char>> vec){
    for(auto x : vec){
        for(auto y : x){
            cout << y;
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<array<bool, 3>>> compare(vector<vector<char>> &good, vector<vector<char>> &bad){
    vector<vector<array<bool, 3>>> check(7, vector(21, array<bool, 3>{{true, true, true}}));

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 21; j++){
            if(good[i][j] == '.' && bad[i][j] == '.') check[i][j][1] = false;
            else if(good[i][j] == '.' && bad[i][j] == 'X') check[i][j][0] = check[i][j][2] = false;
            else if(good[i][j] == 'X' && bad[i][j] == '.') check[i][j][1] = check[i][j][2] = false;
            else if(good[i][j] == 'X' && bad[i][j] == 'X') check[i][j][0] = false;
        }
    }

    return check;
}

int n;

vector<vector<vector<char>>> arr;

vector<vector<array<bool, 3>>> ans(7, vector(21, array<bool, 3>{{false, false, false}}));

int goodcnt = 0;

void test(int hour, int minute){
    vector<vector<array<bool, 3>>> testans(7, vector(21, array<bool, 3>{{true, true, true}}));

    for(int x = 0; x < n; x++){
        int newmin = minute + x;
        int newhour = hour + newmin / 60;
        newmin %= 60;
        newhour %= 24;

        vector<vector<char>> good = get_time(newhour, newmin);

        vector<vector<array<bool, 3>>> comparison = compare(good, arr[x]);

        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 21; j++){
                testans[i][j][0] &= comparison[i][j][0];
                testans[i][j][1] &= comparison[i][j][1];
                testans[i][j][2] &= comparison[i][j][2];

                if(testans[i][j][0] || testans[i][j][1] || testans[i][j][2]) continue;

                if(testans[i][j][0] || testans[i][j][1] || testans[i][j][2]) continue;
                else return;
            }
        }
    }

    for(int i = 0; i < 7; i++){
        for (int j = 0; j < 21; j++) {
            ans[i][j][0] |= testans[i][j][0];
            ans[i][j][1] |= testans[i][j][1];
            ans[i][j][2] |= testans[i][j][2];
        }
    }

    goodcnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    arr.assign(n, vector(7, vector(21, '.')));

    for(auto &x : arr){
        for(auto &y : x){
            for(auto &z : y){
                cin >> z;
            }
        }
    }

    for(int hour = 0; hour < 24; hour++){
        for(int minute = 0; minute < 60; minute++){
            test(hour, minute);
        }
    }

    if(goodcnt == 0) cout << "impossible";
    else{
        vector<vector<char>> templ = get_time(88, 88);

        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 21; j++){
                if(templ[i][j] == '.') cout << '.';
                else{
                    if(ans[i][j][0] && !ans[i][j][1] && !ans[i][j][2]) cout << '0';
                    else if(!ans[i][j][0] && ans[i][j][1] && !ans[i][j][2]) cout << '1';
                    else if(!ans[i][j][0] && !ans[i][j][1] && ans[i][j][2]) cout << 'W';
                    else cout << '?';
                }
            }
            cout << '\n';
        }
    }
}