/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-06   Time : 02:42:49
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

int m, n, u, v;
vector <vector <int>> g(101);
vector <bool> visited(101, false);
vector <pair<int, int>> ans;

void dfs(int x){
    visited[x] = true;
    for (const auto &i : g[x]){
        if (!visited[i]){
            ans.push_back({x, i});
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    while (m--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for (auto &i : ans)
        cout << i.first << ' ' << i.second << endl;
}