/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-02-22   Time : 12:40:06
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

int n, k;
struct ninja{
    int pos;
    int wall;
    int danger;
};

bool bfs(vector <vector<char>> &s){
    queue <ninja> q;
    q.push({0,0,0});
    vector <vector<bool>> visited(2, vector <bool> (n, false));
    visited[0][0] = true;

    while (!q.empty()){
        auto cur = q.front();

        int loc = cur.pos;
        int side = cur.wall;
        int water = cur.danger;

        q.pop();

        if (loc >= n){
            return true;
        }

        if (loc < water){
            continue;
        }

        int up = loc + 1;
        if (up < n && !visited[side][up] && s[side][up] == '-'){
            visited[side][up] = true;
            q.push({up, side, water + 1});
        }

        int down = loc - 1;
        if (down >= 0 && !visited[side][down] && s[side][down] == '-'){
            visited[side][down] = true;
            q.push({down, side, water + 1});
        }

        int jump = loc + k;
        side = 1 - side;

        if (jump >= n)
            return true;
        
        if (jump < n && !visited[side][jump] && s[side][jump] == '-'){
            visited[side][jump] = true;
            q.push({jump, side, water + 1});
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    vector <vector <char>> s(2, vector <char> (n));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }

    cout << (bfs(s) ? "YES" : "NO") << endl;
}