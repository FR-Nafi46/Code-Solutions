/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 00:54:01
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

struct Food{
    int first;
    int second;
    int cnt;
    char prev;
};

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int bfs(vector <vector <char>>&g, int i, int j, int n, char me){
    queue <Food> q;
    q.push({i, j, 0, me});
    g[i][j] = '#';

    while (!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;
        int c = cur.cnt;
        char p = cur.prev;

        if (p == me + 1)
            return c;

        for (int k = 0; k < 4; k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && g[xx][yy] != '#'){
                if (g[xx][yy] == p+1){
                    q.push({xx, yy, c + 1, g[xx][yy]});
                    g[xx][yy] = '#';
                }
                else if (g[xx][yy] == '.'){
                    q.push({xx, yy, c + 1, p});
                    g[xx][yy] = '#';
                }
            }
        }
    }
    
    return -1;
}

void solve(int t){
    int n;
    cin >> n;
    vector <vector <char>> g(n, vector <char> (n)), x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    vector <pair<int, int>> p(26);
    int len = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (g[i][j] >= 'A' && g[i][j] <= 'Z'){
                p[g[i][j] - 'A'] = {i, j};
                len++;
            } 
        }
    }
    x = g;
    int sum = 0;
    for (int i = 0; i < len - 1; i++){
        g = x;
        int count = bfs(g, p[i].first, p[i].second, n, 'A' + i);
        x[p[i].first][p[i].second] = '.';
        sum += count;

        if (count == -1){
            cout << "Case " << t << ": " << "Impossible" << endl;
            return;
        }
    }

    cout << "Case " << t << ": " << sum << endl;
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