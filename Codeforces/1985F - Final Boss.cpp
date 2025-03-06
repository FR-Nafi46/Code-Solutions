/*
 * @author Md. Fahmidur Rahman Nafi
 * @create date 19-02-2025    23:23:13
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
#define lcm(a,b) ((a*b)/__gcd(a,b))
const double PI = 2 * acos(0.0);
const int MOD = 1000000007;

bool finish(vector <ll> &a, vector <ll> &c, ll mid, ll h){
    ull dmg = 0;
    for (int i = 0; i < a.size(); i++){
        ll atk = (mid + c[i] - 1) / c[i];
        dmg += 1LL * atk * a[i];
    }
    return dmg >= h;   
}

void solve(){
    ll h, n;
    cin >> h >> n;
    vector <ll> a(n), c(n);
    for (auto &i : a) cin >> i;
    for (auto &i : c) cin >> i;

    ll low = 0, high = 1e12;

    while (high >= low){
        ll mid = low + (high - low) / 2;

        if (finish(a, c, mid, h))
            high = mid - 1;
        else
            low = mid + 1;
    }  
    cout << low << endl;
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