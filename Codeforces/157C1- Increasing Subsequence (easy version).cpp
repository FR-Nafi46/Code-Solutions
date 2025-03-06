/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-02-21   Time : 18:13:57
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    string ans;

    int mx = 0;
    for (auto &i : a) cin >> i, mx = max(mx, i);

    int i = 0, j = n-1, last = -1;
    while (i <= j && last < mx){
        if (a[i] < last && a[j] < last)
            break;
        
        if (a[i] < a[j]){
            if (a[i] > last){
                last = a[i++];
                ans += 'L';
            }
            else{
                last = a[j--];
                ans += 'R';
            }
        }
        else{
            if (a[j] > last){
                last = a[j--];
                ans += 'R';
            }
            else{
                last = a[i++];
                ans += 'L';
            }
        }
    }
    cout << ans.size() << endl << ans;
}