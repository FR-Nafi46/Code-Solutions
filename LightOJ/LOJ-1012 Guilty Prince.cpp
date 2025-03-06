/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 00:04:02
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
#define lcm(a,b) ((a*b)/__gcd(a,b))
#define debug(x) cout << "Debug : " << x << endl;
const double PI = 2 * acos(0.0);
const int MOD = 1000000007;

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int dfs(vector <vector <char>> &g, int x, int y, int n, int m){
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
        return 0;
    
    g[x][y] = '#';

    int cnt = 1;
    for (int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        cnt += dfs(g, xx, yy, n, m);
    }
    return cnt;
}

void solve(int tt){
    int x, y;
    cin >> y >> x;
    vector <vector <char>> g(x, vector <char> (y));

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if (g[i][j] == '@'){
                g[i][j] = '.';
                cout << "Case " << tt << ": " << dfs(g, i, j, x, y) << endl;
                return;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++){
        solve(i);
    }
}