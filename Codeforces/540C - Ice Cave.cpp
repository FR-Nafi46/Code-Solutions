/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-01   Time : 21:59:59
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

int m, n, st1, st2, end1, end2;
vector <vector <char>> g(1001, vector <char> (1001)), ck;
bool visited[1001][1001];
bool possible = false;
bool cross = false;
bool found = false;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int i, int j, vector <vector <char>> &ck){
    if (possible)
        return;
    if (i < 1|| i > n)
        return;
    if (j < 1 || j > m)
        return;

    if (i == end1 && j == end2){
        if (cross){
            found = true;
            possible = true;
        }

        int cnt = 0;
        for (int k = 0; k < 4; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && ck[xx][yy] == '.'){
                cnt++;
            }
        }
        
        if (found && cnt){
            cout << "YES" << endl; 
            return;
        }

        cout << (cnt > 1 ? "YES" : "NO"); 
        possible = true;
        return;
    }

    if (g[i][j] == 'X') 
        return;

    g[i][j] = 'X';
    for (int k = 0; k < 4; k++){
        int xx = i + dx[k];
        int yy = j + dy[k];

        dfs(xx, yy, ck);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    } 

    cin >> st1 >> st2;
    cin >> end1 >> end2;

    if (n == 1 && m == 1){
        cout << "NO";
        return 0;
    }

    if (g[end1][end2] == 'X'){
        cross = true;
    }

    g[st1][st2] = '.';

    ck = g;
    dfs(st1, st2, ck);

    if (!possible)
        cout << "NO" <<endl;
}