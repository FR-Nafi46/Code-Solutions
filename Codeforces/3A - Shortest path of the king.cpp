/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-02-22   Time : 13:13:46
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

struct king{
    char let;
    int num;
    vector <string> pos;
};

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1},{-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
vector<string> dir = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

void bfs(king k, king t){
    queue <king> q;
    q.push(k);
    vector <vector <bool>> visited(8, vector <bool> (8, false));
    visited[k.let - 'a'][k.num - 1] = true;  

    while (!q.empty()){
        auto cur = q.front();
        char x = cur.let;
        int y = cur.num;
        vector<string> v = cur.pos;
        
        q.pop();

        if (x == t.let && y == t.num){
            cout << v.size() << endl;
            for (auto &i : v) cout << i << endl;
            return;
        }
        
        for (int i = 0; i < 8; i++){
            char xx = x + moves[i].first;
            int yy = y + moves[i].second;

            if (xx >= 'a' && xx <= 'h' && yy >= 1 && yy <= 8 && !visited[xx - 'a'][yy - 1]){
                vector <string> path = v;
                path.push_back(dir[i]);
                q.push({xx, yy, path});
                visited[xx - 'a'][yy - 1] = true;
            }
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    king k, t;
    cin >> k.let >> k.num >> t.let >> t.num;

    bfs(k, t);
}