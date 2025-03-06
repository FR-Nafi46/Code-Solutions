/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 15:47:54
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

int n, m, u, v, s;
vector <vector<int>> g(1001); 
vector <bool> visited (1001);
vector <int> ans(1001, -1);

void bfs(int x){
    queue <pair<int, int>> q;
    q.push({x, 0});
    visited[x] = true;

    while (!q.empty()){
        auto cur = q.front();
        q.pop();

        int val = cur.first;
        int cnt = cur.second;
        ans[val] = cnt;

        for (const auto &i : g[val]){
            if (!visited[i]){
                visited[i] = true;
                q.push({i, cnt + 1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    int mx = 0;

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> u;

            if (u){
                g[i].push_back(j);
                mx = max({mx, i, j});
            }
        }
    }
    
    bfs(s);

    for (int i = 1; i <= mx; i++){
        cout << ans[i] << ' ';
    }
}