/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-06   Time : 14:56:13
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

int n, m, u, v, w, st;

vector <int> bfs(vector <vector<pair<int, int>>> &g, int s){
    vector <int> dis(n, INT_MAX);
    priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});

    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int pos = cur.second;
        int mx = cur.first;

        if (mx > dis[pos])
            continue;
        
        for (const auto &i : g[pos]){
            int val = i.first;
            int we = i.second;

            int new_max = max(mx, we);

            if (new_max < dis[val]){
                dis[val] = new_max;
                pq.push({new_max, val});
            }
        }
    }

    return dis;
}

void solve(int tt){
    cin >> n >> m;
    vector <vector<pair<int, int>>> g(n);
    vector <bool> visited(n);

    for (int i = 0 ; i < m; i++){
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cin >> st;

    auto dis = bfs(g, st);

    cout << "Case " << tt << ":" << endl; 
    for (int i = 0; i < n; i++){
        if (dis[i] == INT_MAX)
            cout << "Impossible" << endl; 
        else   
            cout << dis[i] << endl;
    }
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