/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-03   Time : 04:46:04
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

vector <ll> visited(10000, false);
int gen(int n) {
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int bfs(int a, int b){
    queue <pair<int, int>> q;
    q.push({a, 0});
    visited[a] = true;

    while (!q.empty()){
        auto cur = q.front();
        int x = cur.first;
        int cnt = cur.second;
        q.pop();

        if (x == b)
            return cnt;
        
        if (x * 3 <= 9999 && !visited[x * 3]){
            q.push({x * 3, cnt + 1});
            visited[x * 3] = true;
        }

        if (x - 2 >= 0 && !visited[x - 2]){
            q.push({x - 2, cnt + 1});
            visited[x - 2] = true;
        }

        int val = gen(x);
        if (x + val <= 9999 && !visited[x + val]){
            q.push({x + val, cnt + 1});
            visited[x + val] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << bfs(a, b) << endl;
}