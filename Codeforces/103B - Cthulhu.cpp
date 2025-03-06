/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-06   Time : 14:19:21
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

int n, m, u, v;
vector <vector<int>> g(101);
vector<bool> visited(101, false);

void dfs(int x){
    visited[x] = true;
    for (const auto &i : g[x]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    
    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (!visited[i])  
            ok = false;

    cout << ((n == m && ok) ? "FHTAGN!" : "NO");
}