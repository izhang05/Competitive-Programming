#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353, N = 1e5 + 5;

int add(int a, int b){
    int c = a + b;
    if(c >= MOD) c -= MOD;
    return c;
}

int subt(int a, int b){
    int c = a - b;
    if(c < -0) c += MOD;
    return c;
}

int mult(int a, int b){
    return (1ll * a * b) % MOD;
}

int binpow(int a, int b){
    int c = 1;
    for(; b > 0; b /= 2, a = mult(a, a)) if(b & 1) c = mult(c, a);
    return c;
}


vector<int> pows(N, 1), invpows(N, 1);

struct Item{
    int len;
    int arr[3][3];

    Item(int x = -1){
        len = 1;
        memset(arr, -1, sizeof(arr));

        for(int y = 0; y < 3; y++){
            if(y == x) arr[x][x] = 0;
            else{
                int z;

                if(x != 0 && y != 0) z = 0;
                if(x != 1 && y != 1) z = 1;
                if(x != 2 && y != 2) z = 2;

                arr[z][y] = 1;
            }
        }
    }
};

Item merge(Item &a, Item &b){
    Item c;

    c.len = a.len + b.len;

    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            for(int z = 0; z < 3; z++){
                c.arr[x][y] = add(a.arr[x][z], mult(pows[a.len], b.arr[z][y]));
            }
        }
    }

    return c;
}

Item unmerge(Item a, Item b){
    Item c;

    c.len = b.len - a.len;

    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            for(int z = 0; z < 3; z++){
                c.arr[x][y] = mult(invpows[a.len], subt(b.arr[z][y], a.arr[x][z]));
            }
        }
    }

    return c;
}

struct Fenwick{
    Item tree[N];

    Item getsum(int x){
        Item ans = tree[x];

        for(int i = x - (x & -x); i > 0; i -= i & -i) ans = merge(tree[i], ans);

        return ans;
    }

    void update(int x, int y){
        tree[x] = Item(y);

        for(int i = x + (x & -x); i < N; i += i & -i) tree[x] = merge(tree[x], tree[i]);
    }

    Item query(int l, int r){
        return unmerge(getsum(r), getsum(l - 1));
    }
};

Fenwick fw;

int n, q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    for(int i = 1; i < N; i++) pows[i] = mult(pows[i - 1], 2);

    invpows[N - 1] = binpow(pows[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) invpows[i] = mult(invpows[i + 1], 2);

    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int x;

        cin >> x;

        x--;

        fw.update(i, x);
    }

    while(q--){
        char c;
        int a, b;

        cin >> c >> a >> b;

        if(c == 'c') fw.update(a, b - 1);
        else{
            Item itm = fw.query(a, b);

            int ans = -1;

            for(int i = 0; i < 3; i++){
                if(itm.arr[i][0] != -1){
//                    if(ans != -1) assert(false);

                    ans = itm.arr[i][0];
                }
            }

            cout << ans << "\n";
        }
    }
}
