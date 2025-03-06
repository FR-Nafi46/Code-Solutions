/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-02   Time : 15:05:48
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

int n, m;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int dfs(vector <string> &g, int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '0')
        return 0;
        
    g[x][y] = '0';

    int c = 1;
    for (int i = 0; i < 8; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        c += dfs(g, xx, yy);
    }
    return c;
}

void solve(){
    vector <string> g;
    string line;

    while (getline(cin, line) && !line.empty()){
        g.push_back(line);
    }

    n = g.size();
    m = g[0].size();
    int cnt = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '1'){
                int val = dfs(g, i, j);
                cnt = max(cnt, val);
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;  
    cin.ignore();

    string st;
    getline(cin, st);

    while(t--){
        solve();
        if (t) cout << endl;
    }
}