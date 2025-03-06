/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 15:22:46
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
const int N = 10e5+7;

int n, m, u, v;

void dfs(int x, vector <vector<int>> &g, vector<bool>&visited){
    visited[x] = true;
    for (const auto &i : g[x]){
        if (!visited[i]){
            dfs(i, g, visited);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector <vector<int>> g(n + 1);
    vector <bool> visited(n + 1, false);

    for (int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, g, visited);

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}