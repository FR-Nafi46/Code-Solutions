/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-04   Time : 23:24:22
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

struct knight{
    char pos;
    int num;
    int cnt;
};

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(char c1, int n1, char c2, int n2){
    queue <knight> q;
    q.push({c1, n1, 0});
    vector <vector<bool>> visited (8, vector <bool> (8, false));
    visited[c1 - 'a'][n1 - 1] = true;

    while (!q.empty()){
        auto cur = q.front();
        q.pop();

        char p = cur.pos;
        int n = cur.num;
        int c = cur.cnt;

        if (p == c2 && n == n2){
            cout << "To get from " << c1 << n1 << " to " << c2 << n2 << " takes " << c << " knight moves." << endl;
            return;
        }

        for (int i = 0; i < 8; i++){
            char xx = p + dx[i];
            int yy = n + dy[i];

            if (xx >= 'a' && xx <= 'h' && yy >= 1 && yy <= 8 && !visited[xx - 'a'][yy - 1]){
                q.push({xx, yy, c + 1});
                visited[xx - 'a'][yy - 1] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    while (cin >> a >> b){
        char c1, c2;
        int n1, n2;

        c1 = a[0], c2 = b[0];
        n1 = a[1] - '0', n2 = b[1] - '0';

        bfs(c1, n1, c2, n2);
    }
}