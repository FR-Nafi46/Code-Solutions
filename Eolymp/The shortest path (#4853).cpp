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

int n, m, u, v, s, e;

vector <int> bfs(int x, int finish, vector <vector<int>> &g, vector<bool> &visited){
    queue <int> q;
    vector <int> par(n + 1, -1);
    visited[x] = true;

    q.push(x);
    visited[x] = true;

    while (!q.empty()){
        int val = q.front();
        q.pop();

        if (val == finish){
            vector <int> path;
            for (int i = finish; i != -1; i = par[i]){
                path.push_back(i);
            }
            reverse(path.begin(), path.end());
            return path;
        }
        
        for (const auto &i : g[val]){
            if (!visited[i]){
                visited[i] = true;
                par[i] = val;
                q.push(i);
            }
        }
    }
    return {};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> s >> e;

    vector <vector<int>> g(n + 1); 
    vector <bool> visited (n + 1, false);

    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto ans = bfs(s, e, g, visited);
    
    if (ans.empty() || ans.back() != e){
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() - 1 << endl;
    for (auto i : ans)
        cout << i << ' ';
}