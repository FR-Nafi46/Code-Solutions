/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 12:12:40
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

struct fire{
    int posX;
    int posY;
    int cnt; // time
};

struct player{
    int posX;
    int posY;
    int cnt;
};

int m, n;
char g[201][201];
int agun[201][201];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void fire_bfs(vector<pair<int, int>> fires){
    queue<fire> q;
    for(auto &st : fires){
        q.push({st.first, st.second, 1});
        agun[st.first][st.second] = 1;
    }

    while (!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.posX;
        int y = cur.posY;
        int time = cur.cnt;

        for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] != 'F' && agun[xx][yy] == 0 && g[xx][yy] != '#'){
                agun[xx][yy] = time + 1;
                q.push({xx, yy, time + 1});
            }
        }
    }
}

int player_bfs(pair<int, int> st){
    queue <player> q;
    q.push({st.first, st.second, 1});
    g[st.first][st.second] = '#';

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.posX;
        int y = cur.posY;
        int pos = cur.cnt;
        
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1){
            return pos;
        }

        for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] != '#'){
                if (agun[xx][yy] == 0 || agun[xx][yy] > pos + 1){
                    g[xx][yy] = '#';
                    q.push({xx, yy, pos + 1});
                }
            }
        }
    } 

    return -1;
}

void solve(int t){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            agun[i][j] = 0;
        }
    }

    vector<pair<int, int>> fires;
    pair <int, int> programmer;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
            if (g[i][j] == 'J'){
                programmer = {i, j};
            } 
            else if (g[i][j] == 'F'){
                fires.push_back({i, j});
            }
        }
    }

    fire_bfs(fires);

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }

    int ans = player_bfs(programmer);

    if (ans != -1)
        cout << "Case " << t << ": " << ans << endl;
    else
        cout << "Case " << t << ": " << "IMPOSSIBLE" << endl;
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