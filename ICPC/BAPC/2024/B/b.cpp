#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, k;

vector<vector<int>> graph;

vector<vector<int>> moves = {
        {0, 1, 2, 3},
        {3, 0, 1, 2},
        {1, 2, 3, 0}
};

vector<int> inverses = {2, 3, 0, 1};

vector<vector<vector<vector<int>>>> dist;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> k;

    if(n == 1){
        cout << 0;
        return 0;
    }

    graph.assign(n, vector<int>(4, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> graph[i][j];

            graph[i][j]--;
        }
    }

    dist.assign(k + 1, vector(n, vector(4, vector(3, INF))));

    priority_queue<vector<int>> que;

    for(int dir = 0; dir < 4; dir++){
        if(graph[0][dir] != -1){
            int newdir = -1;

            for(int otherdir = 0; otherdir < 4; otherdir++){
                if(graph[graph[0][dir]][otherdir] == 0){
                    newdir = inverses[otherdir];
                }
            }

            dist[0][graph[0][dir]][newdir][0] = 1;
            que.push({0, -dist[0][graph[0][dir]][newdir][0], graph[0][dir], newdir, 0});
        }
    }

    while(!que.empty()){
        auto vec = que.top(); que.pop();

        int cnt = -vec[0], node = vec[2], dir = vec[3], blink = vec[4];

        if(blink == 0){
            if(cnt + 1 <= k && dist[cnt][node][dir][0] < dist[cnt +  1][node][dir][1]){
                dist[cnt + 1][node][dir][1] = dist[cnt][node][dir][0];
                que.push({-(cnt + 1), -dist[cnt + 1][node][dir][1], node, dir, 1});
            }
            if(cnt + 1 <= k && dist[cnt][node][dir][0] < dist[cnt +  1][node][dir][2]){
                dist[cnt + 1][node][dir][2] = dist[cnt][node][dir][0];
                que.push({-(cnt + 1), -dist[cnt + 1][node][dir][2], node, dir, 2});
            }
        }
        else if(blink == 1){
            if(dist[cnt][node][dir][1] < dist[cnt][node][dir][0]){
                dist[cnt][node][dir][0] = dist[cnt][node][dir][1];
                que.push({-cnt, -dist[cnt][node][dir][0], node, dir, 0});
            }
        }
        else if(blink == 2){
            if(dist[cnt][node][dir][2] < dist[cnt][node][dir][0]){
                dist[cnt][node][dir][0] = dist[cnt][node][dir][2];
                que.push({-cnt, -dist[cnt][node][dir][0], node, dir, 0});
            }
        }

        if(graph[node][moves[blink][dir]] != -1){
            int newdir = -1;

            for(int otherdir = 0; otherdir < 4; otherdir++){
                if(graph[graph[node][moves[blink][dir]]][otherdir] == node){
                    newdir = inverses[otherdir];
                }
            }

            if(dist[cnt][node][dir][blink] + 1 < dist[cnt][graph[node][moves[blink][dir]]][newdir][blink]){
                dist[cnt][graph[node][moves[blink][dir]]][newdir][blink] = dist[cnt][node][dir][blink] + 1;
                que.push({-cnt, -dist[cnt][graph[node][moves[blink][dir]]][newdir][blink], graph[node][moves[blink][dir]], newdir, blink});
            }
        }
    }

    int ans = -1;

    for(int cnt = 0; cnt <= k; cnt++){
        for(int dir = 0; dir < 4; dir++){
            for(int blink = 0; blink < 3; blink++){
                if(dist[cnt][n - 1][dir][blink] != INF){
                    if(ans == -1 || dist[cnt][n - 1][dir][blink] < ans){
                        ans = dist[cnt][n - 1][dir][blink];
                    }
                }
            }
        }
    }

    if(ans == -1) cout << "impossible";
    else cout << ans;
}