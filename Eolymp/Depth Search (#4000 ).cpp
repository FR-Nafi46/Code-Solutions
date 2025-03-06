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
vector <vector<int>> g(10001); 
vector <bool> visited (10001);

int dfs(int x, int cnt){
    visited[x] = true;
    int c = 1;
    for (auto &i : g[x]){
        if(!visited[i]){
            c += dfs(i, c);
        }
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> u;

            if (u){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    cout << dfs(s, 0) << endl;
}