/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-01   Time : 17:21:03
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
    
int m, n;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

void dfs(vector <vector<char>> &g, int i, int j){
    if (i < 0 || i >= n)
        return;
    if (j < 0 || j >= m)
        return;

    if (g[i][j] == '*')
        return;

    g[i][j] = '*';

    for (int k = 0; k < 8; k++){
        int xx = i + dx[k];
        int yy = j + dy[k];

        dfs(g, xx, yy);
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true){
        cin >> n >> m;

        if (m == 0 && n == 0)
            break;

        vector <vector <char>> g(n, vector <char> (m));
        int cnt = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> g[i][j];
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (g[i][j] == '@'){
                    cnt++;
                    dfs(g, i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}