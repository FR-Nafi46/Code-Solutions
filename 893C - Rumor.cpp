/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-06   Time : 02:56:12
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
const int N = 1e5+7;

ll n, m, u, v;
vector <vector <ll>> g(N);
vector <ll> visited(N, false);

void dfs(ll x, vector<ll>&a, ll &mini){
    visited[x] = true;
    
    mini = min(mini, a[x - 1]);

    for (const auto &i : g[x]){
        if (!visited[i]){
            dfs(i, a, mini);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector <ll> a(n);
    for (auto &i : a) cin >> i;

    while (m--){
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll cnt = 0;
    for (ll i = 1; i <= n; i++){
        if (!visited[i]){
            ll mini = a[i - 1];
            dfs(i, a, mini);

            cnt += mini;
        }
    }
    cout << cnt << endl;
}