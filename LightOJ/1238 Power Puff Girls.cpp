/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 12:49:38
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

struct road{
    int x, y, cnt;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(vector <vector <char>>g, int x, int y, int m, int n){
    queue <road> q;
    q.push({x, y, 0});
    vector <vector<bool>> visited(n, vector <bool> (m, false));
    visited[x][y] = true;

    while (!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int cnt = cur.cnt;

        if (g[x][y] == 'h'){
            return cnt;
        }

        for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] != '#' && g[xx][yy] != 'm' && !visited[xx][yy]){
                q.push({xx, yy, cnt + 1});
                visited[xx][yy] = true;
            }
        }
    }
}

void solve(int t){
    int m, n;
    cin >> n >> m;
    vector <vector <char>> g(n, vector <char> (m)), x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    x = g; 
    vector <int> time;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == 'a' || g[i][j] == 'b' || g[i][j] == 'c'){
                time.push_back(bfs(g, i, j, m, n));
            }
        }
    }

    cout << "Case " << t << ": " << *max_element(time.begin(), time.end()) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        solve(i);
    }
}