#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
#define lcm(a,b) ((a*b)/__gcd(a,b))
const double PI = 2 * acos(0.0);
const int MOD = 1000000007;

void solve(){
    int n, m;
    cin >> n >> m;
    
    ll a[n][m];
    vector <pair <ll, int>> add;
    for (int i = 0; i < n; i++){
        ll sum = 0;
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            sum += a[i][j];
        }
        add.push_back({sum, i});
    }
    sort(add.rbegin(), add.rend());

    int cc;
    ll ans = 0;
    ll tt = 0;

    for (int i = 0; i < n; i++){
        cc = add[i].second;
        ll sum = tt;
        for (int j = 0; j < m; j++){
            sum = (sum + a[cc][j]);
            ans += sum;
        }
        tt = sum;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }    
}